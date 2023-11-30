package main

import (
	"fmt"
	"math/rand"
	"sync"
)

func player(Ch chan string, M_ch chan string, wg *sync.WaitGroup, name string) {
	defer wg.Done()
	count := 0 // for cut when pingpong 10 time
	min := 10
	max := 30
	tt := rand.Intn(max-min+1) + min
	for {
		msg := <-Ch
		if msg == "hit" {
			break
		} else if (tt >= 15 && count >= 4) || (count >= 10) {
			fmt.Println("Game Over")
			M_ch <- name
			Ch <- "hit"
			break
		} else if msg == "ping" {
			fmt.Println(name + ": " + msg)
			Ch <- "pong"
		} else if msg == "pong" {
			fmt.Println(name + ": " + msg)
			Ch <- "ping"
		} else {
			fmt.Println(name+": Invalid message:", msg)
		}
		count++
	}
}

func main() {
	Ch := make(chan string, 1)
	M_ch := make(chan string, 1)
	var wg sync.WaitGroup

	wg.Add(2)
	go player(Ch, M_ch, &wg, "Alice")
	go player(Ch, M_ch, &wg, "Bob")

	Ch <- "ping"
	win_p := <-M_ch
	fmt.Println(win_p, " wins.")
	wg.Wait()
	close(Ch)
}
