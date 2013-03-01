
class TransactionFile{
public:
	vector<Transaction> transactions;
	char* filename;
	
	TransactionFile( char* filename);
	void add(Transaction transaction)
	void update();
private:
}
