package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
	"strings"
)

func main() {

	var line string
	var n1, n2 string = "", ""
	var base int = -1
	scanner := bufio.NewScanner(os.Stdin)
	// var result []string
	for scanner.Scan() {
		line = scanner.Text()

		if strings.HasPrefix(line, "#") || strings.HasPrefix(line, "//") { // skip the line starting with #
			continue
		}

		_, err := fmt.Sscanf(line, "%s %s %d", &n1, &n2, &base)

		if err != nil {
			if err != io.EOF {

				log.Fatal(err)
			}
			break
		}

		fmt.Println(baseNAddition(n1, n2, base))

	}
}
