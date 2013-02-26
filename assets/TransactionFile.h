
class TransactionFile{
public:
	vector<Transaction> transactions;
	char* filename;
	
	TransactionFile( char* filename);
	void update();
private:
}
