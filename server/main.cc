#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <thread>
#include <functional> 

#include "headers/sock_server.h"
#include "headers/threadpool.h"
#include "headers/client.h"

int main()
{
	Threadpool *tpool = new Threadpool(); 
	std::thread server_thread(listen_on_port, 4454, tpool); 		
	//listen_on_port(4449, func); 
	server_thread.join(); 
	return 0; 	
}
