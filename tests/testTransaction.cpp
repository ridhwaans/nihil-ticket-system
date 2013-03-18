
#include "../assets/Transaction.h"

int main ( int argc, char** argv, char** envp) {
	Transaction::Code code;
	Transaction t;
	t.code = Transaction::Create;
	char username[] = "asdf";
	t.type = Account::Admin;
	t.totalCredits = 1010;
	char* result = t.write();
	printf("%s\n", result);
}