#ifndef assets_Account_h
#define assets_Account_h

//library headers
//local headers

/** @class Account
 * @brief The C representation of an account.
 **/
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
	Account( const Account& other);
	Account( char* username, int credit, Type type);
	~Account();
	
	Account& operator=( const Account& other);

	bool isEnd();
private:
};

#endif
