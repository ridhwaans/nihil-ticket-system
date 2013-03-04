#ifndef assets_Ticket_h
#define assets_Ticket_h

class Ticket{
public:
	char[eventName_size] eventName;
	int quantity;
	int price;
	char[username_size] username;
	
	Ticket( char* line);
	bool isEnd();
public:
}

#endif
