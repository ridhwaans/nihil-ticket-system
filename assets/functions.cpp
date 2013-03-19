//library includes
#include <cstdio>
#include <ctype.h>
#include <iostream>
#include <cstring>
//local includes
#include "debug.h"
#include "errors.h"
#include "Account.h"
#include "Ticket.h"
#include "Transaction.h"
#include "TransactionFile.h"
//override include
#include "globals.h"

using namespace std;

//initialization functions
bool init(
		const char* accountsFilename,
		const char* ticketsFilename,
		const char* transactionFilename){
	//initialize global variables
	input = new char[input_size+1];
	buffer = new char[buffer_size+1];
	error_string = new char[error_size+1];
	//check filenames are valid?
	if( debug_accounts)
		printf("Accounts Filename:     %s\n",accountsFilename);
	if( debug_tickets)
		printf("Tickets Filename:      %s\n",ticketsFilename);
	if( debug_transactions)
		printf("Transactions Filename: %s\n",transactionFilename);
	//load data files
	bool loadAccounts_success = loadAccounts( accountsFilename);
	if( ! loadAccounts_success) printf("%s\n", error_string);
	bool loadTickets_success = loadTickets( ticketsFilename);
	if( ! loadTickets_success) printf("%s\n", error_string);
	//prepare the transactions file for output
	transactionFile = new TransactionFile( transactionFilename);
	//finish
	return loadAccounts_success && loadTickets_success;
}

bool deinit (){
	delete[] input;
	delete[] buffer;
	delete[] error_string;
	delete transactionFile;
	accounts.clear();
	tickets.clear();
	tickets_queue.clear();
}

//input functions
char* format( char* original){
	//this string defines all the chars we want to ignore
	string whitespaces(" \t\f\v\n\r");
	//defines the next place to insert a char
	int j = 0;
	for(int i = 0; original[i]!='\0'; i++){
			//for every character in the original
		if( whitespaces.find(original[i]) == string::npos){
				//if the character is not in the subset of bad chars
			original[j++] = original[i];}}
				//insert the character into the new location, as well as increment j, so that the next character to be inserted will not overwrite desired data.
	original[j] = '\0';
		//add the null terminator character to ensure other functions, for example print statements, know when the string ends.
	//finish
	return original;
}
char* trim( char* original){
	string ws(" \t\f\v\n\r");
	int i;
	//find first non-whitespace char
	for( i = 0; original[i]!='\0'; i++)
		if( ws.find(original[i]) == string::npos)
			break;
	//left shift by i-j
	if( i > 0){
		int j;
		for( j = 0; original[i]!='\0'; j++){
				original[j] = original[i];
				original[i] = '\0';
				i++;}
		original[j] = '\0';}
	//remove any whitespaces at the end
	for( int i = strlen(original) - 1; i >=0; i--)
		if( ws.find(original[i]) == string::npos)
			break;
		else
			original[i] = '\0';
	//finish
	return original;
}
char* lower( char* original){
	for(int i = 0; original[i]; i++)
		original[i] = (char) tolower(original[i]);
	return original;
}
char* format_command( char* original){
	return lower( format( original));
}
char* format_name( char* original){
	return lower( trim( original));
}


char* getLine(){
	//get input
	cin.getline( input, input_size);
	//return input
	return input;
}

//data load functions
bool loadAccounts( const char* accountsFilename){
	if( debug_accounts) printf("Loading Accounts\n");
	//add default admin
	char admin_name[] = "admin";
	accounts.push_back( Account( admin_name, 0, Account::Admin));
	char asdf_name[] = "sdf";
	accounts.push_back( Account( asdf_name, 0, Account::Admin));
	//try to load file
	std::ifstream accountsFile( accountsFilename);
	if( !accountsFile.good()){
		if( debug_accounts) printf("Loading Accounts Failed\n");
		throwError( Error::AccountsFileNotFoundError);
		return false;}
	//start reading from the file
	Account* newAccount;
	while( accountsFile.good() && ! accountsFile.eof()){
		accountsFile.getline( buffer, buffer_size);
		if( debug_accounts) printf("Parsing %s\n", buffer);
		newAccount = new Account( buffer);
		if( newAccount->isEnd())
			break;
		else
			accounts.push_back( *newAccount);
		delete newAccount;
		if( debug_accounts) printf("Done parsing account\n");}
	//clean up
	if( debug_accounts) printf("%d Accounts loaded from file\n", accounts.size());
	if( debug_accounts) printf("Loading Accounts Complete\n");
	accountsFile.close();
	return true;
}
bool loadTickets( const char* ticketsFilename){
	if( debug_tickets) printf("Loading Tickets\n");
	std::ifstream ticketsFile( ticketsFilename);
	if( ! ticketsFile.good()){
		if( debug_tickets) printf("Loading Tickets Failed\n");
		throwError( Error::TicketsFileNotFoundError);
		return false;}
	Ticket* newTicket;
	while( ticketsFile.good() && ! ticketsFile.eof()){
		ticketsFile.getline( buffer, buffer_size);
		newTicket = new Ticket(buffer);
		if( newTicket->isEnd())
			break;
		else
			tickets.push_back( *newTicket);
		delete newTicket;}
	if( debug_tickets) printf("%d Tickets loaded from file\n", tickets.size());
	if( debug_tickets) printf("Loading Tickets Complete\n");
	ticketsFile.close();
	return true;
}

//error functions
void throwError( const char* newError_string){
	error = true;
	strcpy(error_string, newError_string);
}
void clearError(){
	error = false;
	error_string[0] = '\0';
}

//debug functions
void test_transaction(){
	Transaction t;
	t.code = Transaction::Test;

	strcpy( t.username, "asdf");
	strcpy( t.buyer, "asdf");
	strcpy( t.seller, "asdf");
	strcpy( t.eventName, "asdf");
	t.type = Account::Admin;
	t.ticketAmount = 123;
	t.ticketPrice = 123;
	t.totalCredits = 123;

	transactionFile->add(t);
}