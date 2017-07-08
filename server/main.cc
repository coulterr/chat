#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <thread>
#include <functional> 

#include "headers/server_thread.h"
#include "headers/threadpool.h"
#include "headers/client.h"
#include "headers/client_directory.h"
//#include "headers/admin_tools.h"
int main()
{
	Client_directory *directory = new Client_directory(); 
	Threadpool *threadpool = new Threadpool(100); 
	//std::thread server_thread = std::thread(listen_on_port, 4491, tpool, directory); 
	//server_thread.join(); 
	Server_thread server = Server_thread(4447, threadpool, directory); 
	server.start(); 
	while(true){}; 
	return 0; 	
}
