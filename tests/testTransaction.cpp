#include "../nts-lib.h"

int main ( int argc, char** argv, char** envp) {
	buffer = new char[ buffer_size];
	error_string = new char[ error_size];

	printf("testing transaction\n");
	Transaction t;

	printf("giving code\n");
	t.code = Transaction::Test;

	printf("giving username\n");
	strncpy( t.username, "asdfasdfasdfasdfasdf", username_size);
	printf("giving buyer\n");
	strncpy( t.buyer, "asdfasdfasdfasdfasdf", username_size);
	printf("giving seller\n");
	strncpy( t.seller, "asdfasdfasdfasdfasdf", username_size);
	printf("giving eventName\n");
	strncpy( t.eventName, "asdfasdfasdfasdfasdfasdasfasfasfdasdf", eventName_size);
	printf("giving type\n");
	t.type = Account::Admin;
	printf("giving ticketAmount\n");
	t.ticketAmount = 999;
	printf("giving ticketPrice\n");
	t.ticketPrice = 999999;
	printf("giving totalCredits\n");
	t.totalCredits = 99999999;

	char* result = t.write();
	printf("%s\n", result);
	printf("%-0*c %-0*c %-0*c %-0*c %-0*c %-0*c %-0*c %-0*c\n",
		code_size, 'c', username_size, 'u', username_size, 'b',
		username_size, 's', eventName_size, 'e', type_size, 't',
		quantity_size, 'a', price_size, 'p', credit_size, 'c');
}