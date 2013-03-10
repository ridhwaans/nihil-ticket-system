#include <cstdio>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include "debug.h"
#include "globals.h"

using namespace std;

//initialization functions
bool init(
		char* accountsFilename,
		char* ticketsFilename,
		char* transactionFilename){
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
	//prepare the transactions file for output
	transactionFile = new TransactionFile( transactionFilename);
	//load data files
	//uses ternary since it should stop if loadAccounts fails
	bool loadAccounts_success = loadAccounts( accountsFilename);
	bool loadTickets_success = loadTickets( ticketsFilename);
	//doing debug checks

	//finish
	return loadAccounts_success && loadTickets_success;
}

bool deinit (){
	delete input;
	delete buffer;
	delete error_string;
	delete transactionFile;
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
char* format_command( char* original){
	format(original);
	for(int i = 0; original[i]; i++)
		original[i] = (char) tolower(original[i]);
	return original;
}
char* trim( char* original){
	string ori_string(original);
	string whitespaces (" \t\f\v\n\r");
	int first = ori_string.find_first_not_of(whitespaces);
	if ( first == std::string::npos)
		first = 0;
	int last = ori_string.find_last_not_of(whitespaces);
	int length = last - first;
	if( length < 0)
		length = 0;
	int i;
	for( i = 0; (i <= length) && (original[first+i] != '\0'); i++)
		original[i] = original[first+i];
	original[first+i] = '\0';
	return original;
}

char* getLine(){
	//get input
	cin.getline( input, input_size);
	//return input
	return input;
}

//data load functions
bool loadAccounts( char* accountsFilename){
	if( debug_accounts) printf("Loading Accounts %d\n",accounts.size());
	std::ifstream accountsFile( accountsFilename);
	if( accountsFile.bad()){
		if( debug_accounts) printf("Loading Accounts Failed\n");
		return false;}
	while( accountsFile.good() && ! accountsFile.eof()){
		accountsFile.getline( buffer, buffer_size);
		Account newAccount (buffer);
		if( newAccount.isEnd())
			break;
		else
			accounts.push_back( newAccount);}
	if( debug_accounts) printf("%d Accounts loaded from file\n", accounts.size());
	if( debug_accounts) printf("Loading Accounts Complete\n");
	return true;
}
bool loadTickets( char* ticketsFilename){
	if( debug_tickets) printf("Loading Tickets\n");
	std::ifstream ticketsFile( ticketsFilename);
	if( ticketsFile.bad()){
		if( debug_tickets) printf("Loading Tickets Failed\n");
		return false;}
	while( ticketsFile.good() && ! ticketsFile.eof()){
		ticketsFile.getline( buffer, buffer_size);
		Ticket newTicket (buffer);
		if( newTicket.isEnd())
			break;
		else
			tickets.push_back( newTicket);}
	if( debug_tickets) printf("%d Tickets loaded from file\n", tickets.size());
	if( debug_tickets) printf("Loading Tickets Complete\n");
	return true;
}

//error functions
void throwError( const char* newError_string){
	error = true;
	strcpy(error_string, newError_string);
}
void clearError(){
	error = false;
}
