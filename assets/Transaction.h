
class Transaction{
public:
	Code code;
	char[username_size] 

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
