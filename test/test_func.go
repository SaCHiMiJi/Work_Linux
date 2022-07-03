package main

import (
	"fmt"
)
func main() {
	fmt.Println(check_base(10,8))
}

func check_base(num int,b uint8) string{
	var out string
	arr:= [6]string{"A", "B", "C", "D", "E", "F"}
	num -= int(b) + 1
	fmt.Println("num :",int(num))
	out = arr[int(num)]
	return out
}