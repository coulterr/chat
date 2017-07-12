#ifndef FRIEND_ENTRY_H
#define FRIEND_ENTRY_H

class Friend_entry
{
	private: 
		int id; 
		int a; 
		int b; 
	public: 
		Friend_entry(int id, int a, int b); 
		int get_id(); 
		int get_a(); 
		int get_b(); 
		~Friend_entry(); 
		

};

#endif
