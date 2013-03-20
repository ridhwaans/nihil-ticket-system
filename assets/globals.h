#ifndef assets_globals_h
#define assets_globals_h

//library headers
#include <iostream>
#include <fstream>
#include <vector>
//local headers
//just learnt this is a bad idea :(

//forward declarations
class Account;
class Ticket;
class Transaction;
class TransactionFile;

//file path string size
#define filename_size 128
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
	const char* accountsFilename,
	const char* ticketsFilename,
	const char* transactionFilename);
bool deinit();

//session variables
extern int currentAccount_index;
extern Account* currentAccount;

//data definitions
//variables and constants
extern std::vector<Account> accounts;
extern std::vector<Ticket> tickets;
extern std::vector<Ticket> tickets_queue;		//holds tickets that were sold within current session
extern TransactionFile* transactionFile;
//functions
bool loadAccounts( const char* accountsFilename);
bool loadTickets( const char* ticketsFilename);

//input definitions
//variables and constants
#define input_size 256
extern char* input;
#define buffer_size 256
extern char* buffer;
//functions
char* format( char*);
char* trim( char*);
char* lower( char*);
char* format_command( char*);
char* format_name( char*);
char* getLine();

//error definitions
// variables and constants
#define error_size 256
extern bool error;
extern char* error_string;
// functions
void throwError( const char* error_string);
void clearError();

//debug functions
void test_transaction();

#endif



