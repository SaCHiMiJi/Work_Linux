package main

import (
	"fmt"
	"log"
)

func main() {

	var n1, n2 string
	var bitLen uint8

	_, err := fmt.Scan(&n1, &n2, &bitLen)

	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(addNSubtract(n1, n2, bitLen))

}
