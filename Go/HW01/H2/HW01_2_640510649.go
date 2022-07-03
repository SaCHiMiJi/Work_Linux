// ชัยนันท์ เรืองกิจวณิชกุล
// 640510649
// HW01_2
// 204203 Sec 001

package main

import (

	// "fmt"
	"math"
	"strconv"
	"strings"
)

func additiveInverse(x string) (string, int64) {
	str := strings.Split(x, "")
	one := []string{"1"}
	if check_zero(str) {
		// fmt.Println("in")
		return string(strings.Join(str, "")), 0
		// str = []string{"0"}
	}

	for i := 0; i < len(str); i++ {
		if str[i] == "0" {
			str[i] = "1"
		} else {
			str[i] = "0"
		}
	}
	// fmt.Println("one'com :", strings.Join(str, ""))

	// fmt.Println("range : ", len(str)-1)

	for j := len(str) - 1; j >= 0; j-- {
		num, _ := strconv.Atoi(str[j])

		if int(num) == 1 && j == len(str)-1 {
			// fmt.Println("first in")
			if len(str)-1 == 0 {
				str[j] = "0"
				str = append(one, str...)
			} else if str[j-1] == "1" {
				str[j-1] = "2"
				str[j] = "0"
			} else if str[j-1] == "0" {
				str[j-1] = "1"
				str[j] = "0"
			}
		} else if int(num) == 2 {
			str[j] = "0"
			if str[j-1] == "1" {
				str[j-1] = "2"
			} else {
				str[j-1] = "1"
			}
		} else if j == len(str)-1 && str[j] == "0" {
			str[j] = "1"
		}

	}
	// fmt.Println("two'com :", strings.Join(str, ""))
	out := string(strings.Join(str, ""))

	return out, twosComplToInt(out)
}

func check_zero(str []string) bool {
	for i := 0; i < len(str); i++ {
		if str[i] == "1" {
			return false
		}
	}
	return true
}

func twosComplToInt(x string) int64 {

	var result int64 = 0
	str := strings.Split(x, "")

	l := 0
	for k := len(str) - 1; k >= 0; k-- {

		if k == len(str)-1 && str[l] == "1" {
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

// 1110
 