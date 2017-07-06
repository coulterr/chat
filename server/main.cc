#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <thread>
#include <functional> 

#include "headers/sock_server.h"
#include "headers/threadpool.h"
#include "headers/client.h"
#include "headers/client_dir.h"
//#include "headers/admin_tools.h"
int main()
{
	Client_dir *directory = new Client_dir(); 
	Threadpool *tpool = new Threadpool(100); 
	std::thread server_thread = std::thread(listen_on_port, 4491, tpool, directory); 
	server_thread.join(); 
	return 0; 	
}
