#ifndef FRIEND_REQUEST_H
#define FRIEND_REQUEST_H

class Friend_request 
{
	private: 
		int id; 
		int sender; 
		int recipient; 
	public: 
		Friend_request(int id, int sender, int recipient); 
		int get_id(); 
		int get_sender(); 
		int get_recipient(); 
		~Friend_request(); 

};
#endif
