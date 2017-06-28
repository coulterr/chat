#include "headers/threadpool.h"

bool process_login(Client *cli)
{
	std::string name = (*cli).recv_msg(); 
	(*cli).set_name(name); 
	return true; 
}

void start_listening(Client *cli) 
{
	while(true)
	{
		std::string msg = (*cli).recv_msg();
		if(msg.compare("TIMEOUT") == 0){
			std::cout << "ERROR" << std::endl; 
		}
		std::cout << msg << std::endl; 
	}
}

Threadpool::Threadpool()
{
	client_queue_ = new std::queue<Client*>(); 
	threads_ = new std::vector<std::thread*>(); 	
	empty_ = new sem_t(); 
	full_ = new sem_t(); 

	sem_init(empty_, 0, 100); 
	sem_init(full_, 0, 0);  
	
	for(int i = 0; i < 100; ++i){
		(*threads_).push_back(new std::thread(&Threadpool::start_spinning, this)); 	
	}
	 
}

void Threadpool::start_spinning()
{
	Client *cli;
	 
	while(true){
		sem_wait(full_);
		{
			std::cout << "Acquiring client..." << std::endl; 
			cli = (*client_queue_).front();
			(*client_queue_).pop();  
		}
		sem_post(empty_); 

		std::cout << "Processing login..." << std::endl;
		if(!process_login(cli)){
			//break	
		}
	
		std::cout << "Listening for messages..." << std::endl;
		start_listening(cli); 
	}
}

void Threadpool::add_client(Client *cli)
{
	sem_wait(empty_); 
	{
		std::cout << "Adding client..." << std::endl;
		(*client_queue_).push(cli); 
	}
	sem_post(full_); 
}

Threadpool::~Threadpool()
{

}
