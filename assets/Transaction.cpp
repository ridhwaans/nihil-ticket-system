#include "Transaction.h"
#include "globals.h"
#include <iostream>
#include <string.h>
using namespace std;


/**
 * Determines the transaction code based on the enumeration value received
 *
 * @param transaction_code
 * @return
 **/
char* Transaction::transaction_digit(Code transaction_code, char* dest) {
	if( transaction_code == Transaction::Create){
		char digit[] = "01";
		strcpy( dest, digit);
	}
	else if( transaction_code == Transaction::Delete){
		char digit[] = "02";
		strcpy( dest, digit);
	}
	else if( transaction_code == Transaction::Sell){
		char digit[] = "03";
		strcpy( dest, digit);
	}
	else if( transaction_code == Transaction::Buy){
		char digit[] = "04";
		strcpy( dest, digit);
	}
	else if( transaction_code == Transaction::Refund){
		char digit[] = "05";
		strcpy( dest, digit);
	}
	else if( transaction_code == Transaction::AddCredit){
		char digit[] = "06";
		strcpy( dest, digit);
	}
	return dest;
}

/**
 * Determines the transaction code based on the enumeration value received
 *
 * @ Transaction code field value XX
 **/

Transaction::Transaction(){
	username = new char[username_size+1];
	eventName = new char[eventName_size+1];
	buyer = new char[username_size+1];
	seller = new char[username_size+1];
}
Transaction::~Transaction(){
	delete[] this->username;
	delete[] this->eventName;
	delete[] this->buyer;
	delete[] this->seller;
}

/**
 * Determines the transaction code based on the enumeration value received
 *
 * @return buffer after transaction text line is composed and concatenated for file write
 **/
/*char* Transaction::write(){
	//write the code
	char* current = transaction_digit( this->code, buffer);
	current += 2;
	//write the token
	current[0] = token;
	current += 1;

	switch (this->code){
	//01-create, 02-delete, 06-addcredit, 00-end of session
	//(X field 2, U field 15, T field 2, C field 9, total 28 + 3 = 31)
	//XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
		case Transaction::Create:
		case Transaction::Delete:
		case Transaction::AddCredit:
			//write the username field
			if( this->username != NULL)
					//is there a better way to check for nul?
				strcpy( this->username, current);
				for( int i = 0; i < username_size; i++)
					current[i] = filler;
				current += username_size;
				current[0] = token;
				current += 1;
			break;
	//05-refund
	//(X field 2, U field 15, S field 15, C field 9, total 44)
	//XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
		case 5:
	//03-sell, 04-buy
	//(X field 2, E field 19, S field 15, T field 3, P field 6, total 45+4 = 49)
	//XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSSSS_TTT_PPPPPP
	return buffer;
}*/