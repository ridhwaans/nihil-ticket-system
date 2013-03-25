#include "../nts-lib.h"

int main ( int argc, char** argv, char** envp) {
	buffer = new char[ buffer_size];
	error_string = new char[ error_size];

	printf("testing transaction\n");
	Transaction t;

	printf("giving code\n");
	t.code = Transaction::Test;

	printf("giving username\n");
	strncpy( t.username, "uuuuuuuuuuuuuuuuuuuu", username_size);
	printf("giving buyer\n");
	strncpy( t.buyer, "bbbbbbbbbbbbbbbbbbb", username_size);
	printf("giving seller\n");
	strncpy( t.seller, "sssssssssssssssssss", username_size);
	printf("giving eventName\n");
	strncpy( t.eventName, "eeeeeeeeeeeeeeeeeeeeeeeeee", eventName_size);
	printf("giving type\n");
	t.type = Account::Admin;
	printf("giving ticketAmount\n");
	t.ticketAmount = 999;
	printf("giving ticketPrice\n");
	t.ticketPrice = 999999;
	printf("giving totalCredits\n");
	t.totalCredits = 99999999;

	printf("%s\n", t.write());
	printf(
		"%-0*c %-0*c %-0*c %-0*c %-0*c %-0*c %-0*c %-0*c %-0*c_\n",
		code_size, 'c', username_size, 'u', username_size, 'b',
		username_size, 's', eventName_size, 'e', type_size, 't',
		quantity_size, 'a', price_size, 'p', credit_size, 'c');

	t.code = Transaction::AddCredit;
	printf("AddCredit: %s\n", t.write());
	t.code = Transaction::Buy;
	printf("Buy:       %s\n", t.write());
	t.code = Transaction::Create;
	printf("Create:    %s\n", t.write());
	t.code = Transaction::Delete;
	printf("Delete:    %s\n", t.write());
	t.code = Transaction::Refund;
	printf("Refund:    %s\n", t.write());
	t.code = Transaction::Sell;
	printf("Sell:      %s\n", t.write());
}