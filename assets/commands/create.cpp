//library includes
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>

//local includes
#include "../errors.h"
#include "../Transaction.h"
#include "../TransactionFile.h"
//override includes
#include "../commands.h"

/**
 * Returns a corresponding enum value based on the user type code
 * @param usertype two character code input
 * @return 		   one of four enum values: Admin, Buy, Sell or Full
 */
Account::Type usertype_to_enum(char* usertype) {
	switch(usertype[0]){
		case 'A': return Account::Admin;
		case 'B': return Account::Buy;
		case 'S': return Account::Sell;
		case 'F': return Account::Full;}}

/**
 * Carries out the necessary operations the system is to
 * perform when the user initiates the create transaction.
 * This includes getting and formatting all user input parameters,
 * performing internal actions, constructing and pushing transaction
 */
void command_create(){
//basic command pseudocode:
	//get all inputs
		//stop only if input line cannot be parsed
	//validate all inputs
		//e.g. username is in the accounts list
	//if relevant to command, confirm execution of command should proceed
		//only command this applies to is buy
	//prepare relevant objects
		//e.g. new account, new tickets, etc
	//perform internal actions
		//e.g. accounts.add(newAccount) or tickets[4].quantity-=4
	//construct transaction
		//e.g. Transaction transaction(Transaction.create);
			//transaction.username = username;
	//push transaction
	//transactions.add(transaction);
	//clean up
	//terminate
	//return 0;
	//end basic command pseudocode

	Transaction transaction;
	transaction.code = Transaction::Create;

	if (accounts[currentAccount_index].type != Account::Admin){
		printf( "%s\n", Error::unprivilegedUserError);
		return;}

	printf("Enter user name:\n");
	char* new_username = format(getLine());

	//check for null, empty input
	if( std::cin.eof() || strlen(new_username) == 0){
		printf( "%s\n", Error::badParameterError);
		return;}
	//check if input > required size
	if( strlen(new_username) > username_size){
		printf("%s\n", Error::LineTooLongError);
		return;}

	strcpy( transaction.username, new_username);

	//check for bad characters
	std::string badChars(" \t\f\v\n\r");
	for( int i = 0; transaction.username[i] != '\0'; i++)
	if( badChars.find(transaction.username[i]) != std::string::npos){
		printf("%s\n", Error::invalidUsernameCharactersError);
		return;}

	//check if username exists
	for( int i = 0; i < accounts.size(); i++){
		if( strcmp( transaction.username, accounts[i].username)==0){
			printf("[Fail] User account already exists. Please specify a new username\n"); 
			return;}}

	printf("Enter account type:\n");
	char* new_accountType = format(getLine());

	//check for null, empty input
	if( std::cin.eof() || strlen(new_accountType) == 0){
		printf( "%s\n", Error::badParameterError);
		return;}

	//check input for correct account type size
	if (strlen(new_accountType) != code_size){
		printf("%s\n", Error::LineTooLongError);
		return;}

	if (!isalpha(new_accountType[0]) && !isalpha(new_accountType[1])){
		printf("%s\n", Error::InvalidAccountType);
		return;}

	//turn account type code to uppercase
	for(int i = 0; new_accountType[i] != '\0'; i++){
		new_accountType[i] = toupper(new_accountType[i]);
	}
	//if input != one of the four account types
	if ((strcmp (new_accountType,"AA") != 0) && (strcmp (new_accountType,"FS") != 0) && (strcmp (new_accountType,"SS") != 0) && (strcmp (new_accountType,"BS") != 0)){
		printf("%s\n", Error::InvalidAccountType);
		return;
	}

	transaction.type = usertype_to_enum(new_accountType);

	//get user input for account credit, parse int
	printf("Enter credit amount:\n");
	char* new_accountcredit = format(getLine());

	//check for null, empty input
		if( std::cin.eof() || strlen(new_accountcredit) == 0){
			printf( "%s\n", Error::badParameterError);
			return;}

	//check credit format
	bool flag=true;
	//if ( input[0] == '.' || input[strlen(input)-1] == '.') flag = false;

	  int x;int p=0;
	  for ( x = 0; x < strlen(new_accountcredit); x++) {
	      //printf("%c\n", input[x]);
	      if (!isdigit(new_accountcredit[x])){
	    	  if (new_accountcredit[x] != '.'){
				  flag = false;
				  break;}
	    	  else{
	    		  p++;}}}

	  if (p > 1) flag = false;

	  //check if credit user input is valid
	  if (flag == false){
		  printf( "%s\n", Error::TransactionInvalidCredits);
		  return;}

	  //store user account credit in cents
	  char* leftpart   = new char[ strlen(new_accountcredit) + 1];
	  char* rightpart = new char[ strlen(new_accountcredit) + 1];

	  //  for ( x = 0; x < strlen(input); x++) {
	  //	  if (input[x] != '.')
	  //		  leftpart[x] = input[x];
	  //	  else{
	  //		  int i = 0;
	  //		  for (int y = x+1; x < strlen(input); y++) {
	  //			  rightpart[i] = input[y];
	  //			  i++;}}}

	  x = 0; int l = 0; int r = 0;
	  while( x<strlen(new_accountcredit) ) {
	  	if( new_accountcredit[x] != '.' ) {
	  		leftpart[l] = new_accountcredit[x];
	  		l++;x++;}
	  	else {
	  		x++;  //skip over period
	  		while( x<strlen(new_accountcredit) ) {
	  			rightpart[r] = new_accountcredit[x];
	  			r++;x++; }
	  		break;}}
	  leftpart[l] = '\0'; rightpart[r] = '\0';


	  //printf("'%s'\n'%s'\n",leftpart,rightpart);
	  /*char period[] = ".";
	  char* period_str = (char*)memchr( new_accountcredit, '.', strlen(new_accountcredit));
	  if( NULL != period_str){
		  printf( "%s\n", Error::TransactionInvalidCredits);
		  return;}
	  int period_i = period_str - new_accountcredit;
	  char* left = new char[ credit_size];
	  strncpy( left, new_accountcredit, period_i);
	  char* right = period_str+1;

	  int rpart= strlen(right)>0 ? atoi(right) : 0;*/

	  int rpart= 0;
	  //compose decimal value
	  if (rightpart[0] != '\0') rpart = (rightpart[0]- '0') * 10;
	  if (rightpart[1] != '\0') rpart = rpart + (rightpart[1]- '0');
	  if ((rightpart[2] != '\0') && ((rightpart[2]- '0') > 5)) rpart++; //round up

	  //check that the account credit entered does not exceed the maximum limit
		transaction.totalCredits =  (atoi(leftpart) * 100) + rpart;
	  if (transaction.totalCredits > 99999999){
		  printf( "%s\n", Error::maxAccountCreditError);
		  return;}

	// regex (0 | [1-9][0-9]*) . (0 | [0-9]*[1-9])

	transactionFile->add( transaction);
	printf("[Success] User created\n");
	//accounts.push_back( newAccount);
	return;

}
