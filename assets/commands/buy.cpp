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

	//Check for correct account type to be allowed to buy
	if( accounts[currentAccount_index].type == Account::Sell ) {
		std::cout << "\n Your user account type does not allow you to buy. \n";
		return;
	}

	//Show user a listing of all tickets available
	std::cout <<   "\n                   TICKETS AVAILABLE FOR SALE                          \n";
	std::cout <<     " Seller:         Event:              Quantity:    Ticket Price (CENTS):\n";
	std::cout <<     " ======================================================================\n";
	for(int i = 0;  i<tickets.size();  i++) {
		std::cout << " " << tickets[i].username;
		for(int j = 0;  j<16-strlen(tickets[i].username); j++)  std::cout << " ";
		std::cout << tickets[i].eventName;
		for(int j = 0;  j<20-strlen(tickets[i].eventName); j++) std::cout << " ";
		std::cout << tickets[i].quantity;
		for(int j = 0;  j<14;  j++) std::cout << " ";
		std::cout << tickets[i].price << "\n";
	}
   std::cout <<     " ----------------------------------------------------------------------\n";
	std::cout <<     "                    YOUR CREDIT BALANCE: " << accounts[currentAccount_index].credit << " (CENTS)\n\n";


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
	if( strcmp( UsernameOfSeller, "admin" ) == 0 ) SellerExists = true;   //there always exists the build in account 'admin'
	for(int u = 0;  u<accounts.size();  u++) {
		if( strcmp(accounts[u].username, UsernameOfSeller)==0 ) {
			SellerExists = true;
			break;
		}
	}
	if( !SellerExists ) {
		std::cout << "\nSeller: '" << InputUsernameOfSeller << "' does not exist! Transaction cancelled. \n";
		return;
	}

	//Find Tickets to the Specified Event, being sold by %UsernameOfSeller%
	bool SellerHasEventTickets = false;  //set true if we can find a ticket object with the seller's name and event name;
	int  MaxTicketsAvailable   = 0;
	int  MaxTicketsAvailable_TicketIndex = 0;  //will be set to index of ticket object with the largest number of tickets
	for(int t = 0;  t<tickets.size();  t++) {
		if( strcmp(tickets[t].eventName, EventName) == 0  && strcmp(tickets[t].username, UsernameOfSeller) == 0 ) {
			SellerHasEventTickets = true;
			if( tickets[t].quantity > MaxTicketsAvailable ) {
				MaxTicketsAvailable = tickets[t].quantity;
				MaxTicketsAvailable_TicketIndex = t;
			}
		}
	}
	if( !SellerHasEventTickets ) {
		std::cout << "\nThe specified seller: '" << UsernameOfSeller << "' does not have tickets to the event: '" << EventName << "'. Transaction cancelled. \n";
		return;
	}
	if( MaxTicketsAvailable == 0 ) {
		std::cout << "\nUnfortunately the specified seller has no more tickets to the event left. Transaction cancelled. \n";
		return;
	}

	//Is buyer trying to buy more tickets than are available?
	if( NumOfTickets > MaxTicketsAvailable ) {
		std::cout << "\nUnfortunately you can not buy " << NumOfTickets << " as there is a max of " << MaxTicketsAvailable << " from the seller, to the requested event. Transaction cancelled. \n";
		std::cout << "Also please note you can not buy tickets within the same session they are sold\n";
		return;
	}
	
	//Does buyer have enough credit to buy the requested number of tickets?
	if( (NumOfTickets * tickets[MaxTicketsAvailable_TicketIndex].price) > accounts[currentAccount_index].credit ) {
		std::cout << "\nYou do not have enough credit to purchase the requested tickets. Transaction cancelled.\n";
		return;
	}

	//PERFORM PURCHASE
	tickets[MaxTicketsAvailable_TicketIndex].quantity -= NumOfTickets;
	accounts[currentAccount_index].credit -= (NumOfTickets * tickets[MaxTicketsAvailable_TicketIndex].price);
	std::cout << "\n Ticket Purchase Successful. \n";

	//construct transaction
	Transaction* BuyTransact = new Transaction();
	BuyTransact->username = accounts[ currentAccount_index ].username;
	BuyTransact->type = accounts[ currentAccount_index ].type;
	BuyTransact->eventName = EventName;
	BuyTransact->code = Transaction::Buy;

	//transactionFile.add( *BuyTransact );	//why doesn't this work

	return;
}
