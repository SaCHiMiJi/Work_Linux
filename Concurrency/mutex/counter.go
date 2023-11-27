package main

import(
	"fmt"
	"wg"
	"sync"
)

func counter(n int, wg *sync.WaitGroup)  {
	for i := 0; i < 10000; i++ {
		sum = sum + 1
	}
	fmt.Println("From ", n, ":", sum)
	wg.Done()
}

func main()  {
	for i := 0; i < 5; i++ {
		wg.Add(1)
		go counter(i, &wg)
	}
	wg.Wa
}