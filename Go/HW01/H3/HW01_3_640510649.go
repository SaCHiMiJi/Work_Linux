// ชัยนันท์ เรืองกิจวณิชกุล
// 640510649
// HW01_3
// 204203 Sec 001
package main

import (
	// "fmt"
	"math"
	"strconv"
	"strings"
)

func addNSubtract(n1, n2 string, bitLen uint8) (int64, int64) {
	num := len(n1)
	if len(n2) > len(n1) {
		num = len(n2)
	}
	if len(n1) != len(n2) {
		n1 = add_valve(n1, uint8(num), true)
		n2 = add_valve(n2, uint8(num), false)
	}

	return Plus_binary(n1, n2, bitLen), Plus_binary(n1, additiveInverse(n2), bitLen)
}

// need to plus befor and cut after
func Plus_binary(n1, n2 string, bitLen uint8) int64 {
	println("n1 :", n1)
	println("n2 :", n2)
	len1 := len(n1)
	len2 := len(n2)


	result := []byte(strings.Repeat("x", int(bitLen)))

	i, j, k := len1-1, len2-1, int(bitLen)-1

	println("i:", i, "j", j, "k", k)
	// loop from right most position
	for ; i >= 0; i, j, k = i-1, j-1, k-1 {
		// current digit
		currDigit := 0

		currDigit += int(n1[i]) - int('0')

		currDigit += int(n2[j]) - int('0')

		println("k :", k)
		if k >= 0 {
			if string(result[k]) == "x" {
				result[k] = byte(int(currDigit)%2 + int('0'))
			} else {
				currDigit += 1
				result[k] = byte(int(currDigit)%2 + int('0'))

			}
			println("currDigit :", currDigit)
			println("plus end :", string(result[k]))
			if k > 0 {
				if currDigit > 1 {
					result[k-1] = byte(currDigit/2 + int('0'))
					println("set next digit :", string(result[k-1]))
					
				}
				if string(result[k-1]) == "x" {
					println("result k-1:", string(result[k-1]))
					k++
				}
			}
		} else {
			k++
		}
	}
	println("result all :", string(result[0:]))
	println("result out:", string(result[k+1:]))
	println("num out : ", k, "\n=======================\n")

	return twosComplToInt(string(result[k+1:]))
}

//1111
//1000
//12

//output
//-9 7

//1100
//0011
//5

//output
//-1 -7

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

func additiveInverse(x string) string {
	str := strings.Split(x, "")
	one := []string{"1"}
	if check_zero(str) {
		// fmt.Println("in")
		return string(strings.Join(str, ""))
		// str = []string{"0"}
	}

	for i := 0; i < len(str); i++ {
		if str[i] == "0" {
			str[i] = "1"
		} else {
			str[i] = "0"
		}
	}

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

	return out
}

func check_zero(str []string) bool {
	for i := 0; i < len(str); i++ {
		if str[i] == "1" {
			return false
		}
	}
	return true
}

func add_valve(str string, bitLen uint8, x bool) string {
	arr_str := strings.Split(str, "")
	var num string
	if arr_str[0] == "0" || x {
		num = "0"
	} else {
		num = "1"
	}
	for i := 0; i < int(bitLen)-len(arr_str); i++ {
		str = num + str
	}
	return str
}
