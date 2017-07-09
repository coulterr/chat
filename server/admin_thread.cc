#include "headers/admin_thread.h"

Admin_thread::Admin_thread(Threadpool *threadpool, Client_directory *directory)
{
	this -> threadpool = threadpool; 
	this -> directory = directory; 
}


void Admin_thread::list_clients()
{
	(*directory).list_clients(); 
}


void Admin_thread::listen_for_commands()
{	
	std::string cmd; 
	while (true)  
	{
		std::cin >> cmd; 
		if (cmd.compare("list_clients") == 0) {
			list_clients(); 
		}
	}
}

void Admin_thread::start()
{
	thread = new std::thread(&Admin_thread::listen_for_commands, this); 	
}

Admin_thread::~Admin_thread()
{

}
