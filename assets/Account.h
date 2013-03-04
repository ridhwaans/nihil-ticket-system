#ifndef assets_Account_h
#define assets_Account_h

//library headers
//local headers

class Account {
public:
	enum Type {
		Admin,
		Buy,
		Sell,
		Full };
	
	char* username;
	int credit;
	Type type;
	
	Account( char* line);
	Account( char* username, int credit, Type type);
	
	bool isEnd();
private:
};

#endif
