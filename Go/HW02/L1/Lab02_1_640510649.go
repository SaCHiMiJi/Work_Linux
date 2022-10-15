// ชื่อ ชัยนันท์ เรืองกจวณิชกุล
// 640510649
// Lab02_1
// 204203 Sec 001

package main

func powerOfTwo(x uint64) bool {
	return x-(x&(x-1)) == x
}
