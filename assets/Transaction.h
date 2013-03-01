
class Transaction{
public:
	Code code;
	char[username_size] username;
	Account.Type type;
	char[eventName_size] eventName;
	int ticketAmount;
	int ticketPrice;
	int totalCredits;
	char[username_size] buyer;
	char[usrename_size] seller;

	Transaction();
	char* format();
	
	enum Code{
		AddCredit,
		Buy,
		Create,
		Delete,
		Refund,
		Sell };
private:
};
