package main

import (
	"fmt"
	"math/rand"
	"sync"
)

func play(player string, Ch chan string, Ch_main chan string, turn chan string, wg *sync.WaitGroup) {
	defer wg.Done()
	count := 0
	tt := 0
	for count <= 10 {
		min := 10
		max := 30
		tt = rand.Intn(max-min+1) + min

		select {
		case msg := <-turn:
			if msg == player {
				if (tt > 20 && count > 2) || count >= 9 {
					count = 10
					Ch <- "hit"
					Ch_main <- player
				} else if player == "ping" && <-Ch == "ping" {
					fmt.Println("ping")
					Ch <- "pong"
					count++
				} else if player == "pong" && <-Ch == "pong" {
					fmt.Println("pong")
					Ch <- "ping"
					count++
				}
				turn <- "pong" // Switch turn
			} else {
				turn <- msg // Pass the turn to the other player
			}
		case <-Ch_main:
			return
		}
	}
}

func main() {
	Ch := make(chan string, 1)
	Ch_main := make(chan string, 1)
	turn := make(chan string, 1)
	turn <- "ping" // Starting turn

	var wg sync.WaitGroup
	wg.Add(2)
	go play("ping", Ch, Ch_main, turn, &wg)
	go play("pong", Ch, Ch_main, turn, &wg)

	Ch <- "ping"

	go func() {
		msg := <-Ch_main
		fmt.Println(msg, "wins.")
		close(Ch)
		close(Ch_main)
	}()

	wg.Wait()
}
