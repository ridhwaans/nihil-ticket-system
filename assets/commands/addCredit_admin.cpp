//local includes
#include "../Account.h"
#include "../Transaction.h"

//global includes
#include "../commands.h"
#include "../errors.h"

/**
 * Performs the necessary operations when the admin invokes the addCredit command.
 * This command adds additional credit to addCreditTransactiona specified user's account
 * The admin is asked for the following information, in this order:
 *              1. the user's username
 *		2. the amount of credit to add
 * PRECONDITION:   User must be logged in as an admin, and currentAccount_Index must be accurately set
 */

void command_addCredit_admin(){
int maxCredit = 1000;
int minCredit = 1;
char* creditToUsername;
int addedCredit;
int nameIndex = 0;

//define a new transaction
Transaction addCreditTransaction;

//prompt admin for username
std::cout << "\n Enter the name of the user: \n";
char*InputUsername = format( getline() );
creditToUsername = new char[strlen(InputUsername) + 1];
strcpy(creditToUsername, InputUsername);

//prompt user for credit amount
std::cout << "\n Enter the amount of credit to add: \n";
char* InputCredit = format(getline());
addedCredit = atoi(InputCredit);

//check if user exists
bool UserExists = false;
if (strcmp(creditToUsername, "admin")==0) UserExists=true;

for(int u = 0;  u<accounts.size();  u++) {
		if( strcmp(accounts[u].username, creditToUsername)==0 ) {
			UserExists=true;
			break;
		}
	}
if( !UserExists) {
    printf("%s\n" , Error::UserNotFound);
		return;
	}

//check to see if credit amount is between 0 and 1000
if(addedCredit < minCredit || addedCredit > maxCredit){
    printf("%s\n", Error::TransactionInvalidCredits);
    return;
}

//add credit to the account of the specified user
while (strcmp(accounts[nameIndex], creditToUsername)!= 0){
    nameIndex = nameIndex + 1;
    return nameIndex;
}
accounts[nameIndex].username = accounts[nameIndex];
accounts[nameIndex].credit += (addedCredit);

addCreditTransaction.code = Transaction::AddCredit;
return;
}
