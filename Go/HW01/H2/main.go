package main

import (
	"fmt"
	"log"
)

func main() {

	var x string
	_, err := fmt.Scan(&x)

	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(additiveInverse(x))

}
