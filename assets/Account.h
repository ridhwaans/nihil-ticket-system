#ifndef assets_Account_h
#define assets_Account_h

class Account{
public:
	char[username_size] username;
	int credit;
	Type type;
	
	Account( char* line);
	bool isEnd();
	
	enum Type{
		Admin,
		Buy,
		Sell,
		Full };
private:
};

#endif
