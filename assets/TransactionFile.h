#ifndef assets_TransactionFile_h
#define assets_TransactoinFile_h

#include <vector.h>

#include "Transaction.h"

class TransactionFile{
public:
	vector<Transaction> transactions;
	char* filename;
	
	TransactionFile( char* filename);
	
	void add(Transaction transaction)
	void update();
private:
}

#endif
