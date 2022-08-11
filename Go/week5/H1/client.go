package main
import (
	"net"
	"fmt"
	"bufio"
	"os"
)

func main()  {
	// connect to sever
	conn,_ := net.Dial("tcp","127.0.0.1:8000")
	for {
		// create buffer to get keyboard input
		keyboard_buffer := bufio.NewReader(os.Stdin)
		fmt.Print("Text to send: ")
		text,_ := keyboard_buffer.ReadString('\n')
		//  send to sever
		fmt.Fprintf(conn, text + "\n")
		// create buffer and recieve from conn
		sever_buffer := bufio.NewReader(conn)
		message ,_ := sever_buffer.ReadString('\n')
		fmt.Print("Message from sever: "+message)

	}
}
