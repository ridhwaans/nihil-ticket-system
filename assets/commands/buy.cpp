#include "../commands.h"


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
void command_buy(){
	//get parameter
	//check for EOF
	//format input
	//check for null
	//validate parameter
	//if( failed){
		//error message
		//cout<< Error::badParameterError<< endl;
			//replace badParameterError with the specific error
		//return;}
	
	//validate parameter combinations?
	
	//construct transaction
	//Transaction transaction = new Transaction();
	//transaction.code = Transaction.Code.Buy;
	
	//send data to transactionFile
	//transactionFile.add( transaction);
	
	//done, clean up?
	return;}
