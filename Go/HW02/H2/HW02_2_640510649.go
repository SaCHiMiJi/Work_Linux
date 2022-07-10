// ชื่อ ชัยนันท์ เรืองกจวณิชกุล
// 640510649
// HW02_2
// 204203 Sec 001

package main

import (
	"fmt"
	"math"
	"strings"
)

func roundToEven(x string, bPlace uint8) string {
	result := ""
	
	if strings.Index(x,".") >= 0 {

		str_int := strings.Split(x, ".")[0]
		str_float := strings.Split(x, ".")[1]

		if bPlace == 0 {
			result = strings.Split(x, ".")[0]
		} else {

			arr_str_float := strings.Split(str_float, "")
			len_str := len(str_float)
			// println("arr_str_float:", strings.Join(arr_str_float, ", "))
			// println("len_str:", len_str)

			if len_str < int(bPlace) {

				str_float = add_zero(str_float, int(bPlace)-len_str)
				result = str_int + "." + str_float
			} else {

				str := ""
				for i := 0; i < int(bPlace); i++ {
					str += arr_str_float[i]
				}
				str_float = str
				num := math.Pow(10, -1*float64(bPlace))
				str_num := fmt.Sprintf("%v", num)

				// println("str_num:", str_num)
				result = addition(str_int+"."+str_float, str_num, 2)

				str_check := strings.Split(strings.Split(result, ".")[1], "")
				// println("str_check:", strings.Join(str_check, ", "))

				if check_binary(str_check, int(bPlace)) == false {
					result = str_int + "." + str_float
				}
				// println("plus_num:", result)

			}
		}
	} else {
		if  bPlace != 0{
			str_float := add_zero("", int(bPlace))
			result = x + "." + str_float
		} else {
			result = x
		}
		
	}
	
	return result
}

func check_binary(str []string, num int) bool {

	remain := 0
	b_fraction := 0
	l := len(str)
	for i := len(str) - 1; i >= 0; i-- { // bug this loop
		if str[i] != "0" {
			// println(str[i])
			// println("l:",l)
			if b_fraction == 0 {
				b_fraction = int(math.Pow(2, float64(l)))
				remain += 1
			} else {
				// println("pow:",int(math.Pow(2, float64(l))))
				// println("mod:",b_fraction / int(math.Pow(2, float64(l))))
				remain += int(b_fraction / int(math.Pow(2, float64(l))))
			}
			// println("remain:", remain)
		}
		l--
	}
	// println("b_fraction:", b_fraction)
	// println("remain:", remain)
	if b_fraction == 0 || remain == 0 {
		return true
	}

	check := b_fraction % remain
	// println("b_fraction%remain:", check)

	if check == 0 {
		// println(true)
		return true
	} else {
		// println(false)
		return false
	}

}

func add_zero(str string, num int) string {

	for i := 0; i < num; i++ {
		str += "0"
	}
	return str
}

func addition(n1, n2 string, base int) string {
	// fmt.Println("r1:", n1, "\nr2:", n2)
	result := []byte(strings.Repeat("x", 141))
	len1 := len(n1)
	len2 := len(n2)
	carry := 0

	i, j, k := len1-1, len2-1, 140

	for ; i >= 0 || j >= 0; i, j, k = i-1, j-1, k-1 {
		temp := carry
		carry = 0
		if string(n1[i]) != "." {
			if i >= 0 {
				temp += int(n1[i]) - int('0')
			}
			if j >= 0 {
				temp += int(n2[j]) - int('0')
			}
			if k >= 0 {
				result[k] = byte((temp % base) + int('0'))
			}

			carry = temp / base
			// fmt.Println("carry:", carry)
		} else {
			// fmt.Println("result k :", string(result[k]))
			// fmt.Println("result k-1 :", string(result[k-1]))
			result[k] = byte('.')
			carry = temp

		}
		if k < 0 {
			k++
		}
		// fmt.Println("result:", string(result[k]))

	}

	if carry > 0 && k > 0 {
		result[k] = '1'
	} else {
		k++
	}
	// fmt.Println("k out:", k)
	// fmt.Println("result all:", string(result[0:]))
	return string(result[k:])

}
