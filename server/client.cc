#include "headers/client.h"

Client::Client(std::string name, int sockfd) 
{
	name_ = name; 
	sockfd_ = sockfd; 
}

Client::Client(int sockfd)
{
	sockfd_ = sockfd; 
}

void Client::set_name(std::string name)
{
	name_ = name; 
}

std::string Client::get_name()
{
	return name_; 
}

bool Client::send_msg(std::string msg)
{ 
	const char *str = msg.c_str();
	ssize_t status = send(sockfd_, (void *) str, strlen(str), 0); 
	
	if (status == -1){
		return false; 
	}

	return true; 
}

std::string Client::recv_msg()
{
	char buf[1024] = ""; 
	ssize_t status = recvfrom(sockfd_, (void *) buf, 1023, 0, NULL, NULL); 
	if(status == -1){
		return std::string("TIMEOUT"); 	
	}
	return std::string(buf); 
}


Client::~Client()
{
}

