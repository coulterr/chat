#include "headers/sock_writer.h"

SockWriter::SockWriter(int sock_fd) 
{
	this->sock_fd = sock_fd;  
}

bool SockWriter::sendMsg(std::string str)
{
	bool stat = true; 
	lock.lock(); 
	{
		const char *msg = str.c_str();
		ssize_t stat = send(sock_fd, (void *) msg, strlen(msg), 0); 
		if (stat == -1){
			stat = false;
		}
	}
	lock.unlock(); 

	return stat; 
}

SockWriter::~SockWriter()
{
	close(sock_fd); 
}

