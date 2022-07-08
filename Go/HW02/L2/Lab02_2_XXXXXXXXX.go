// ชื่อ นามสกุล ชื่อเล่น
// 6XXXXXXXX
// LabYY_Z |  HWYY_Z
// 204203 Sec 00B

package main

import (
	"strings"
)

const MAX = 36 // really?

func baseNAddition(r1, r2 string, base int) string {
	//decPointPos1 := strings.Index(r1, ".")
	//decPointPos2 := strings.Index(r2, ".")




	return ""
}

func addition(n1, n2 string) string {

	result := []byte(strings.Repeat("x", MAX))
	len1 := len(n1)
	len2 := len(n2)
	carry := 0

	i, j, k := len1-1, len2-1, MAX-1

	for ; i >= 0 || j >= 0; i, j, k = i-1, j-1, k-1 {
		temp := carry
		carry = 0

		if i >= 0 {
			temp += int(n1[i]) - int('0')
		}
		if j >= 0 {
			temp += int(n2[j]) - int('0')
		}

		result[k] = byte((temp % 10) + int('0'))
		carry = temp / 10
		// fmt.Print(result)
	}

	if carry > 0 {
		result[k] = '1'
	} else {
		k++
	}

	return string(result[k:])

}