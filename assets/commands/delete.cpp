#include "../commands.h"
#include <cstdio>
#include <algorithm>
#include <vector>
#include <regex>

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


Transaction transaction;
printf("Enter user:");


if (!(std::regex_match (format(getLine()), std::regex("\w")))){
	printf("%s\n", Error::invalidUsernameCharactersError);
}
else if (strcmp(format(getLine()), username))){
	printf( "%s\n", Error::currentAccountDelete);
}
else{
	transaction.username = format(getLine());
//std::vector<std::string>::iterator it = std::find(accounts.begin(), accounts.end(), transaction.username);

std::vector<int>::iterator position = std::find(accounts.begin(), accounts.end(), transaction.username);
if (position != accounts.end()){
    accounts.erase(position);
    currentAccount_index = ((position < currentAccount_index) ? --currentAccount_index : currentAccount_index);
   printf("[Success] User deleted\n");
}
else{
	printf( "%s\n", Error::UserNotFound);
}
}
}

