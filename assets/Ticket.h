#ifndef assets_Ticket_h
#define assets_Ticket_h

//library headers
#include <cstring>
#include <cstdlib>
#include <iostream>

//local headers
#include "globals.h"
#include "errors.h"

class Ticket{
public:
	char* eventName;		//will trimmed from white space, and converted to lower case by constructor
	int 	quantity;		
	int 	price;		
	char* username;
	
	Ticket( char* line );
	Ticket( const Ticket& other);
	Ticket( char* eventname, int quantity, int price, char* username );
	~Ticket();
	
	Ticket& operator=( const Ticket& other);
	
	bool isEnd();
	bool isValid();
private:
};

#endif
