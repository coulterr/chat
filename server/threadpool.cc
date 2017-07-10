#include "headers/threadpool.h"



Threadpool::Threadpool(int threadcount, Client_directory &directory)
: directory(directory) 
{
	sem_init(&empty, 0, threadcount); 
	sem_init(&full, 0, 0);  
	
	for(int i = 0; i < threadcount; ++i){
		threads.push_back(new std::thread(&Threadpool::start_spinning, this)); 	
	}
	 
}

void Threadpool::start_spinning()
{
	 
	while(true){
		sem_wait(&full);
		
			Client *client = clients.front();
			clients.pop();  
		
		sem_post(&empty); 

		Connection::start(*client, directory); 
		delete client; 
	}
}

void Threadpool::add_client(int socketfd)
{
	sem_wait(&empty); 
	{
		Client *client = new Client(socketfd); 
		clients.push(client); 
	}
	sem_post(&full); 
}

Threadpool::~Threadpool()
{

}
