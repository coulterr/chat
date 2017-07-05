#include "headers/threadpool.h"

bool process_login(Client *cli)
{
	std::string name = (*cli).recv_msg(); 
	(*cli).set_name(name); 
	return true; 
}

void start_listening(Client *cli, Client_dir *client_dir) 
{
	while(true)
	{ 
		std::cout << "Receiving from: " << (*cli).get_name() << std::endl; 
		std::string msg = (*cli).recv_msg();
		if (msg.compare("TIMEOUT") == 0)
		{
			if (!(*client_dir).dispatch_msg((*cli).get_name(), "KEEPALIVE"))
			{
				std::cout << "DIRTY SHUTDOWN" << std::endl;
				break;  
			}
		}
		else if (msg.compare("ERROR") == 0)
		{
			std::cout << "CLIENT LOST" << std::endl; 
			break; 
		}	
		else if (msg.compare("CLOSED") == 0)
		{
			std::cout << "CLEAN EXIT" << std::endl; 
			break; 	
		}
		else {
			std::string recipient = msg.substr(0, msg.find_first_of(" ", 0));
			msg = msg.substr(msg.find_first_of(" ", 0), msg.length());  
			msg = (*cli).get_name() + ": " + msg;
			(*client_dir).dispatch_msg(recipient, msg); 
		}
	}
}

Threadpool::Threadpool(Client_dir *client_dir)
{
	client_dir_ = client_dir; 
	client_queue_ = std::queue<Client*>(); 
	threads_ = std::vector<std::thread>(); 	
	empty_ = sem_t(); 
	full_ = sem_t(); 

	sem_init(&empty_, 0, 100); 
	sem_init(&full_, 0, 0);  
	
	for(int i = 0; i < 100; ++i){
		threads_.push_back(std::thread(&Threadpool::start_spinning, this)); 	
	}
	 
}

void Threadpool::start_spinning()
{
	 
	while(true){
		sem_wait(&full_);
		
			std::cout << "Acquiring client..." << std::endl; 
			Client *cli = client_queue_.front();
			client_queue_.pop();  
		
		sem_post(&empty_); 

		std::cout << "Processing login..." << std::endl;
		if(!process_login(cli)){
			//break	
		}

		(*client_dir_).add_client(cli); 
	
		std::cout << "Listening for messages..." << std::endl;
		start_listening(cli, client_dir_); 
		(*client_dir_).remove_client((*cli).get_name()); 
	}
}

void Threadpool::add_client(Client *cli)
{
	sem_wait(&empty_); 
	{
		std::cout << "Adding client..." << std::endl;
		client_queue_.push(cli); 
	}
	sem_post(&full_); 
}

Threadpool::~Threadpool()
{

}
