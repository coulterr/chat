#include "headers/threadpool.h"



Threadpool::Threadpool(int threadcount)
{
	connections_ = std::queue<Connection*>(); 
	threads_ = std::vector<std::thread>(); 	
	empty_ = sem_t(); 
	full_ = sem_t(); 

	sem_init(&empty_, 0, threadcount); 
	sem_init(&full_, 0, 0);  
	
	for(int i = 0; i < threadcount; ++i){
		threads_.push_back(std::thread(&Threadpool::start_spinning, this)); 	
	}
	 
}

void Threadpool::start_spinning()
{
	 
	while(true){
		sem_wait(&full_);
		
			Connection *connection = connections_.front();
			connections_.pop();  
		
		sem_post(&empty_); 

		(*connection).start(); 
	}
}

void Threadpool::add_connection(Connection *connection)
{
	sem_wait(&empty_); 
	{
		connections_.push(connection); 
	}
	sem_post(&full_); 
}

Threadpool::~Threadpool()
{

}
