package main

import (
	"fmt"
	"log"
)

func main() {

	var x float64
	var b uint8
	_, err := fmt.Scan(&x, &b)

	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(floatToBaseB(x, b))

}
