#include "headers/client.h"
#include <cerrno>
#include <cstring>
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
	//ssize_t status = send(sockfd_, (void *) str, strlen(str), MSG_NOSIGNAL); 
	ssize_t status = send(sockfd_, (void *) str, strlen(str), 0); 
	status = send(sockfd_, (void *) str, strlen(str), MSG_NOSIGNAL); 
	
	std::cout << "send status: " << "to " << name_ << " " << status << std::endl;  
	
	if (status == -1 || status == EPIPE){
		std::cout << "On send(): ERROR:" << std::strerror(errno) << std::endl;  
		return false; 
	}

	return true; 
}

std::string Client::recv_msg()
{
	char buf[1024] = ""; 
	ssize_t status = recvfrom(sockfd_, (void *) buf, 1023, 0, NULL, NULL); 

	if(status == -1){
		std::cout << "detected timeout on recv" << std::endl; 	
		std::cout << "On recvfrom() ERROR:" << std::strerror(errno) << std::endl;  
		return std::string("TIMEOUT"); 
	}
	if(status == 0){
		std::cout << "detected clean exit on recv" << std::endl; 	
		return std::string("CLEANSHUT"); 

	}
	return std::string(buf); 
}


Client::~Client()
{
	close(sockfd_); 
}

