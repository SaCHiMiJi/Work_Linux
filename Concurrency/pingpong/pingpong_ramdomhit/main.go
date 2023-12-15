package main

import (
	"fmt"
	"math/rand"
	"sync"
)

func player(Ch chan string, M_ch chan string, wg *sync.WaitGroup, name string) {
	defer wg.Done()
	tt := rand.Intn(5)
	for {
		msg := <-Ch
		if msg == "hit" {
			break
		} else if tt >= 2 {
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
