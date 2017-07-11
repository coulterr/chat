#include "headers/threadpool.h"



Threadpool::Threadpool(int threadcount)
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
		
			Connection *connection = connections.front();
			connections.pop();  
		
		sem_post(&empty); 

		(*connection).start(); 
		delete connection; 
	}
}

void Threadpool::add_connection(Connection *connection)
{
	sem_wait(&empty); 
	{
		connections.push(connection); 
	}
	sem_post(&full); 
}

Threadpool::~Threadpool()
{

}
