package main

import (
	"fmt"
	"time"
)

func main()  {
	for i := 0; i < 3; i++ {
		go count(i)
		time.Sleep(2)
	}
	time.Sleep(1000*60)
	fmt.Println("end")
}

func count(x int)  {
	for i := 0; i < 5; i++ {
		fmt.Println("gorouting no.",x ,": ", i)
		time.Sleep(1)
	}
}