#ifndef assets_TransactionFile_h
#define assets_TransactionFile_h

//library includes
#include <vector>
//local includes
#include "Transaction.h"

/** @class TransactionFile
 * @brief The C representation of the dtf.
 **/
class TransactionFile{
public:
	std::vector<Transaction> transactions;
	char* filename;
	
	TransactionFile( const char* filename);
	~TransactionFile();
	
	void add( const Transaction& transaction);
	void commit();
private:
};

#endif
