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
		Sell };
	
	Code code;
	char* username;
	Account::Type type;
	char* eventName;
	int ticketAmount;
	int ticketPrice;
	int totalCredits;
	char* buyer;
	char* seller;

	Transaction(); //default null constructor
	~Transaction();

	char* write(char* dest = buffer);
	char* transaction_digit( Transaction::Code, char*);
private:
};

#endif
