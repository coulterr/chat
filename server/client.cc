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
	int len = strlen(str); 
	int32_t tmp = htonl(len); 	
	
	status = send(sockfd_, &tmp, sizeof(tmp), MSG_NOSIGNAL); 
	if (status == -1 || status == EPIPE)
	{
		//std::cout << "On send(): ERROR:" << std::strerror(errno) << std::endl;  
		return false; 
	}
	
	status = send(sockfd_, (void *) str, len, MSG_NOSIGNAL); 
	if (status == -1 || status == EPIPE)
	{
		//std::cout << "On send(): ERROR:" << std::strerror(errno) << std::endl;  
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
	
		status = read(sockfd_, ((char *) &tmp) + sizeof(tmp) - goal, goal);
		//std::cout << std::strerror(errno) << std::endl;	
		if (status == -1)
		{
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
	
	if (len <= 0)
	{
		return "ERROR"; 
	}
	
	//std::cout << len << std::endl;
	char buf[len + 1];  
	
	goal = len;  
	while (goal > 0) {
	
		status = read(sockfd_, buf + len - goal, goal);
	
		if (status == -1)
		{
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
	buf[len] = 0; 
	return std::string(buf); 

}


Client::~Client()
{
	close(sockfd_); 
}

