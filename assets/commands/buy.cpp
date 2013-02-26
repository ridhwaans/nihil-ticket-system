#include "../commands.h"

void buy(){
	//get parameter
	//check for EOF
	//format input
	//check for null
	//validate parameter
	if( failed){
		//error message
		cout<< Error::badParameterError<< endl;
			//replace badParameterError with the specific error
		return;}
	
	//validate parameter combinations?
	
	//construct transaction
	Transaction transaction = new Transaction();
	transaction.code = Transaction.Code.Buy;
	
	//send data to transactionFile
	transactionFile.add( transaction);
	
	//done, clean up?
	return;}
