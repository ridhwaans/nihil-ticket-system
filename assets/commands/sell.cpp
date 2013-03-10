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
	TicketPrice = 0; //to do  will need to consider the format the user enters like 90.43

	//Get Number of Tickets to Sell
   std::cout << "\nPlease enter the number of tickets to sell:\n";
	char* InputNumOfTicket = format( getLine() );
	NumOfTickets = atoi( InputNumOfTicket );
	
	//Echo parameters
	std::cout << "\nEvent name is: (" << EventName << ")";
	std::cout << "\nTicket Price is: (" << TicketPrice << ")";
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
		//e.g. Transaction transaction(Transaction.create);
			//transaction.username = username;
	//push transaction
	//transactions.add(transaction);
	
	return;
}




