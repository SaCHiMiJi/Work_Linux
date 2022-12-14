package main

import (
	"fmt"
	"io"
	"log"
	"strconv"
	"strings"
)

func main() {

	var numCase int
	var line string
	var n uint32

	fmt.Scan(&numCase)

	for i := 0; i < numCase; i++ {
		_, err := fmt.Scan(&line)
		if err != nil {
			if err != io.EOF {
				log.Fatal(err)
			}
			break
		}

		if strings.Contains(line, ".") {
			fmt.Println(ipv4Encode(line))
		} else {
			temp, _ := strconv.Atoi(line)
			n = uint32(temp)
			fmt.Println(ipv4Decode(n))
		}
	}

}
