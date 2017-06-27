#include "headers/sock_writer.h"

Sock_writer::Sock_writer(int sock_fd) 
{
	sock_fd_ = sock_fd;  
}

bool Sock_writer::send_msg(std::string str)
{
	bool stat = true; 
	const char *msg = str.c_str();
	ssize_t val = send(sock_fd_, (void *) msg, strlen(msg), 0); 
	
	if (val == -1){
		stat = false;
	}

	return stat; 
}

Sock_writer::~Sock_writer()
{
	close(sock_fd_); 
}

