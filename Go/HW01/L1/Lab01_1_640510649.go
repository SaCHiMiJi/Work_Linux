// ชัยนันท์ เรืองกิจวณิชกุล
// 640510649
// Lab01_1
// 204203 Sec 001

package main

import (
	"fmt"
	"log"
	"strings"
)

// set the maximum digit length. why 36 and not 35?
const MAX = 36

func main() {
	// why are we using string?
	var n1, n2 string

	// read in two string (can be multiple lines)
	_, err := fmt.Scan(&n1, &n2)

	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(addition(n1, n2))
}

func addition(n1, n2 string) string {
	// this is just a skeleton and will give out wrong result
	result := []byte(strings.Repeat("x", MAX))
	len1 := len(n1)
	len2 := len(n2)

	if len1 < len2 {
		n1, n2 = n2, n1
		len1, len2 = len2, len1
	}
	d := 0
	// loop from the left most digit
	i, j, k := len1-1, len2-1, MAX-1

	// loop from right most position
	for ; i >= 0; i, j, k = i-1, j-1, k-1 {
		// current digit
		currDigit := 0
		// add the value from the current digit of n1
		if i >= 0 {
			currDigit += int(n1[i]) - int('0')
		}
		// add the value from the current digit of n2
		if j >= 0 {
			currDigit += int(n2[j]) - int('0')
		} else {
			currDigit += int('0') - int('0')
		}
		// convert back to byte (one char is called byte)
		if string(result[k]) == "x" {
			result[k] = byte(currDigit%10 + int('0'))
		} else {
			num := (1 + int(currDigit%10)) % 10
			result[k] = byte(num + int('0'))
			currDigit += 1
		}
		if currDigit/10 != 0 && k > 0 {
			result[k-1] = byte(currDigit/10 + int('0'))
			d++
		}
		if k == 0 {
			d = 1
		} else if k-d < 0 {
			d = 1
		} else if string(result[k-d]) == "x" {
			d--
		}
	}
	// convert array of bytes to string
	return string(result[k-d+1:])

}
