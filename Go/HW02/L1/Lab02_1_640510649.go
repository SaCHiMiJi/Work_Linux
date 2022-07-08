// ชื่อ นามสกุล - ชื่อเล่น
// 6XXXXXXXX
// Lab02_1
// 204203 Sec 00B

package main


func powerOfTwo(x uint64) bool {
	return x-(x&(x-1)) == x

}
