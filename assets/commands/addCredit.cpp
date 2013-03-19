//lib includes
#include <cstdlib>
//local includes
#include "../Account.h"
#include "../errors.h"
#include "../Transaction.h"
//override includes
#include "../commands.h"

/**
 * Performs the necessary operations when the user invokes the addCredit command.
 * This command adds additional credit to the current user's account
 * The user is asked for the following information, in this order:
 *		1. the amount of credit to add
 * PRECONDITION:   User must be logged in, and currentAccount_Index must be accurately set
 */

void command_addCredit(){
int maxCredit = 1000;
int minCredit = 1;
char* creditToUsername;
int addedCredit;
int nameIndex = 0;

//define a new transaction
Transaction addCreditTransaction;

//prompt user for credit amount
std::cout << "\n Enter the amount of credit to add: \n";
char* InputCredit = format(getLine());
addedCredit = atoi(InputCredit);

//check to see if credit amount is between 0 and 1000
if(addedCredit < minCredit || addedCredit > maxCredit){
    printf("%s\n", Error::TransactionInvalidCredits);
    return;
}

//add credit to the account of the specified user
accounts[currentAccount_index].credit += (addedCredit);
addCreditTransaction.code = Transaction::AddCredit;
return;
}

