#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include "nts-lib.h"

#define AccountsFilename_ArgIndex 1
#define TicketsFilename_ArgIndex 2
#define TransactionFilename_ArgIndex 3
const char AccountsFilename_default[] = "resources/data.cua";
const char TicketsFilename_default[] = "resources/data.atf";
const char TransactionFilename_default[] = "output.dtf";

int main( int argc, char* argv[], char *envp[]) {
	//load
	//do filename validation!
	init(
		argc > AccountsFilename_ArgIndex ?
			argv[AccountsFilename_ArgIndex] :
			AccountsFilename_default,
		argc > TicketsFilename_ArgIndex ?
			argv[TicketsFilename_ArgIndex] :
			TicketsFilename_default,
		argc > TransactionFilename_ArgIndex ?
			argv[TransactionFilename_ArgIndex] :
			TransactionFilename_default);
	//welcome message
	printf("Welcome to Ticket sales\n");
	
	//enter shell loop
	while( true){
		//print prompt
		if( promptEnabled) printf("> ");
		//get command and format it ( to lower case)
		char* command = format_command(getLine());
		//exit on end of input
		if( std::cin.eof()){
			if( promptEnabled) printf("\n");
			break;}
		//get input again if no input
		else if( strlen( command) == 0)
			continue;
		//exit with quit command
		else if( ! strcmp( command, "quit"))
			break;
		//do not attempt to enter login session if command is not 'login'
		else if( strcmp( command, "login")){
			printf( "%s\n", Error::LoginRequiredError);
			continue;}
		else ; //attempt to enter login session
		
		//get username and do validation
		//prompt
		printf( "Please enter your username to login\n");
		//get username
		char* username = format(getLine());
		//check for null input
		if( std::cin.eof())
			break;
		else if( strlen( command) == 0){
			printf( "%s\n", Error::InvalidLoginError);
			continue;}
		//username validation
		currentAccount_index = -1;
		for( int i = 0; i < accounts.size(); i++)
			if( ! strcmp( accounts[i].username, username)){
				currentAccount_index = i;
				break;}
		//check username was not found
		if( currentAccount_index < 0){
			printf( "%s\n", Error::InvalidLoginError);
			continue;}
		//username valid - continue to enter login session
		currentAccount = &accounts[currentAccount_index];
		printf( "[Success] Logged in as \'%s\'\n",
			currentAccount->username);
		
		//enter login session
		while( true){
			//prompt
			if( promptEnabled) printf("> ");
			//get command
			command = format_command(getLine());
			//if EOF, exit cleanly with error flag
			if( std::cin.eof()){
				deinit();
				if( promptEnabled) printf("\n");
				return 1;}
			
			//check for null input
			if( strlen( command) == 0);
			//select command
			else if( !strcmp( command, "addCredit"))
				if( true) //if user is admin, call special addCredit
					command_addCredit_admin();
				else
					command_addCredit();
			else if( !strcmp( command, "buy"))
				command_buy();
			else if( !strcmp( command, "create"))
				command_create();
			else if( !strcmp( command, "delete"))
				command_delete();
			else if( !strcmp( command, "refund"))
				command_refund();
			else if( !strcmp( command, "sell"))
				command_sell();
			//check for logout
			else if( !strcmp( command, "logout"))
				break;
			else // unrecognized command
				printf( "%s\n", Error::UnrecognizedCommandError);}
		printf("Logged out\n");
		//push dtf to file
		transactionFile->commit();}
	//clean up and exit
	deinit();
	return 0;
}
