#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>

#include <string.h>
#include <sqlite3.h>
#include <semaphore.h>

#include "user.h"
#include "friend_request.h"
#include "friend_entry.h"

class Data_accessor
{
	private:
		sqlite3 *database; 
		const int ID_INDEX = 0; 
		const int NAME_INDEX = 0; 
		const int PASSWORD_INDEX = 1; 
		sem_t lock; 
		static const char GET_USER_STMT[];
		static const char ADD_USER_STMT[]; 
		static const char GET_FRIEND_ENTRIES_STMT[]; 
		static const char GET_INCOMING_FRIEND_REQUESTS_STMT[]; 
		static const char GET_OUTGOING_FRIEND_REQUESTS_STMT[]; 
		static const char ADD_FRIEND_REQUEST_STMT[]; 
		static const char GET_FRIEND_REQUEST_STMT[]; 
		static const char REMOVE_FRIEND_REQUEST_STMT[]; 
		static const char ADD_FRIEND_ENTRY_STMT[]; 
		static const char REMOVE_FRIEND_ENTRY_STMT[]; 


	public:
		Data_accessor(std::string path); 
		void get_user_by_id(int id); 
		bool add_user(std::string name, std::string password); 
		User *get_user_by_name(std::string name); 
		std::vector<Friend_entry> get_friend_entries(int id); 
		std::vector<Friend_request> get_incoming_friend_requests(int id); 
		std::vector<Friend_request> get_outgoing_friend_requests(int id); 
		bool add_friend_request(int sender, int recipient, int date);
		void remove_friend_request(int id); 
		bool add_friend_entry_pair(int a, int b); 
		void remove_friend_entry_pair(int a, int b); 

		~Data_accessor(); 

};

#endif
