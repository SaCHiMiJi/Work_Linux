// ชื่อ ชัยนันท์ เรืองกจวณิชกุล
// 640510649
// HW02_1
// 204203 Sec 001

package main

import (
	"strconv"
	"strings"
)

func ipv4Encode(ipString string) uint32 {
	var result uint32 = 0
	l := 3
	numSet := strings.Split(ipString, ".")
	// println(ipString)

	// println("numSet len:",   len(numSet))
	for i := 0; i < 4; i++ {
		int_num, _ := strconv.Atoi(numSet[i])
		// println("int_num:",int_num)
		result += (uint32(int_num)<<(l*8))
		l--
	}
	
	return result

}

func ipv4Decode(ipUint uint32) string {

	var result = ""
	for i := 3; i >=0; i-- {
		int_num := int(ipUint>>(8*i))
		// println("int_num:",int_num)
		ipUint -= uint32(int_num<<(8*i))
		str := strconv.Itoa(int_num)
		result += str 
		if i != 0 {
			result += "."
		}
	}
	return result

}
