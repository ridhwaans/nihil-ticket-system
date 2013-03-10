#include "../commands.h"


/**
 * Performs the necessary operations when the user invokes the buy command.
 * This command buys a specified number of tickets to a specified event,
 * from a specified user (the seller).
 * The user is asked for the following information, in this order:
 *		1 the event name
 *		2 the number of tickets to buy
 *		3 the seller's username
 */
void command_buy(){

	//Get Event Title
	std::cout << "\nPlease enter the event of which to buy tickets for:\n";
	char* InputEventTitle = format( getLine() );

	//Get Number of Tickets to Sell
   std::cout << "\nPlease enter the number of tickets to buy:\n";
	char* InputNumOfTicket = format( getLine() );

	//Get Ticket Price
	std::cout << "\nPlease enter the username of whom to purchase the tickets from\n";
	char* InputTicketPrice = format( getLine() );



	//get parameter
	//check for EOF
	//format input
	//check for null
	//validate parameter
	//if( failed){
		//error message
		//cout<< Error::badParameterError<< endl;
			//replace badParameterError with the specific error
		//return;}
	
	//validate parameter combinations?
	
	//construct transaction
	//Transaction transaction = new Transaction();
	//transaction.code = Transaction.Code.Buy;
	
	//send data to transactionFile
	//transactionFile.add( transaction);
	
	//done, clean up?
	return;
}
