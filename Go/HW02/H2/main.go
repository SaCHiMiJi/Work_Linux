package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
)

func main() {

	var line string
	var s string = ""
	var bp int = -1
	scanner := bufio.NewScanner(os.Stdin)

	for scanner.Scan() {
		line = scanner.Text()

		var err error
		if s == "" {
			_, err = fmt.Sscanf(line, "%s", &s)

		} else {
			_, err = fmt.Sscanf(line, "%d", &bp)
		}

		if err != nil {
			if err != io.EOF {
				log.Fatal(err)
			}
			break
		}

		if bp != -1 {
			fmt.Println(roundToEven(s, uint8(bp)))
			s = ""
			bp = -1
		}
	}
}
