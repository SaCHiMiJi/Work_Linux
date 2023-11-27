package main

import (
	"fmt"
	"sync"
	"runtime"
	"time"
	// "math/rand"
)

var sum = 0
var mu sync.Mutex


func getGOMAXPROCS() int {
	return runtime.GOMAXPROCS(0)
}

func counter(n int, wg *sync.WaitGroup) {
	time.Now().UnixNano()
	// min :=10
	// max :=30
	// tt := rand.Intn(max-min+1)+min
	for i := 0; i < 10000; i++ {
		mu.Lock()
		sum = sum + 1
		mu.Unlock()
		// time.Sleep(time.Duration(tt*1000))
	}
	fmt.Println("From ", n, ":", sum)
	wg.Done()
}

func main() {
	numCPU := runtime.NumCPU()
	runtime.GOMAXPROCS(numCPU)
	fmt.Printf("GOMAXPROCS is %d\n",getGOMAXPROCS())
	var wg sync.WaitGroup // Initialize WaitGroup
	for i := 0; i < 5; i++ {
		wg.Add(1)
		go counter(i, &wg)
	}
	wg.Wait()
	fmt.Println("Final Sum:", sum)
}
