class Account{
public:
	char[username_size] username;
	int credit;
	Type type;
	
	Account( char* line);
	
	enum Type{
		Admin,
		Buy,
		Sell,
		Full };
private:
};
