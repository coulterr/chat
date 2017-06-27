#ifndef SOCK_READER_H_INCLUDED
#define SOCK_READER_H_INCLUDED

#include <sys/socket.h>
#include <string>

class Sock_reader
{
	private:
		int sock_fd_; 
	public:
		Sock_reader(int sock_fd);
		std::string recv_msg();
		~Sock_reader();
};
#endif // SOCK_READER_H_INCLUDED
