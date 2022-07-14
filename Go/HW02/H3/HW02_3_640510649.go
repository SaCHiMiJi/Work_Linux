// ชื่อ นามสกุล - ชื่อเล่น
// 6XXXXXXXX
// Lab02_1
// 204203 Sec 00B

package main

import (
	"fmt"
	"math"
	"strings"
)

const fracLen = 7
const expLen = 8

const BASE uint8 = 2
const DEBUG = true

// from Lab01_2
const MAX_INT = 64
const DEC_PLACE = 128

func float16bitNormed(n float32) string {
	// expLen = 8, fracLen = 7

	var bias = int(pow(2, expLen-1) - 1) // bias = 127

	if DEBUG {
		println("Bias", bias)
	}
	var minNorm float64 = pow(2, -126)      // dummy value
	var maxNorm float64 = 255 * pow(2, 120) // dummy value

	sign := "0"
	if n < 0 {
		n = -n
		sign = "1"
	}

	if (float64(n) > maxNorm) || (float64(n) < minNorm) {
		if DEBUG {
			println(n, "overflow")
		}
		return ""
	} else {
		x := fmt.Sprintf("%b\n", math.Float32bits(n))
		E := math.Log2(float64(n))

		Fexp := E + float64(bias)

		exp := floatToBaseB(Fexp, 2)
		if DEBUG {
			println("n :", fmt.Sprintf("%v", n))
			println("in condition")
			println("n :", n)
			fmt.Println("x:", x)
			fmt.Println("binary is ", x[0:8], x[8:15])
			println("exp :",exp)
		}
		
		
		if n >= 1 {
			return sign + x[0:8] + x[8:15]
		} else {
			if check_zero(x[0:8]) {
				new := x[1:8] + x[0:1]
				return sign + new + x[8:15]
			} else {
				x = "0" + x
				return sign + x[0:8] + x[8:15]
			}
		}
	}

	// return sign + ""
}
func check_zero(n string) bool {
	count := 0
	arr_n := strings.Split(n, "")
	for i := 0; i < len(n); i++ {
		if arr_n[i] == "0" {
			count++
		}
	}
	if arr_n[0] == "1" && count == 7 {
		return true
	} else {
		return false
	}

}

func pow(x, y int) float64 {
	return math.Pow(float64(x), float64(y))
}

//------------------------------------ Lab01_2

func floatToBaseB(x float64, b uint8) string {
	sign := ""

	if x < 0 {
		x = -x
		sign = "-"
	}
	// split at the decimal point
	front := int64(x)
	back := x - float64(front)

	frontStr := posIntToBaseB(front, b)
	backStr := fractionToBaseB(back, b)
	converted := sign + frontStr + "." + backStr

	return converted

}

func fractionToBaseB(x float64, b uint8) string {

	result := []byte(strings.Repeat("x", DEC_PLACE))
	var currDigit byte

	for i := 0; i < DEC_PLACE; i++ {
		x = x * float64(b)
		front := int64(x)
		currDigit = byte((front) + int64('0'))
		if currDigit > '9' {
			currDigit = 'A' + currDigit - '9' - 1
		}
		x = x - float64(front)
		result[i] = currDigit

	}

	return string(result[:])
}

func posIntToBaseB(x int64, b uint8) string {

	if x == 0 {
		return "0"
	}

	result := []byte(strings.Repeat("x", MAX_INT))
	k := MAX_INT - 1
	var currDigit byte

	for x > 0 {
		currDigit = byte((x % int64(b)) + int64('0'))
		if currDigit > '9' {
			currDigit = 'A' + currDigit - '9' - 1
		}
		result[k] = currDigit
		x = x / int64(b)
		k--
	}

	return string(result[k+1:])
}
