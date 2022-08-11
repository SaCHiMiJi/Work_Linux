package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strings"
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
		if err != nil{
			fmt.Print("Client disconnection.\n")
		} 
		check(err,"Accepted connection.")
		
		go func(){
			client_buffer := bufio.NewReader(conn)
			name,_ := client_buffer.ReadString('\n')
			name = strings.Replace(name, "\n", " ", 3)
			for  {
				client_buffer = bufio.NewReader(conn)
				message,err := client_buffer.ReadString('\n')
				if err != nil{
					fmt.Print("Client disconnection.\n")
					break;
				} 
				fmt.Print(name + "Said: ", string(message))

				keyboard_buffer := bufio.NewReader(os.Stdin)
				fmt.Print("Text to send: ")
				text,_ := keyboard_buffer.ReadString('\n')

				fmt.Fprintf(conn, text + "\n")
				
				
			}
			
		}()
		
	}
}