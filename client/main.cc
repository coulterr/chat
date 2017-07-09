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

void listen_for_messages(int serverFD)
{
	while(true){

		ssize_t status; 
		int32_t tmp; 

		read(serverFD, &tmp, sizeof(tmp)); 

		int len = ntohl(tmp); 
		char buf[len + 1]; 
		status = recvfrom(serverFD, (void *) buf, len, 0, NULL, NULL); 
		buf[len] = 0; 
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
        portNum = 4451;
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
		int len = msg.length(); 
		int32_t tmp = htonl(len); 
		send(serverFD, &tmp, sizeof(tmp), 0);  
		send(serverFD, (void *)msg.c_str(), len, 0); 
	}
}


