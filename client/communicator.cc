#include "headers/communicator.h"

Communicator::Communicator(int socketfd)
{
	this -> socketfd = socketfd; 
}


std::string Communicator::recv_message()
{
	ssize_t status; 
	int32_t tmp, len; 


	read(socketfd, &tmp, sizeof(tmp)); 

	len = ntohl(tmp); 
	char buf[len + 1]; 
	status = recvfrom(socketfd, (void *) buf, len, 0, NULL, NULL); 
	buf[len] = 0; 
	
	return std::string(buf);
	
}

void Communicator::send_message(std::string message)
{
	int len; 
	int32_t tmp; 

	len = message.length(); 
	tmp = htonl(len); 
	send(socketfd, &tmp, sizeof(tmp), 0);  
	send(socketfd, (void *)message.c_str(), len, 0); 
}

Communicator::~Communicator()
{
	close(socketfd); 
}
