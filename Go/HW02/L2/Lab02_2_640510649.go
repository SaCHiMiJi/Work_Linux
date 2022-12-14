// ชื่อ ชัยนันท์ เรืองกจวณิชกุล
// 640510649
// Lab02_2
// 204203 Sec 001

package main

import (
	// "fmt"
	"strings"
)

const MAX = 141 // really?

func baseNAddition(r1, r2 string, base int) string {
	r1, r2 = add_zero(r1, r2)
	return addition(r1, r2, base)
}

func addition(n1, n2 string, base int) string {
	// fmt.Println("r1:", n1, "\nr2:", n2)
	result := []byte(strings.Repeat("x", MAX))
	len1 := len(n1)
	len2 := len(n2)
	carry := 0

	i, j, k := len1-1, len2-1, MAX-1

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

func add_zero(r1, r2 string) (string, string) {
	decPointPos1 := strings.Index(r1, ".")
	decPointPos2 := strings.Index(r2, ".")
	// println("1 :", decPointPos1, "| 2 :", decPointPos2)
	if decPointPos1 == -1 || decPointPos2 == -1 {
		len_r1 := len(r1)
		len_r2 := len(r2)
		arr_r1 := strings.Split(r1, ".")
		len_arr_r1 := len(string(arr_r1[0]))
		arr_r2 := strings.Split(r2, ".")
		len_arr_r2 := len(string(arr_r2[0]))
		l_loop := len_arr_r1 - len_arr_r2
		if l_loop > 0 {
			for i := 0; i < l_loop; i++ {
				r2 = "0" + r2
			}
		} else {
			l_loop *= -1
			for i := 0; i < l_loop; i++ {
				r1 = "0" + r1
			}
		}
		len_r1 = len(r1)
		len_r2 = len(r2)
		if decPointPos1 == -1 && decPointPos2 != -1 {
			// println(len_r2 - len_r1)
			r1 += "."
			for j := 0; j < len_r2-len_r1-1; j++ {
				r1 += "0"
			}
		} else if decPointPos1 != -1 && decPointPos2 == -1 {
			// println(len_r1 - len_r2)
			r2 += "."
			for j := 0; j < len_r1-len_r2-1; j++ {
				r2 += "0"
			}
		} else if decPointPos1 == -1 && decPointPos2 == -1 {
			if len_r1 > len_r2 {
				for j := 0; j < len_r1-len_r2; j++ {
					r2 = "0" + r2
				}
			} else if len_r1 < len_r2 {
				for j := 0; j < len_r2-len_r1; j++ {
					r1 = "0" + r1
				}
			}
		}

	} else {
		l_num := decPointPos1 - decPointPos2
		add_str := "r2"
		if decPointPos1 != decPointPos2 {
			if decPointPos1 < decPointPos2 {
				l_num = decPointPos2 - decPointPos1
				add_str = "r1"
			}
			// println("l_num:", l_num-1)
			for i := 0; i < l_num; i++ {
				if add_str == "r1" {
					r1 = "0" + r1
				} else {
					r2 = "0" + r2
				}
			}
		}

		len_r1 := len(r1)
		len_r2 := len(r2)
		if len_r1 > len_r2 {
			for j := 0; j < len_r1-len_r2; j++ {
				r2 += "0"
			}
		} else if len_r1 < len_r2 {
			for j := 0; j < len_r2-len_r1; j++ {
				r1 += "0"
			}
		}
	}
	return r1, r2
}

// 1111 11121 3
// 11111111111111111.1111111111111111 1101101010001.10001010 2 out 100001101101010001.1000100111111111
// 100.5021 250.230 8
// 101.1 100 2
// 11124.2521 4423112 8 out 4434236.2521
// 462636177263 154233552512.523414124 9 out 626870740775.523414124
