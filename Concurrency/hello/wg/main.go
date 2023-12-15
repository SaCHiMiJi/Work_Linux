package main

import (
	"fmt"
	"sync"
	"time"
)

func sayHello(wg *sync.WaitGroup, turn *int) {
	defer wg.Done()
	for i := 0; i < 10; i++ {
		if *turn == 0 {
			fmt.Println("Hello")
			*turn = 1
		}
		time.Sleep(time.Millisecond*500)
	}
}

func sayWorld(wg *sync.WaitGroup, turn *int) {
	defer wg.Done()
	for i := 0; i < 11; i++ {
		if *turn == 1 {
			fmt.Println("world")
			*turn = 0
		}
		time.Sleep(time.Millisecond*500)
	}
}

func main() {
	var wg sync.WaitGroup
	turn := 0
	wg.Add(2)

	go sayHello(&wg, &turn)
	go sayWorld(&wg, &turn)

	wg.Wait()
}
