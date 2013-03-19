#include <cstdio>
#include <iostream>
#include <string.h>
#include "Transaction.h"
#include "globals.h"
#include "errors.h"

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
Transaction::Transaction( const Transaction& other){
	username = new char[username_size+1];
	eventName = new char[eventName_size+1];
	buyer = new char[username_size+1];
	seller = new char[username_size+1];
	*this = other;
}
Transaction::~Transaction(){
	delete[] username;
	delete[] eventName;
	delete[] buyer;
	delete[] seller;
}
Transaction& Transaction::operator=( const Transaction& other){
	strcpy( username, other.username);
	strcpy( buyer, other.buyer);
	strcpy( seller, other.seller);
	strcpy( eventName, other.eventName);
	code = other.code;
	type = other.type;
	ticketAmount = other.ticketAmount;
	ticketPrice = other.ticketPrice;
	totalCredits = other.totalCredits;
}

/**
 * Determines the transaction code based on the enumeration value received
 *
 * @return buffer after transaction text line is composed and concatenated for file write
 **/
char* Transaction::write(char* dest){
	//prepare the code

	switch (this->code){
		case Transaction::Test:{
			char* curr = write_digit( dest, this->code);
			if( error) break;
			curr = write_token( curr);
			curr = write_username( curr, this->username);
			if( error) break;
			//good
			return dest;}

		//01-create, 02-delete, 06-addcredit, 00-end of session
		//(X field 2, U field 15, T field 2, C field 9, total 28 + 3 = 31)
		//XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
		case Transaction::Create:
		case Transaction::Delete:
		case Transaction::AddCredit:{
			//printf("Creating a Create, Delete, or AddCredit transaction\n");
			//check the username field
			/*for( i = 0; this->username[i] != '\0'; i++)
				current[i] = this->username[i];
			for( i; i < username_size; i++)
				current[i] = filler;
			current += username_size;
			current[0] = token;
			current += 1;*/

			//prepare the account type field

			//check the credits field
			//"%02s %-15s %2s %06d.%02d" sample format
			//write the fields
			}

		//05-refund
		//(X field 2, U field 15, S field 15, C field 9, total 44)
		//XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
		case Transaction::Refund:{
			}//break;}

		//03-sell, 04-buy
		//(X field 2, E field 19, S field 15, T field 3, P field 6, total 45+4 = 49)
		//XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSSSS_TTT_PPPPPP
		case Transaction::Buy:
		case Transaction::Sell:{
			}//break;}

		//manage the error case
		default:{
			printf("%s\n", Error::TransactionInvalidCode);
			break;}}
	//handle the error case
	printf("%s\n", error_string);
	dest[0] = '\0';
	printf("transaction: {%s}\n", dest);
	return buffer;
}

/**
 * Determines the transaction code based on the enumeration value received
 *
 * @param transaction_code
 * @return
 **/
char* Transaction::write_digit( char* dest, Transaction::Code code){
	clearError();
	switch( code){
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
		case Transaction::Test:{
			char digit[] = "00";
			strcpy( dest, digit);
			break;}
		default:{
			throwError( Error::TransactionNullCode);
			break;}}
	return dest + code_size;
}

char* Transaction::write_username( char* dest, char* name){
	clearError();
	if( NULL == name)//ensure name is usable
		throwError( Error::TransactionNullUsername);
	else if( strlen( name) == 0) //ensure name is not ""
		throwError( Error::TransactionNullUsername);
	else if( strlen( name) > username_size) //ensure name is not too long
		throwError( Error::TransactionUsernameTooLong);
	else { //write name
		sprintf( dest, "%-*s", username_size, name);
		return dest + username_size;}
	dest[0] = '\0';
	return dest;
}

char* Transaction::write_type( char* dest, Account::Type type){
	clearError();
	/*switch( type){
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
			return NULL;}}*/
	return dest;
}

char* Transaction::write_credit( char* dest, int amount){
	clearError();
	/*if( totalCredits >= 100000000 ||
			totalCredits <0){
		printf("%s\n", Error::TransactionInvalidCredits);
		delete[] typeString;
		return NULL;}*/
	return dest;
}

char* Transaction::write_ticketAmount( char* dest, int amount){
	clearError();
	return dest;
}

char* Transaction::write_ticketPrice( char* dest, int amount){
	clearError();
	return dest;
}

char* Transaction::write_token( char* dest){
	clearError();
	dest[0] = token;
	dest[1] = '\0';
	return dest + 1;
}
