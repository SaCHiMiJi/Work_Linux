package main
import (
	"net"
	"fmt"
	"bufio"
	"os"
)

func check(err error, message string){
	
	if err != nil{
		panic(err)
	}
	fmt.Printf("%s\n",message)
	
}

func main()  {
	

	// listen on port 8000
	ln,err := net.Listen("tcp", ":8000")


	check(err,"Start server is ready.")
	// accept to conection
	

	// run loop forever (or until ctrl-c)
	for {
		// get message, output
		conn,err := ln.Accept()
		check(err,"Accepted connection.")
		
		
		go func(){

			for  {
				client_buffer := bufio.NewReader(conn)
				message,err := client_buffer.ReadString('\n')
				if err != nil{
					fmt.Print("Client disconnection.\n")
					break;
				} 
				fmt.Print("Message Received: ", string(message))

				keyboard_buffer := bufio.NewReader(os.Stdin)
				fmt.Print("Text to send: ")
				text,_ := keyboard_buffer.ReadString('\n')

				fmt.Fprintf(conn, text + "\n")
				
				
			}
			
		}()
		
	}
}