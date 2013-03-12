#include "../commands.h"


/**
 * Performs the necessary operations when the user invokes the buy command.
 * This command buys a specified number of tickets to a specified event,
 * from a specified user (the seller).
 * The user is asked for the following information, in this order:
 *		1 the event name
 *		2 the number of tickets to buy
 *		3 the seller's username
 *
 * PRECONDITION:   User must be logged in, and currentAccount_Index must be accurately set
 */
void command_buy(){
	char* EventName;
	int   NumOfTickets;
	char* UsernameOfSeller;

	//Get event title
	std::cout << "\nPlease enter the event of which to buy tickets for:\n";
	char* InputEventTitle = format( getLine() );
	EventName = new char[strlen(InputEventTitle) + 1];
	strcpy(EventName, (const char*) InputEventTitle);

	//Get Number of tickets to buy
   std::cout << "\nPlease enter the number of tickets to buy:\n";
	char* InputNumOfTicket = format( getLine() );
	NumOfTickets = atoi( InputNumOfTicket );

	//Get username of seller to buy from
	std::cout << "\nPlease enter the username of whom to purchase the tickets from\n";
	char* InputUsernameOfSeller = format( getLine() );
	UsernameOfSeller = new char[ strlen(InputUsernameOfSeller) + 1 ];
	strcpy(UsernameOfSeller, InputUsernameOfSeller);

	//Check if seller exists
	bool SellerExists = false; //will be set to true if seller is found
	for(int u = 0;  u<accounts.size();  u++) {
		if( strcmp(accounts[u].username, UsernameOfSeller)==0 ) {
			SellerExists = true;
			break;
		}
	}
	if( !SellerExists ) {
		std::cout << "Seller: '" << InputUsernameOfSeller << "' does not exist! Transaction cancelled. ";
		return;
	}

	//construct transaction
	Transaction* BuyTransact = new Transaction();
	BuyTransact->username = accounts[ currentAccount_index ].username;
	BuyTransact->type = accounts[ currentAccount_index ].type;
	BuyTransact->eventName = EventName;
	BuyTransact->code = Transaction::Buy;

	//transactionFile.add( *BuyTransact );	//why doesn't this work

	return;
}
