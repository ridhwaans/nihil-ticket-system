#include <cstdio>
#include <iostream>
#include <string.h>
#include "Transaction.h"
#include "globals.h"
#include "errors.h"

/**
 * Determines the transaction code based on the enumeration value received
 *
 * @param transaction_code
 * @return
 **/
char* Transaction::transaction_digit(Code transaction_code, char* dest) {
	switch( transaction_code){
		case Transaction::Create:{
			char digit[] = "01";
			strcpy( dest, digit);
			break;}
		case Transaction::Delete:{
			char digit[] = "02";
			strcpy( dest, digit);
			break;}
		case Transaction::Sell:{
			char digit[] = "03";
			strcpy( dest, digit);
			break;}
		case Transaction::Buy:{
			char digit[] = "04";
			strcpy( dest, digit);
			break;}
		case Transaction::Refund:{
			char digit[] = "05";
			strcpy( dest, digit);
			break;}
		case Transaction::AddCredit:{
			char digit[] = "06";
			strcpy( dest, digit);
			break;}
		default:{
			char digit[] = "00";
			strcpy( dest, digit);
			break;}}
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
char* Transaction::write(char* dest){
	//prepare the code
	char* codeString = new char[ code_size + 1];
	transaction_digit( this->code, codeString);

	switch (this->code){
		//01-create, 02-delete, 06-addcredit, 00-end of session
		//(X field 2, U field 15, T field 2, C field 9, total 28 + 3 = 31)
		//XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
		case Transaction::Create:
		case Transaction::Delete:
		case Transaction::AddCredit:{
			//check the username field
			if( this->username == NULL){
				printf("%s\n", Error::TransactionNullUsername);
				return NULL;}
			/*for( i = 0; this->username[i] != '\0'; i++)
				current[i] = this->username[i];
			for( i; i < username_size; i++)
				current[i] = filler;
			current += username_size;
			current[0] = token;
			current += 1;*/

			//prepare the account type field
			char* typeString = new char[type_size + 1];
			switch( type){
				case Account::Admin:{
					char typeString_admin[] = "AA";
					strcpy( typeString, typeString_admin);
					break;}
				case Account::Buy:{
					char typeString_buy[] = "BS";
					strcpy( typeString, typeString_buy);
					break;}
				case Account::Sell:{
					char typeString_sell[] = "SS";
					strcpy( typeString, typeString_sell);
					break;}
				case Account::Full:{
					char typeString_full[] = "FS";
					strcpy( typeString, typeString_full);
					break;}
				default:{
					printf("%s\n", Error::TransactionNullAccountType);
					delete[] typeString;
					delete[] codeString;
					return NULL;}}

			//check the credits field
			if( totalCredits >= 100000000 ||
					totalCredits <0){
				printf("%s\n", Error::TransactionInvalidCredits);
				delete[] typeString;
				delete[] codeString;
				return NULL;}

			//"%02s %-15s %2s %06d.%02d" sample format
			//write the fields
			sprintf( buffer,
				"%0*s%c%-*s%c%*s%c%0*d.%02d",
				code_size, codeString, token,
				username_size, this->username, token,
				type_size, typeString, token,
				credit_size - 3, this->totalCredits / 100,
				this->totalCredits % 100);
			delete[] typeString;
			delete[] codeString;
			return buffer;}

		//05-refund
		//(X field 2, U field 15, S field 15, C field 9, total 44)
		//XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
		case Transaction::Refund:{
			break;}

		//03-sell, 04-buy
		//(X field 2, E field 19, S field 15, T field 3, P field 6, total 45+4 = 49)
		//XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSSSS_TTT_PPPPPP
		case Transaction::Buy:
		case Transaction::Sell:{
			break;}

		//manage the error case
		default:{
			break;}}
	//clean up and finish
	delete[] codeString;
	return NULL;
}