#include "../commands.h"
#include "../Account.h"
#include "../Ticket.h"
#include "../Transaction.h"
#include "../TransactionFile.h"
#include "../debug.h"

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

	//Show user a listing of all tickets available
	if( debug_buy ) {
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
		std::cout <<   "\n ---------Sold within current session (not available for purchase)-----\n";
		for(int i = 0;  i<tickets_queue.size();  i++) {
			std::cout << " " << tickets_queue[i].username;
			for(int j = 0;  j<16-strlen(tickets_queue[i].username); j++)  std::cout << " ";
			std::cout << tickets_queue[i].eventName;
			for(int j = 0;  j<20-strlen(tickets_queue[i].eventName); j++) std::cout << " ";
			std::cout << tickets_queue[i].quantity;
			for(int j = 0;  j<14;  j++) std::cout << " ";
			std::cout << tickets_queue[i].price << "\n";
		}
		std::cout <<     " ----------------------------------------------------------------------\n";
		std::cout <<     "                    YOUR CREDIT BALANCE: " << accounts[currentAccount_index].credit << " (CENTS)\n\n";
	}

	//Get event title
	bool ValidEventName = true;
	std::cout << "\nPlease enter the event of which to buy tickets for:\n";
	char* InputEventTitle = format( getLine() );
	if( std::cin.eof() ) {
		std::cout << "\n" << Error::badParameterError << "\n";
		return;
	}
	EventName = new char[strlen(InputEventTitle) + 1];
	strcpy(EventName, (const char*) InputEventTitle);
	if( strlen(EventName) == 0 || strlen(EventName) > eventName_size ) ValidEventName = false;
	for(int i = 0;  i<strlen(EventName);  i++)
		if( isalnum(EventName[i]) == 0 && EventName[i] != '-' && EventName[i] != '_') //if a character is not alphanumeric, and its not a - or _ its invalid
			ValidEventName = false;
	if( !ValidEventName ) {
		std::cout << "\n" << Error::badEventStringError << "\n";
		return;
	}			

	//Get Number of tickets to buy
	bool ValidNumOfTickets = true;
   std::cout << "\nPlease enter the number of tickets to buy:\n";
	char* InputNumOfTicket = format( getLine() );
	if( std::cin.eof() ) {
		std::cout << "\n" << Error::badParameterError << "\n";
		return;
	}
	NumOfTickets = atoi( InputNumOfTicket );
	if( strlen(InputNumOfTicket) == 0 || NumOfTickets <= 0 || NumOfTickets >= 1000 )	ValidNumOfTickets = false;
	if( !ValidNumOfTickets ) {
		std::cout << "\n" << Error::BuyInvalidNumberOfTickets << "\n";
		return;
	}
	//Note: other checking based on account type and/or whether buying from their 
	//own tickets will be checked later

	//Get username of seller to buy from
	std::cout << "\nPlease enter the username of whom to purchase the tickets from\n";
	char* InputUsernameOfSeller = format( getLine() );
	if( std::cin.eof() ) {
		std::cout << "\n" << Error::badParameterError << "\n";
		return;
	}
	UsernameOfSeller = new char[ strlen(InputUsernameOfSeller) + 1 ];
	strcpy(UsernameOfSeller, InputUsernameOfSeller);
	if( strlen(UsernameOfSeller) == 0 || strlen(UsernameOfSeller) > username_size ) {
		std::cout << "\n" << Error::badUsernameStringError << "\n";
		return;
	}

	//Show confirmation to user
	std::cout << "\nSummary:";
	std::cout << "\nEvent: " << EventName;
	std::cout << "\nNumber of tickets: " << NumOfTickets;
	std::cout << "\nSeller: " <<  UsernameOfSeller;
	std::cout << "\nConfirm [Yes/No]\n";

	//Get users response to confirmation message
	char* ConfirmResponse = format( getLine() );
	if( std::cin.eof() ) {
		std::cout << "\n" << Error::badParameterError << "\n";
		return;
	}
	if( strcmp( format_command(ConfirmResponse), "no" ) == 0 ) {
		std::cout << "\nBuy transaction cancelled.\n";
		return;
	} else if( strcmp( format_command(ConfirmResponse), "yes" ) != 0 ) {
		std::cout << "\nInvalid response, buy transaction cancelled\n";
		return;
	}
	
	//Check if seller exists
	bool SellerExists = false; //will be set to true if seller is found
	if( strcmp( UsernameOfSeller, "admin" ) == 0 ) SellerExists = true;   //there always exists the built in account 'admin'
	if( strcmp( UsernameOfSeller, currentAccount->username ) == 0 ) SellerExists = true; //buying from self
	for(int u = 0;  u<accounts.size();  u++) {
		if( strcmp(accounts[u].username, UsernameOfSeller)==0 ) {
			SellerExists = true;
			break;
		}
	}
	if( !SellerExists ) {
		std::cout << "\n" << Error::BuySellerDoesNotExist << "\n";
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
	if( !SellerHasEventTickets || MaxTicketsAvailable == 0 ) {
		std::cout << "\n[Fail] The specified seller: '" << UsernameOfSeller << "' does not have tickets to the event: '" << EventName << "'. Transaction cancelled. \n";
		return;
	}

	//Ensure current user is not trying to buy more tickets than they are allowed to buy in one session (based on user type, and if buying their own tickets)
	if( strcmp(currentAccount->username,  UsernameOfSeller) != 0 ) {   //user is not buying their own tickets
		if( currentAccount->type == Account::Sell || (currentAccount->type != Account::Admin && NumOfTickets > 4) ) {
			std::cout << Error::BuyUserTicketLimitExceeded;
			return;
		}
	}

	//Is buyer trying to buy more tickets than are available?
	if( NumOfTickets > MaxTicketsAvailable ) {
		std::cout << "\n[Fail] Unfortunately you can not buy " << NumOfTickets << " as there is a max of " << MaxTicketsAvailable << " from the seller, to the requested event. \n";
		return;
	}
	
	//Does buyer have enough credit to buy the requested number of tickets?
	if( (NumOfTickets * tickets[MaxTicketsAvailable_TicketIndex].price) > accounts[currentAccount_index].credit ) {
		std::cout << "\n" << Error::BuyInsufficientCredit << "\n";
		return;
	}
		
	//PERFORM PURCHASE
	tickets[MaxTicketsAvailable_TicketIndex].quantity -= NumOfTickets;
	accounts[currentAccount_index].credit -= (NumOfTickets * tickets[MaxTicketsAvailable_TicketIndex].price);
	std::cout << "\n[Success] Tickets bought\n";

	//construct transaction
	Transaction BuyTransact;
	BuyTransact.username = accounts[ currentAccount_index ].username;
	BuyTransact.type = accounts[ currentAccount_index ].type;
	BuyTransact.eventName = EventName;
	BuyTransact.code = Transaction::Buy;

	transactionFile->add( BuyTransact );

	return;
}


