//library includes
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
//local includes
#include "../Account.h"
#include "../errors.h"
#include "../globals.h"
#include "../Transaction.h"
#include "../TransactionFile.h"
//override include
#include "../commands.h"

/**
 * Carries out the necessary operations the system is to
 * perform when the user enters the delete command.
 * This includes validating the user input, verifying
 * the specified username and storing the transaction
 */
void command_delete(){
//basic command pseudocode:
	//get all inputs
		//stop only if input line cannot be parsed
	//validate all inputs
		//e.g. username is in the accounts list
	//if relevant to command, confirm execution of command should proceed
		//only command this applies to is buy
	//prepare relevant objects
		//e.g. new account, new tickets, etc
	//perform internal actions
		//e.g. accounts.add(newAccount) or tickets[4].quantity-=4
	//construct transaction
		//e.g. Transaction transaction(Transaction.create);
			//transaction.username = username;
	//push transaction
	//transactions.add(transaction);
	//clean up
	//terminate
	//return 0;
//end basic command pseudocode

	//Setup
	Transaction transaction;
	transaction.code = Transaction::Delete;

	//get username
	printf("Enter user:\n");
	char* input = format( getLine());

	//check for null, empty input
	if( std::cin.eof() || strlen(input) == 0)
		printf( "%s\n", Error::badParameterError);

	//ensure line is not too long
	if( strlen(input) > username_size){
		printf("%s\n", Error::LineTooLongError);
		return;}

	strcpy( transaction.username, input);

	//check for bad characters
	//change this code block to use regex
	std::string badChars(" \t\v\n\r");
	for( int i = 0; transaction.username[i] != '\0'; i++)
	if( badChars.find(transaction.username[i]) != std::string::npos){
		printf("%s\n", Error::invalidUsernameCharactersError);
		return;}

	//check that user != current user
	if (!strcmp(transaction.username, accounts[currentAccount_index].username)){
		printf("%s\n", Error::currentAccountDelete);
		return;}

	//find the account
	int i;
	for( i = 0; i < accounts.size(); i++){
	if( ! strcmp( transaction.username, accounts[i].username))
		break;}

	//check if we found the username
	if( i == accounts.size()){
		printf("%s\n", Error::UserNotFound);
		return;}

	//double-check that user != current user
	if( i == currentAccount_index){
		printf("%s\n", Error::currentAccountDelete);
		return;}
	//write relevant data to the transaction
	transaction.type = accounts[i].type;
	transaction.totalCredits = accounts[i].credit;

	//done, finish up
	accounts.erase( accounts.begin() + i);
	if( currentAccount_index > i)
		currentAccount_index--;

	transactionFile->add(transaction);
	printf("[Success] User deleted\n");

	return;
}
