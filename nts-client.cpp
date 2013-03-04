#include "nts-lib.h"

#define AccountsFilenameArgIndex 0
#define TicketsFilenameArgIndex 1
#define TransactionFilenameArgIndex 2

int main( int argc, char *argv[], char *envp[]) {
	//load
	bool exit = false;
	//load user accounts file to this:
	//load available tickets file
	transactionFile = new TransactionFile(argv[TransactionFilenameArgIndex]);
	while( !exit){
		//prompt
		//get command
		//check for EOF
		//format input
		//check for null input
		//check for end command
		//check for login command
		
		//prompt
		//get username
		//format input
		//check for null input
		//username validation
		bool logout = false;
		while( !logout){
			//prompt
			//get command
			//auto-logout if EOF
			//format input
			//check for null input
			if( strcmp(input,"buy") == 0)
				command_buy();
			else if( strcmp(input,"logout") == 0)
				logout= true;
			else;
				//error message
				}
		transactionFile->update();}
	
	//clean up
	return 0;
}
