// ชัยนันท์ เรืองกิจวณิชกุล
// 640510649
// HW00
// Problem A
// 204203 Sec 00B 

package main

func factorial(num1 int8) int64 {
	var result int64 = 1

	for i := 0; i < int(num1); i++ {
		result *= int64(num1) - int64(i)
	}
	return result
}
