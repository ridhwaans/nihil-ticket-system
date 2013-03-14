//library includes
#include <cstdio>
//local includes
#include "../Transaction.h"
//override includes
#include "../commands.h"

void command_create(){
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

Transaction transaction;
printf("Enter user name:");
transaction.username = format(getLine());
printf("Enter account type:");
transaction.username = format(getLine());
//override addCredit
printf("Enter credit amount:");
transaction.username = format(getLine());

}
