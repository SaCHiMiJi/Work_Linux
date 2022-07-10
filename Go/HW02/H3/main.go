package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
)

const BIT_LEN = 16
func main() {

	var x float32
	var line string

	scanner := bufio.NewScanner(os.Stdin)
	// var result []string
	for scanner.Scan() {
		line = scanner.Text()

		_, err := fmt.Sscanf(line, "%f", &x)
		if err != nil {
			if err != io.EOF {
				log.Fatal(err)
			}
			break
		}
		result := float16bitNormed(x)
		if len(result) == BIT_LEN {
			fmt.Println(string(result[0]) + " " + string(result[1:9]) + " " + string(result[9:]))
		} else {
			fmt.Println(result)
		}

	}
}
