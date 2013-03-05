#include <cstdio>
#include <string.h>
#include "../assets/globals.h"

int main ( int argc, char** argv, char** envp) {
	// test format and get line
	/*
	char* asdf = getLine();
	printf("%s\n",asdf);
	//*/
	
	// test the init and deinit functions
	/*
	init( "resources/data.cua", "resources/data.atf", "output.dtf");
	deinit();
	//*/
	
	// test accounts data loading
	/*
	loadAccounts( "resources/data.cua");
	Account a = accounts[0];
	printf("Account 0: %s, %d, %d", a.username, a.type, a.credit);
	//*/
	
	// test tickets data loading
	/*
	loadTickets( "resources/data.atf");
	Ticket t = tickets[0];
	printf("Ticket 0: %s, %d, %d, %s",
		t.eventName, t.quntity, t.price, t.username);
	//*/
}
