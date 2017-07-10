#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <thread>
#include <functional> 

#include "headers/server_thread.h"
#include "headers/threadpool.h"
#include "headers/client.h"
#include "headers/client_directory.h"
#include "headers/admin_thread.h"

int main()
{
	const int PORT = 4467;
	const int THREADCOUNT = 100; 

	Client_directory *directory = new Client_directory(); 
	Threadpool *threadpool = new Threadpool(THREADCOUNT, *directory); 
	Server_thread server_thread(PORT, *threadpool); 
	server_thread.start();
	Admin_thread admin_thread(*threadpool, *directory); 
	admin_thread.start(); 
	std::cout << "Server running..." << std::endl; 



	while(true){}; 
	return 0; 	
}
