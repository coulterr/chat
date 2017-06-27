#ifndef SOCK_WRITER_H_INCLUDED
#define SOCK_WRITER_H_INCLUDED

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#include <mutex>
#include <string>

class SockWriter 
{
	private: 
		int sock_fd; 
		std::mutex lock;
	public:  
		SockWriter(int sock_fd);
		bool sendMsg(std::string str);
		~SockWriter();
};

#endif // SOCK_WRITER_H_INCLUDED
