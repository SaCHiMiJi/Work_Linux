package main
import (
	"net"
	"fmt"
	"bufio"
	"os"
)

func main()  {
	fmt.Print("Start server...\n")

	// listen on port 8000
	ln,_ := net.Listen("tcp", ":8000")

	// accept to conection
	conn,_ := ln.Accept()

	// run loop forever (or until ctrl-c)
	for {
		// get message, output
		client_buffer := bufio.NewReader(conn)
		message,_ := client_buffer.ReadString('\n')
		fmt.Print("Message Received: ", string(message))

		keyboard_buffer := bufio.NewReader(os.Stdin)
		fmt.Print("Text to send: ")
		text,_ := keyboard_buffer.ReadString('\n')

		fmt.Fprintf(conn, text + "\n")
	}
}