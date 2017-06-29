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

void listen_for_messages(int serverFD)
{
	while(true){

		char buf[1024] = ""; 
		ssize_t status = recvfrom(serverFD, (void *) buf, 1023, 0, NULL, NULL); 
		std::cout << std::string(buf) << std::endl; 
	}

}


std::string getInput()
{
	std::string msg; 
	std::getline(std::cin, msg); 
	return msg; 
}


int main()
{
        int serverFD, portNum, len;
        struct sockaddr_in serverAddress;
        struct hostent *server;

	char hostname[] = "localhost";
        portNum = 4481;
        serverFD = socket(AF_INET, SOCK_STREAM, 0);
        server = gethostbyname(hostname);

        bzero( (char *) &serverAddress, sizeof(serverAddress) );
        serverAddress.sin_family = AF_INET;
        bcopy( (char *) server -> h_addr, (char *) &serverAddress.sin_addr.s_addr, server -> h_length);
        serverAddress.sin_port = htons(portNum);

        if(connect(serverFD, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0){
                fprintf(stderr, "ERROR: Could not connect.");
                exit(0);
        }

	std::thread listen_thread(listen_for_messages, serverFD);
	while(true)
	{	
		std::string msg = getInput();  
		if(msg.compare("close") == 0){
			close(serverFD); 
			exit(0); 
		}
		send(serverFD, (void *)msg.c_str(), msg.length(), 0); 
	}
}


