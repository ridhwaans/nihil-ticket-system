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
	char* eventName;
	int 	quantity;
	int 	price;		
	char* username;
	
	Ticket( char* line );
	Ticket( char* eventname, int quantity, int price, char* username );
	
	bool isEnd();


	bool isValid();
public:
};

#endif
