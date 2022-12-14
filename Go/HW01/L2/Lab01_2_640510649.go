// ชัยนันท์ เรืองกิจวณิชกุล
// 640510649
// Lab01_2
// 204203 Sec 001
package main

import (
	// "fmt"
	"math"
	"strconv"
	"strings"
)

const MAX_INT = 64
const DEC_PLACE = 6

func floatToBaseB(x float64, b uint8) string {
	sign := ""

	if x < 0 { // turn negative numbers to positive
		x = -x
		sign = "-"
	}
	// split at the decimal point
	front := int64(x)
	back := x - float64(front)

	frontStr := posIntToBaseB(front, b)
	backStr := fractionToBaseB(back, b)
	// putting every part together
	converted := sign + frontStr + "." + backStr

	return converted

}

func fractionToBaseB(x float64, b uint8) string {
	// only need to implement this function
	i := 0
	var result string
	for i < 6 {
		x *= float64(b)
		num := int(math.Floor(x))
		if b >= 10 && num >= 10 {
			// println("===in condition===\nnum :",num)
			result += check_base(num)
		} else { 
			result += strconv.Itoa(num)
		}
		// fmt.Println("floor :",math.Floor(x))
		// fmt.Println(result)
		x -= math.Floor(x)
		i++
	}
	return string(result)
}

func posIntToBaseB(x int64, b uint8) string {
	// this function is working correctly
	if x == 0 {
		return "0"
	}

	result := []byte(strings.Repeat("x", MAX_INT))
	k := MAX_INT - 1
	var currDigit byte

	for x > 0 {
		// calculate and convert back to char
		currDigit = byte((x % int64(b)) + int64('0'))
		if currDigit > '9' {
			currDigit = 'A' + currDigit - '9' - 1
		}
		result[k] = currDigit
		x = x / int64(b)
		k--
	}
	// convert from byte array to string
	return string(result[k+1:])
}

func check_base(num int) string {
	var out string
	arr := [6]string{"A", "B", "C", "D", "E", "F"}
	num -= 10
	// fmt.Println("num :",int(num))
	out = arr[int(num)]
	return out
}
