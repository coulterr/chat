#ifndef SOCK_READER_H_INCLUDED
#define SOCK_READER_H_INCLUDED

#include <sys/socket.h>
#include <string>

class SockReader
{
	private:
		int sock_fd; 
	public:
		SockReader(int sock_fd);
		std::string recvMsg();
		~SockReader();
};
#endif // SOCK_READER_H_INCLUDED
