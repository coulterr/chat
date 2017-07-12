#include "headers/friend_request.h"

Friend_request::Friend_request(int id, int sender, int recipient)
:id(id), sender(sender), recipient(recipient)
{
		
}

int Friend_request::get_id()
{
	return id; 
}

int Friend_request::get_sender()
{
	return id; 
}

int Friend_request::get_recipient()
{
	return recipient; 
}

Friend_request::~Friend_request(){}; 
