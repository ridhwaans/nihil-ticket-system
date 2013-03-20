//lib includes
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
//local includes
#include "debug.h"
#include "errors.h"
#include "globals.h"
//override include
#include "Transaction.h"

//constructors, destructor and operators
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
			//write code
			printf("writing code\n");
			char* curr = write_code( dest, this->code);
			if( error) break;
			printf("writing token\n");
			curr = write_token( curr);
			//write username
			printf("writing username\n");
			curr = write_username( curr, this->username);
			if( error) break;
			printf("writing token\n");
			curr = write_token( curr);
			//write buyer username
			printf("writing buyer username\n");
			curr = write_username( curr, this->buyer);
			if( error) break;
			printf("writing token\n");
			curr = write_token( curr);
			//write seller username
			printf("writing seller username\n");
			curr = write_username( curr, this->seller);
			if( error) break;
			printf("writing token\n");
			curr = write_token( curr);
			//write event name
			printf("writing event name\n");
			curr = write_eventName( curr, this->eventName);
			if( error) break;
			printf("writing token\n");
			curr = write_token( curr);
			//write type
			printf("writing type\n");
			curr = write_type( curr, this->type);
			if( error) break;
			printf("writing token\n");
			curr = write_token( curr);
			//write credit
			printf("writing credit\n");
			curr = write_credit( curr, this->totalCredits);
			if( error) break;
			printf("writing token\n");
			curr = write_token( curr);
			//write ticket amount
			printf("writing ticket amount\n");
			curr = write_ticketAmount( curr, this->ticketAmount);
			if( error) break;
			printf("writing token\n");
			curr = write_token( curr);
			//write ticket price
			printf("writing ticket price\n");
			curr = write_ticketPrice( curr, this->ticketPrice);
			if( error) break;
			//good
			printf("done\n");
			return dest;}

		//01-create, 02-delete, 06-addcredit, 00-end of session
		//(X field 2, U field 15, T field 2, C field 9, total 28 + 3 = 31)
		//XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
		case Transaction::Create:
		case Transaction::Delete:
		case Transaction::AddCredit:{
			//write code
			char* curr = write_code( dest, this->code);
			if( error) break;
			curr = write_token( curr);

			//write username
			curr = write_username( curr, this->username);
			if( error) break;
			curr = write_token( curr);

			//write type
			curr = write_type( curr, this->type);
			if( error) break;
			curr = write_token( curr);

			//write credit
			curr = write_credit( curr, this->totalCredits);
			if( error) break;

			//done
			return dest;}

		//05-refund
		//(X field 2, U field 15, S field 15, C field 9, total 44)
		//XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
		case Transaction::Refund:{
			//write code
			char* curr = write_code( dest, this->code);
			if( error) break;
			curr = write_token( curr);

			//write buyer username
			curr = write_username( curr, this->buyer);
			if( error) break;
			curr = write_token( curr);

			//write seller username
			curr = write_username( curr, this->seller);
			if( error) break;
			curr = write_token( curr);

			//write credit
			curr = write_credit( curr, this->totalCredits);
			if( error) break;

			//done
			return dest;}

		//03-sell, 04-buy
		//(X field 2, E field 19, S field 15, T field 3, P field 6, total 45+4 = 49)
		//XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSSSS_TTT_PPPPPP
		case Transaction::Buy:
		case Transaction::Sell:{
			//write code
			char* curr = write_code( dest, this->code);
			if( error) break;
			curr = write_token( curr);

			//write seller username
			curr = write_username( curr, this->seller);
			if( error) break;
			curr = write_token( curr);

			//write ticket amount
			curr = write_ticketAmount( curr, this->ticketAmount);
			if( error) break;
			curr = write_token( curr);

			//write ticket price
			curr = write_ticketPrice( curr, this->ticketPrice);
			if( error) break;

			//done
			return dest;}

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
char* Transaction::write_code( char* dest, Transaction::Code code){
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
			return dest;}}
	return dest + code_size;
}

char* Transaction::write_username( char* dest, char* name){
	clearError();
	//check for errors errors
	// ensure name is usable
	if( NULL == name)
		throwError( Error::TransactionNullUsername);
	 //ensure name is not empty
	else if( strlen( name) == 0)
		throwError( Error::TransactionNullUsername);
	//ensure name is not too long
	else if( strlen( name) > username_size)
		throwError( Error::TransactionUsernameTooLong);

	//write name
	else {
		sprintf( dest, "%-*s", username_size, name);
		return dest + username_size;}

	//handle error case
	dest[0] = '\0';
	return dest;
}

char* Transaction::write_eventName( char* dest, char* name){
	clearError();
	//check for errors errors
	// ensure name is usable
	if( NULL == name)
		throwError( Error::TransactionNullEventName);
	 // ensure name is not empty
	else if( strlen( name) == 0)
		throwError( Error::TransactionNullEventName);
	// ensure name is not too long
	else if( strlen( name) > eventName_size)
		throwError( Error::TransactionEventNameTooLong);

	//write name
	else {
		sprintf( dest, "%-*s", eventName_size, name);
		return dest + eventName_size;}

	//handle error case
	dest[0] = '\0';
	return dest;
}

char* Transaction::write_type( char* dest, Account::Type type){
	clearError();
	switch( type){
		case Account::Admin:{
			char typeString_admin[] = "AA";
			strcpy( dest, typeString_admin);
			break;}
		case Account::Buy:{
			char typeString_buy[] = "BS";
			strcpy( dest, typeString_buy);
			break;}
		case Account::Sell:{
			char typeString_sell[] = "SS";
			strcpy( dest, typeString_sell);
			break;}
		case Account::Full:{
			char typeString_full[] = "FS";
			strcpy( dest, typeString_full);
			break;}
		default:{
			throwError( Error::TransactionNullAccountType);
			return dest;}}
	return dest + type_size;
}

char* Transaction::write_credit( char* dest, int amount){
	clearError();
	if( 0 <= totalCredits &&
			totalCredits < pow( 10, credit_size - 1)){
		return dest + credit_size;}
	else{
		throwError( Error::TransactionInvalidCredits);
		return dest;}
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
