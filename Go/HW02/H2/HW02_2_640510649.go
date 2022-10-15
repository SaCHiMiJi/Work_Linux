// ชื่อ ชัยนันท์ เรืองกจวณิชกุล
// 640510649
// HW02_2
// 204203 Sec 001

package main

import (
	"math"
	"strings"
)

func roundToEven(x string, bPlace uint8) string {
	result := ""
	if strings.Index(x, ".") > 0 {
		str_int := strings.Split(x, ".")[0]
		str_float := strings.Split(x, ".")[1]
		len_str_float := len(str_float)

		if int(bPlace) == len_str_float {
			result = x
		} else if int(bPlace) > len_str_float {
			result = add_zero(x, int(bPlace)-len_str_float)
		} else {

			arr_str_float := strings.Split(str_float, "")
			// println("arr_str_float:", strings.Join(arr_str_float, ", "))
			// println("len_str:", len_str)

			if bPlace == 0 {
				arr_str_int := strings.Split(str_int, "")
				// println("arr_str_int[",len(str_int)-1,"]:", strings.Join(arr_str_int, ", "))
				// if check_binary(arr_str_float, bPlace, arr_str_int[len(str_int)-1]) {

				// 	result = addition(str_int, "1", 2)
				// } else
				if arr_str_float[0] == "1" {
					if arr_str_int[len(str_int)-1] == "0" {
						
						if check_binary(arr_str_float, bPlace, arr_str_int[len(str_int)-1]) {
							result = addition(str_int, "1", 2)
						} else {
							result = str_int
						}
					} else {
						result = addition(str_int, "1", 2)
					}
				} else {
					result = str_int
				}

			} else {
				str_float = ""
				for i := 0; i < int(bPlace); i++ {
					str_float += arr_str_float[i]
				}
				if arr_str_float[int(bPlace)] == "0" {
					result = str_int + "." + str_float
				} else {
					// println(check_binary(arr_str_float, bPlace, ""))
					if check_binary(arr_str_float, bPlace, "") {
						str_plus := new_str_plus(int(bPlace))
						result = str_int + "." + str_float
						// println("result:", result)
						// println("str_plus:", str_plus)
						result = addition(result, str_plus, 2)
					} else if arr_str_float[int(bPlace)-1] == "0" {
						result = str_int + "." + str_float
					}  else {
						result = str_int + "." + str_float
					}
				}
			}
		}
	} else {
		str := ""
		if bPlace != 0 {
			for i := 0; i < int(bPlace); i++ {
				str += "0"
			}
			result = x + "." + str
		} else {
			result = x
		}

	}

	return result
}

func new_str_plus(num int) string {
	result := "0."
	for i := 0; i < num; i++ {

		if i == num-1 {
			result += "1"
		} else {
			result += "0"
		}
	}
	return result
}
func check_binary(str []string, bPlace uint8, int_str string) bool {

	var remain float64
	pow := len(str) - int(bPlace)
	// b_f := 0
	// println("bPlace:",bPlace)
	// println("len_str:",len(str))
	// println("int_str:",int_str)
	for i := len(str) - 1; i >= int(bPlace); i-- {
		// println("i:",i)
		// if b_f == 0 && str[i] != "0" {
		// 	b_f = int(math.Pow(2, float64(pow)))
		// 	remain += 1
		// } else {
		if str[i] != "0" {
			remain += (math.Pow(2, -1*float64(pow)))

		}
		// }
		pow--
	}
	// println("remain:", remain)
	// println("b_f:", b_f)
	// println("b_f/remain:",b_f/remain)
	if remain == 0.5 {
		// println("str b4:",str[int(bPlace)-1])
		
		if int_str == "" {
			if str[int(bPlace)-1] == "0" {
				return false
			} else {
				return true
			}
		} else if int_str == "0" {
			return false
		} else {
			return true
		}
	} else if remain > 0.5 {
		return true
	}else{
		return true
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
