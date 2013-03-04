#ifndef assets_Transaction_h
#define assets_Transaction_h

//library headers
//local headers
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
	
	char* username;
	Account::Type type;
	char* eventName;
	int ticketAmount;
	int ticketPrice;
	int totalCredits;
	char* buyer;
	char* seller;

	Transaction();
	char* write();
private:
};

#endif
