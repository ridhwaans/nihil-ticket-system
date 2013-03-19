#ifndef assets_Transaction_h
#define assets_Transaction_h

//library headers
//local headers
#include "globals.h"
#include "Account.h"

class Transaction{
public:
	enum Code {
		AddCredit,
		Buy,
		Create,
		Delete,
		Refund,
		Sell ,
		Test};
	
	Code code;
	char* username;
	char* buyer;
	char* seller;
	Account::Type type;
	char* eventName;
	int ticketAmount;
	int ticketPrice;
	int totalCredits;

	Transaction(); //default null constructor
	Transaction( const Transaction&); //copy constructor
	~Transaction();
	Transaction& operator=( const Transaction&);

	char* write(char* dest = buffer);
	char* write_digit( char*, Transaction::Code);
	char* write_username( char*, char*);
	char* write_type( char*, Account::Type);
	char* write_credit( char*, int);
	char* write_ticketAmount( char*, int);
	char* write_ticketPrice( char*, int);
	char* write_token( char*);
private:
};

#endif
