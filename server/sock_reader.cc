#include "headers/sock_reader.h"


SockReader::SockReader(int sock_fd) 
{
	(*this).sock_fd = sock_fd;  
}

std::string SockReader::recvMsg()
{
	char buf[1024] = ""; 
	recv(sock_fd, (void *) buf, 1023, 0); 
	return std::string(buf); 
}


SockReader::~SockReader()
{
}


