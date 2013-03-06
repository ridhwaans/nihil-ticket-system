#include "Ticket.h"


/**
 * Constructs a ticket object, using the line of text from an available tickets file.
 * The ticket object represents a given number of tickets, being sold by a particular
 * user, at some ticket price.
 *
 * @param line   Pointer to a c-string representing the line of text from an atf file.
 */
Ticket::Ticket( char* line) {

	//Ensure line is 45 Characters exactly
	if( strlen( line ) != eventName_size + 1 + username_size + 1 + quantity_size + 1 + price_size ) {
		throwError( Error::TicketLineTooLongError);  // temporarily commented out throwError
		return;
	}

	//Extract event name from line.
	this->eventName = new char[eventName_size + 1];  								//+1 for space for null terminator
	memcpy( (void*) this->eventName, (const void*) line, eventName_size );  //copies eventName_size chars to indices 0 to (eventName_size-1)
	this->eventName[eventName_size] = '\0';												//null terminator 

	//Extract Seller's Username from line
	this->username = new char[username_size + 1];
	memcpy( (void*) this->username, (const void*) &line[eventName_size+1], username_size );//copy username_size chars starting at first char of username in line string
	this->username[username_size] = '\0';

	//Extract quantity of tickets to sell from line
	char* TempQuantityString = (char*) malloc(4);					//3 chars + 1 char for null terminator
	memcpy( (void*) TempQuantityString, (const void*)	&line[eventName_size+1+username_size+1], 3 );
	TempQuantityString[3] = '\0';
	this->quantity = atoi( (const char*) TempQuantityString );
	free( (void*) TempQuantityString );

	//Extract ticket price from line
	char* TempTicketPriceString = (char*) malloc(6);
	memcpy( (void*) TempTicketPriceString,     (const void*) &line[eventName_size+1+username_size+1+3+1],     3);  //copy
   memcpy( (void*) &TempTicketPriceString[3], (const void*) &line[eventName_size+1+username_size+1+3+1 + 4], 2);
	TempTicketPriceString[5] = '\0';
	this->price = (double) atoi( (const char*) TempTicketPriceString );
	free( (void*) TempTicketPriceString );

}


/**
 * Constructs a ticket object, representing the specified number of tickets available to
 * be sold from the given seller (username), to be sold at the given ticket price (price)
 *
 * @param 
 */
Ticket::Ticket( char* eventname, int quantity, int price, char* username) {
	this->eventName = eventname;
	this->quantity = quantity;
	this->price = price;
	this->username = username;
}


/**
 * Checks if the ticket object has eventName "END", indicating that the
 * ticket object is a token reprenting the end of the ticket lines found in
 * the available tickets file it was created from.
 *
 * @return True if the eventName begins with "END" or false elsewise.
 */
bool Ticket::isEnd() {
	if( strncmp( (const char*) eventName, (const char*) "END", 3) == 0 )
		return true;
	else
		return false;
   
}


/**
 * Validates the ticket object, ensuring all it's parameters are valid.
 * This is used to ensure successful ticket creation.

 * @return True if the ticket object is valid, false elsewise.
 */
bool Ticket::isValid() {

	//Verify that the event name is set and of correct length
	if( this->eventName == NULL || strlen( this->eventName ) != eventName_size )
		return false;

	//Verify that seller name is set and of correct length
	if( this->username == NULL || strlen( this->username) != username_size )
		return false;

	//Verify that quantity is within the acceptable range
	if( this->quantity < 0 || this->quantity >= 1000 )
		return false;

	//Verify that the ticket price is within the acceptable range
	if( this->price < 0 || this->price >= 1000 )
		return false;


	return true;
}





