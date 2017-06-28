#include "headers/sock_reader.h"


Sock_reader::Sock_reader(int sock_fd) 
{
	sock_fd_ = sock_fd;  
}

std::string Sock_reader::recv_msg()
{
	char buf[1024] = ""; 
	ssize_t res = recvfrom(sock_fd_, (void *) buf, 1023, 0, NULL, NULL); 
	if(res == -1){
		std::cout << "ERROR" << std::endl;
	}
	return std::string(buf); 
}


Sock_reader::~Sock_reader()
{
}


