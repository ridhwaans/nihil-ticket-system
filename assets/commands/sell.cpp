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

	//Get Event Title
	std::cout << "\nPlease enter the event of which to sell tickets for:\n";
	char* InputEventTitle = format( getLine() );
	EventName = new char[ strlen(InputEventTitle) ];
	strcpy( EventName, (const char*) InputEventTitle );   //copy to separate buffer, before next call to getLine()
	 
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
	if( !VallidTicketPrice ) {
		std:cout << "\n Invalid Ticket price! Sell transaction cancelled. \n";
		return;
	}


	//Get Number of Tickets to Sell
   std::cout << "\nPlease enter the number of tickets to sell:\n";
	char* InputNumOfTicket = format( getLine() );
	NumOfTickets = atoi( InputNumOfTicket );
	
	//Echo parameters
	std::cout << "\nEvent name is:     (" << EventName    << ")";
	std::cout << "\nValid Ticket Price: (" << ValidTicketPrice << ")";
	std::cout << "\nTicket Price is:   (" << TicketPrice  << ")  *expressed in # of cents";
	std::cout << "\nNum of Tickets is: (" << NumOfTickets << ")\n";


	//Get the seller's name (the user who is currently logged in)
	char* SellersUsername = accounts[ currentAccount_index ].username;

	std::cout << "\nSeller's name is: (" << SellersUsername << ")\n";


	//get all inputs
		//stop only if input line cannot be parsed
	//validate all inputs
		//e.g. username is in the accounts list


	//prepare relevant objects
		//e.g. new account, new tickets, etc

	//perform internal actions
		//e.g. accounts.add(newAccount) or tickets[4].quantity-=4

	//construct transaction
	//Transaction transaction();	
	//transaction.username = SellersUsername;	
	//transactions.add(transaction);	//push transaction
	
	return;
}




