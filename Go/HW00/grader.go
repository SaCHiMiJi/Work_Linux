package main

import (
	"fmt"
)

func main() {

	var num int8
	fmt.Scan(&num)
	var result = factorial(num)
	fmt.Println("num =", num, "result =", result)

}
