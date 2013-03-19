//lib includes
#include <cstdlib>
#include <cstring>
//local includes
#include "../Account.h"
#include "../errors.h"
#include "../Transaction.h"

//override include
#include "../commands.h"

/**
 * Performs the necessary operations when the admin invokes the refund command.
 * This command refunds a specified amount of money from one user(the seller)
 * to another specified user (the buyer).
 * The admin is asked for the following information, in this order:
 *		1 the buyer's username
 *		2 the seller's username
 *		3 the amount of credit to refund
 *              4 confirmation to execute the command
 *
 * PRECONDITION:   User must be logged in as an admin, and currentAccount_Index must be accurately set
 */

void command_refund(){
    char* nameOfBuyer;
    char* nameOfSeller;
    int refundAmount;
    char* confirm;//search for buyer name in the account index
    int maxRefund = 999999;
    int minRefund = 1;
    int buyer_index = 0;
    int seller_index = 0;
    
Transaction refundTransaction;

//Get the username of the refundee
std::cout << "\n Please enter the username of the refundee: \n";
char* InputNameOfBuyer = format_name_name(getLine());
nameOfBuyer = new char(strlen(InputNameOfBuyer) + 1);
strcpy(nameOfBuyer, InputNameOfBuyer);

//Get the username of the refunder
std::cout << "\n Please enter the username of the refunder: \n";
char* InputNameOfSeller = format_name(getLine());
nameOfSeller = new char(strlen(InputNameOfSeller) + 1);
strcpy(nameOfSeller, InputNameOfSeller);

//Get the amount of credit to give to the refundee
std::cout << "\n Enter the amount of credit to refund: \n";
char* InputRefundAmount = format_name_name(getLine());
refundAmount = atoi(InputRefundAmount);

//Determine if buyer username exists
bool BuyerExists = false;
if (strcmp(nameOfBuyer, "admin")==0) BuyerExists=true;

for(int u = 0;  u<accounts.size();  u++) {
		if( strcmp(accounts[u].username, nameOfBuyer)==0 ) {
			BuyerExists = true;
			break;
		}
	}
if( !BuyerExists) {
		printf("%s\n" , Error::UserNotFound);
		return;
	}

//Determine if seller username exists
bool SellerExists = false;
if (strcmp(nameOfBuyer, "admin")==0) BuyerExists=true;
for(int u = 0;  u<accounts.size();  u++) {
		if( strcmp(accounts[u].username, nameOfBuyer)==0 ) {
			SellerExists = true;
			break;
		}
	}
if( !SellerExists) {
		printf("%s\n" , Error::UserNotFound);
		return;
	}
//check to see if buyer and seller are the same person
if(nameOfBuyer == nameOfSeller){
     printf("%s\n" , Error::sameUserError);
     return;
}

//check to see if credit amount is between 0 and max user credit
if(refundAmount < minRefund || refundAmount > maxRefund){
    printf("%s\n", Error::TransactionInvalidCredits);
    return;
}

//search for buyer name in the account index
if(refundAmount < minRefund || refundAmount > maxRefund){
    printf("%s\n", Error::TransactionInvalidCredits);
    return;
}
while (strcmp(accounts[buyer_index].username, nameOfBuyer)!= 0){
	buyer_index++;
}

//search for seller name in the account index
while (strcmp(accounts[seller_index].username, nameOfSeller)!= 0){
    seller_index ++;
}
//check that seller has enough credits
if (accounts[seller_index] < refundAmount){
      printf("%s\n" , Error::insufficientCreditError);
      return;
}

//add funds to buyer
accounts[buyer_index].credit += (refundAmount);
//subtract funds from seller
accounts[seller_index].credit -= (refundAmount);

refundTransaction.code = Transaction::Refund;
return;
}

