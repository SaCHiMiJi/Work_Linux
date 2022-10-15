package main

import (
	"fmt"
	"log"
)

func main() {

	var n uint64
	_, err := fmt.Scan(&n)

	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(powerOfTwo(n))

}
