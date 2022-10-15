// ชัยนันท์ เรืองกิจวณิชกุล
// 640510649
// HW01_1
// 204203 Sec 001

package main

import (
	// "fmt"
	"math"
	// "strconv"
	"strings"
)

func twosComplToInt(x string) int64 {

	var result int64 = 0
	str := strings.Split(x, "")
	
	l := 0
	for k := len(str) - 1; k >= 0; k-- {

		if k == len(str) - 1 && str[l] == "1"{
			// fmt.Println("in")
			result += int64(math.Pow(2, float64(k)) * -1)
		} else if str[l] == "1" {
			result += int64(math.Pow(2, float64(k)))
		}
		// fmt.Println(result)
		l++
	}
	return result
}
