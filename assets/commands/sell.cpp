//library includes
#include <iostream>

//local includes
#include "../Account.h"
#include "../Transaction.h"
#include "../TransactionFile.h"
#include "../errors.h"
#include "../Ticket.h"
#include "../Transaction.h"
#include "../TransactionFile.h"

//override include
#include "../commands.h"



/**
 * Performs the necessary operations when the user invokes the sell command.
 * This command sells a specified number of tickets to a specified event,
 * with the specified price per ticket.
 * The user is asked for the following information, in this order:
 *		1 the event name
 *		2 pricer per ticket
 *		3 number of tickets to sell
 *
 * PRECONDITION:   User must be logged in, and currentAccount_Index must be accurately set
 */
void command_sell(){
	char* EventName;
	int   TicketPrice;
	int   NumOfTickets;

	//Check for correct account type to be allowed to sell
	if( accounts[currentAccount_index].type == Account::Buy ) {
		std::cout << "\n[Fail] Your user account type does not allow you to sell. \n";
		return;
	}

	//Get Event Title
	bool ValidEventName = true;
	std::cout << "\nPlease enter the event of which to sell tickets for:\n";
	char* InputEventTitle = format( getLine() );
	EventName = new char[ strlen(InputEventTitle) + 1];
	strcpy( EventName, (const char*) InputEventTitle );   //copy to separate buffer, before next call to getLine()
	if( strlen(EventName) == 0 || strlen(EventName) > eventName_size ) ValidEventName = false;
	for(int i = 0;  i<strlen(EventName);  i++)
		if( isalnum(EventName[i]) == 0 && EventName[i] != '-' && EventName[i] != '_') //if a character is not alphanumeric, and its not a - or _ its invalid
			ValidEventName = false;
	if( !ValidEventName ) {
		std::cout << "\n" << Error::badEventStringError << "\n";
		return;
	}		
	 
	//Get Ticket Price
	std::cout << "\nPlease enter the price per ticket:\n";
	char* InputTicketPrice = format( getLine() );
	bool ValidTicketPrice = true;									//will be set to false if anything is wrong with input
	int Periods = 0;
	for( int i = 0;  i<strlen(InputTicketPrice);  i++) {	//first ensure there are no invalid chars, and at most 1 period
		char C = InputTicketPrice[i];
		if( C == '.' ) Periods++;
		else if( C!='0' && C!='1' && C!='2' && C!='3' && C!='4' && C!='5' && C!='6' && C!='7' && C!='8' && C!='9' ) 
			ValidTicketPrice = false;  
	}
	if( Periods != 0 && Periods != 1 ) ValidTicketPrice = false;
	if( ValidTicketPrice ) {   //Parse input string to get integer and fractional part (if a valid input string)
		int i = 0;
		//Extract Integer portion
		char* TicketPrice_IntPart   = new char[ strlen(InputTicketPrice) + 1];
		char* TicketPrice_FractPart = new char[ strlen(InputTicketPrice) + 1];
		int d = 0;	
		int f = 0;
		while( i<strlen(InputTicketPrice) ) {	//Extract decimal portion
			if( InputTicketPrice[i] != '.' ) {
				TicketPrice_IntPart[d] = InputTicketPrice[i];
				d++;
				i++; 
			}
			else {
				i++;  //skip over period
				while( i<strlen(InputTicketPrice) ) {
					TicketPrice_FractPart[f] = InputTicketPrice[i];
					f++;
					i++; }
				break;
			}
		}
		TicketPrice_IntPart[d] = 0;     //null terminator for integer string
		TicketPrice_FractPart[f] = 0;   //null terminator
		int IntPart = atoi( TicketPrice_IntPart );
		int FractPart = atoi( TicketPrice_FractPart );
		if( FractPart != 0 ) 
			while( FractPart % 10 == 0) 
				FractPart /= 10;  //get rid of zeros to right
		if( IntPart >= 0 && IntPart < 1000 && FractPart >= 0 && FractPart <= 99 )
			TicketPrice = IntPart * 100 + FractPart;
		else
			ValidTicketPrice = false;
	}
	if( !ValidTicketPrice ) {
		std::cout << "\n[Fail] Invalid Ticket price! Sell transaction cancelled. \n";
		return;
	}

	//Get Number of Tickets to Sell
   std::cout << "\nPlease enter the number of tickets to sell:\n";
	char* InputNumOfTickets = format( getLine() );
	NumOfTickets = atoi( InputNumOfTickets );
	if( strlen(InputNumOfTickets)==0 || NumOfTickets <= 0 || NumOfTickets >= 1000 ) {
		std::cout << "\n[Fail] Invalid number of tickets.\n";
		return;
	}

	//Get the seller's name (the user who is currently logged in)
	char* SellersUsername = accounts[ currentAccount_index ].username;

	//Construct a new ticket representing the tickets being sold
	Ticket* t = new Ticket( EventName, NumOfTickets, TicketPrice, SellersUsername);
	tickets_queue.push_back( *t ); //goes into queue of tickets sold during this session

	std::cout << "\n[Success] Tickets Sold. \n";

	//construct transaction
	Transaction SellTransact;
	SellTransact.username = SellersUsername;
	SellTransact.type = accounts[ currentAccount_index ].type;
	SellTransact.eventName = EventName;
	SellTransact.ticketAmount = TicketPrice;
	SellTransact.code = Transaction::Sell;
	
	transactionFile->add( SellTransact );	

	return;
}




