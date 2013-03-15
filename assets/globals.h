#ifndef assets_globals_h
#define assets_globals_h

//library headers
#include <iostream>
#include <fstream>
#include <vector>
//local headers
#include "Ticket.h"
#include "Transaction.h"
#include "TransactionFile.h"

//forward declarations
class Account;
class Ticket;

//transaction string sizes
#define	code_size 		2
//account string sizes
#define	username_size 	15
#define	credit_size 	9
#define	type_size 		2
//ticket string sizes
#define	eventName_size 19
#define	quantity_size 	3
#define	price_size 		6
//string format chars
#define	token 			' '
#define	filler 			' '


//initialization functions
bool init(
	char* accountsFilename,
	char* ticketsFilename,
	char* transactionFilename);
bool deinit();

//session variables
extern int currentAccount_index;
extern Account* currentAccount;

//data definitions
//variables and constants
extern std::vector<Account> accounts;
extern std::vector<Ticket> tickets;
extern TransactionFile* transactionFile;
//functions
bool loadAccounts( char* accountsFilename);
bool loadTickets( char* ticketsFilename);

//input definitions
//variables and constants
#define input_size 256
extern char* input;
#define buffer_size 256
extern char* buffer;
//functions
char* format( char* original);
char* format_command( char* original);
char* trim( char* original);
char* getLine();

//error definitions
//variables and constants
#define error_size 256
extern bool error;
extern char* error_string;
//functions
void throwError( const char* error_string);
void clearError();

#endif
