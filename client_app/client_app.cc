#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream> 
int getAllContacts(int serverFD);
int getUpdatedContacts(int serverFD);
int getAllByContact(int serverFD, char *name);
int getNewByContact(int serverFD, char *name);
int addSending(int serverFD, char *name, char *body);
int sendMessage(int socketFD, char *message);
int receiveMessage(int socketFD, char *messageDest);


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
        portNum = 4453;
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

	while(true)
	{	
		std::string msg = getInput();  
		send(serverFD, (void *)msg.c_str(), msg.length(), 0); 
	}
}
