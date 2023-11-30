package main

import (
	"fmt"
	"sync"
	"runtime"
	// "time"
	// "math/rand"
)

var sum = 0
var mu sync.Mutex
var csum chan int


func getGOMAXPROCS() int {
	return runtime.GOMAXPROCS(0)
}

func counter(n int, wg *sync.WaitGroup) {
	sum_in_counter := 0
	for i := 0; i < 10000; i++ {
		// mu.Lock()
		sum_in_counter = sum_in_counter +1
		// mu.Unlock()
		// time.Sleep(time.Duration(tt*1000))
		
	}
	csum <- sum_in_counter
	fmt.Println("From ", n, ":", sum_in_counter)
	wg.Done()
}

func main() {
	numCPU := runtime.NumCPU()
	runtime.GOMAXPROCS(numCPU)
	fmt.Printf("GOMAXPROCS is %d\n",getGOMAXPROCS())
	var wg sync.WaitGroup // Initialize WaitGroup
	csum = make(chan int)
	for i := 0; i < 5; i++ {
		wg.Add(1)
		go counter(i, &wg)
	}
	go func() {
		wg.Wait()
		close(csum)
	}()
	totalSum := 0
	for partialSum := range csum {
		totalSum += partialSum // Aggregate the partial sums received from the channel
	}

	fmt.Println("Final Sum:", totalSum)
}