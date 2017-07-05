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
	ssize_t status; 
	const char *str = msg.c_str();
	int32_t len = htonl(strlen(str)); 	
	
	status = send(sockfd_, &len, sizeof(len), MSG_NOSIGNAL); 
	if (status == -1 || status == EPIPE)
	{
		std::cout << "On send(): ERROR:" << std::strerror(errno) << std::endl;  
		return false; 
	}
	
	status = send(sockfd_, (void *) str, len, MSG_NOSIGNAL); 
	if (status == -1 || status == EPIPE)
	{
		std::cout << "On send(): ERROR:" << std::strerror(errno) << std::endl;  
		return false; 
	}

	return true; 
}

std::string Client::recv_msg()
{
	int goal; 
	ssize_t status; 
	
	int32_t tmp; 

	goal = sizeof(tmp); 
	while (goal > 0) {
	
		status = read(sockfd_, &tmp + sizeof(tmp) - goal, goal);
		
		if (status == -1)
		{
			//timeout or error?
			if (errno == EAGAIN) 
			{
				 return "TIMEOUT"; 
			}
			else 
			{
				return "ERROR"; 
			}
		}
		else if (status == 0) 
		{
			return "CLOSED"; 
		}
		goal -= status; 	 
	}
	
	int len = ntohl(tmp); 
	char buf[len + 1] = ""; 
	
	goal = len;  
	while (goal > 0) {
	
		status = read(sockfd_, buf + len - goal, goal);
	
		if (status == -1)
		{
			//timeout or error?
			if (errno == EAGAIN) 
			{
				 return "TIMEOUT"; 
			}
			else 
			{
				return "ERROR"; 
			}
		}
		else if (status == 0) 
		{
			return "CLOSED"; 
		}
		goal -= status; 	 
	}
}


Client::~Client()
{
	close(sockfd_); 
}

