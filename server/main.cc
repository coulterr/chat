#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <thread>
#include <functional> 

#include "headers/sock_server.h"
#include "headers/threadpool.h"
#include "headers/client.h"
#include "headers/client_dir.h"

int main()
{
	Client_dir *client_dir = new Client_dir(); 
	Threadpool *tpool = new Threadpool(client_dir); 
	std::thread server_thread(listen_on_port, 4458, tpool); 
	//listen_on_port(4449, func); 
	server_thread.join(); 
	return 0; 	
}
