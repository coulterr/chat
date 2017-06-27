#include "headers/sock_reader.h"


Sock_reader::Sock_reader(int sock_fd) 
{
	sock_fd_ = sock_fd;  
}

std::string Sock_reader::recv_msg()
{
	char buf[1024] = ""; 
	recv(sock_fd_, (void *) buf, 1023, 0); 
	return std::string(buf); 
}


Sock_reader::~Sock_reader()
{
}


