#ifndef assets_TransactionFile_h
#define assets_TransactionFile_h

//library includes
#include <vector>
//local includes
#include "Transaction.h"

class TransactionFile{
public:
	std::vector<Transaction> transactions;
	char* filename;
	
	TransactionFile( char* filename);
	~TransactionFile();
	
	void add( Transaction transaction);
	void update();
private:
};

#endif
