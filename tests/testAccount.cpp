#include <cstdio>
#include <string.h>
#include "../assets/globals.h"
#include "../assets/Ticket.h"

using namespace std;

int main ( int argc, char** argv, char** envp) {
	input = new char[input_size];
	error_string = new char[error_size];
	// format:            UUUUUUUUUUUUUUU_TT_CCCCCCCCC
	char inputstring[] = "END             FS 000001.11";
	Account* account = new Account( inputstring );
	
	printf("Account:{%s,%d,%d}\n",
		account->username, account->type, account->credit);
	printf("Is it the ender?: %s\n",
		account->isEnd()? "true":"false");
	printf("Error happened?: %s\n",
		error? "true":"false");
	return 0;
}