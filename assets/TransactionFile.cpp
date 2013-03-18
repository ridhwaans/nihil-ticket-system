//library includes
#include <cstring>
#include <fstream>
//override include
#include "TransactionFile.h"

TransactionFile::TransactionFile( const char* _filename){
	filename = new char[filename_size];
	strcpy( filename, _filename);
}
TransactionFile::~TransactionFile(){
	transactions.clear();
	delete[] filename;
}

void TransactionFile::add( const Transaction& transaction){
	transactions.push_back( transaction);
}
void TransactionFile::commit(){
	//open the file
	std::ofstream dtf(filename, std::ios_base::app);
	//write each transaction
	int transactions_size = transactions.size();
	for( int i = 0; i < transactions_size; i++)
		dtf<< transactions[i].write() << std::endl;
	transactions.clear();
}
