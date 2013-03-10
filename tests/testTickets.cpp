#include <cstdio>

#include <string>

#include "../assets/globals.h"
#include "../assets/Ticket.h"

using namespace std;

int main ( int argc, char** argv, char** envp) {
	input = new char[input_size];
	buffer = new char[buffer_size];
	error_string = new char[error_size];
	//load the tickets file
	char filename[] = "resources/data.atf";
	printf( "Success: %s\n", loadTickets( filename) ?
		"true" : "false");
	//do validations
	printf( "Number of tickets: %d\n", tickets.size());
	for( int i = 0; i < tickets.size(); i++)
		printf("Account %d:{%10s,%10s,%3d,%7d}\n", i,
			tickets[i].eventName, tickets[i].username, tickets[i].quantity,
			tickets[i].price);
}