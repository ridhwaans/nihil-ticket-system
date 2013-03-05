#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include "nts-lib.h"

#define AccountsFilenameArgIndex 0
#define TicketsFilenameArgIndex 1
#define TransactionFilenameArgIndex 2

int main( int argc, char *argv[], char *envp[]) {
	//load
	init(
		argv[AccountsFilenameArgIndex],
		argv[TicketsFilenameArgIndex],
		argv[TransactionFilenameArgIndex]);
	//welcome message
	printf("Welcome to Ticket sales\n");
	
	//enter shell loop
	while( true){
		//get command and format it ( to lower case)
		char* command = format_command(getLine());
		//exit on end of input
		if( std::cin.eof())
			break;
		//get input again if no input
		else if( strlen( command) == 0)
			continue;
		//exit with quit command
		else if( !strcmp( command, "quit"))
			break;
		//do not attempt to enter login session if command \
			is not 'login'
		else if( strcmp( command, "login")){
			printf( "%s\n", Error::LoginRequiredError);
			continue;}
		else ; //attempt to enter login session
		
		//get username and do validation
		//prompt
		printf( "Please enter your username to login\n");
		//get username
		char* username = getLine();
		//check for null input
		if( std::cin.eof())
			break;
		else if( strlen( command) == 0){
			printf( "%s\n", Error::InvalidLoginError);
			continue;}
		//username validation
		//implement this properly when Account and loadAccounts\
			are completed
		printf( "[Success] Logged in as ‘admin’");
		
		//enter login session
		while( true){
			//prompt? (future feature)
			//get command
			command = format_command(getLine());
			//if EOF, exit cleanly with error flag
			if( std::cin.eof()){
				deinit();
				return 1;}
			
			//check for null input
			if( strlen( command) == 0);
			//select command
			else if( !strcmp( command, "create"))
				command_create();
			//check for logout
			else if( !strcmp( command, "logout"))
				break;
			else // unrecognized command
				printf( "%s\n", Error::UnrecognizedCommandError);}
		//push dtf to file
		transactionFile->update();}
	//clean up and exit
	deinit();
	return 0;
}
