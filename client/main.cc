#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream> 
#include <thread>
#include <arpa/inet.h>
#include "headers/listener.h"
#include "headers/communicator.h"

const int PORT = 4467;


std::string getInput()
{
	std::string msg; 
	std::getline(std::cin, msg); 
	return msg; 
}


int main()
{
        int socketfd, portNum;
        struct sockaddr_in serverAddress;
        struct hostent *server;

	char hostname[] = "localhost";
        portNum = PORT;
        socketfd = socket(AF_INET, SOCK_STREAM, 0);
        server = gethostbyname(hostname);

        bzero( (char *) &serverAddress, sizeof(serverAddress) );
        serverAddress.sin_family = AF_INET;
        bcopy( (char *) server -> h_addr, (char *) &serverAddress.sin_addr.s_addr, server -> h_length);
        serverAddress.sin_port = htons(portNum);

        if(connect(socketfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0){
                fprintf(stderr, "ERROR: Could not connect.");
                exit(0);
        }

	Communicator *comm = new Communicator(socketfd); 

	(*comm).send_message(std::string("LOGIN")); 
	(*comm).send_message(getInput()); 

	Listener listener = Listener(comm); 
	listener.start_listening(); 

	while(true){
		(*comm).send_message(getInput()); 
			
	}; 

}


