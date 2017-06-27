#ifndef SOCK_WRITER_H_INCLUDED
#define SOCK_WRITER_H_INCLUDED

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#include <mutex>
#include <string>

class Sock_writer 
{
	private: 
		int sock_fd_; 
	public:  
		Sock_writer(int sock_fd);
		bool send_msg(std::string str);
		~Sock_writer();
};

#endif // SOCK_WRITER_H_INCLUDED
