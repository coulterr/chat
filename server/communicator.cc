#include "headers/communicator.h"

Communicator::Communicator(int socketfd)
{
	this -> socketfd = socketfd; 
}

bool Communicator::send_message(std::string message)
{ 
	ssize_t status; 
	const char *str = message.c_str();
	int len = strlen(str); 
	int32_t tmp = htonl(len); 	
	
	status = send(socketfd, &tmp, sizeof(tmp), MSG_NOSIGNAL); 
	if (status == -1 || status == EPIPE)
	{
		//std::cout << "On send(): ERROR:" << std::strerror(errno) << std::endl;  
		return false; 
	}
	
	status = send(socketfd, (void *) str, len, MSG_NOSIGNAL); 
	if (status == -1 || status == EPIPE)
	{
		//std::cout << "On send(): ERROR:" << std::strerror(errno) << std::endl;  
		return false; 
	}

	return true; 
}

std::string Communicator::recv_message()
{
	int goal; 
	ssize_t status; 
	
	int32_t tmp; 

	goal = sizeof(tmp); 
	while (goal > 0) {
	
		status = read(socketfd, ((char *) &tmp) + sizeof(tmp) - goal, goal);
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
	
		status = read(socketfd, buf + len - goal, goal);
	
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

Communicator::~Communicator()
{
	close(socketfd); 
}
