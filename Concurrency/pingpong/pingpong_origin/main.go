package main

import (
	"fmt"
	"sync"
)

func ping(Ch chan string, wg *sync.WaitGroup) {
	defer wg.Done()
	pingCount := 0
	for pingCount < 3 {
		msg := <-Ch
		if msg == "ping" {
			fmt.Println(msg)
			Ch <- "pong"
			pingCount++
		}

	}
}

func pong(Ch chan string, wg *sync.WaitGroup) {
	defer wg.Done()
	pongCount := 0
	for pongCount < 3 {
		msg := <-Ch
		if msg == "pong" {
			fmt.Println(msg)
			Ch <- "ping"
			pongCount++
		}
	}
}

func main() {
	Ch := make(chan string, 1)
	var wg sync.WaitGroup

	wg.Add(1)
	go ping(Ch, &wg)
	go pong(Ch, &wg)

	Ch <- "ping"

	wg.Wait()
	close(Ch)
}
