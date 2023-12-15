package main

import (
	"fmt"
	"sync"
)

func Sayworld(Ch chan int, wg *sync.WaitGroup) {
	defer wg.Done()
	count := 0
	for count < 10 {
		<-Ch
		fmt.Println("world")
		Ch <- 1
		count++
	}
}

func Sayhello(Ch chan int, wg *sync.WaitGroup) {
	defer wg.Done()
	count := 0
	for count < 10 {
		<-Ch
		fmt.Println("hello")
		Ch <- 0
		count++
	
	}
}

func main() {
	Ch := make(chan int, 1)
	var wg sync.WaitGroup

	wg.Add(1)
	go Sayhello(Ch, &wg)
	go Sayworld(Ch, &wg)

	Ch <- 1

	wg.Wait()
	close(Ch)
}
