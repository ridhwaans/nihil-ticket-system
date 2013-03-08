#include <cstdio>
#include <string.h>
#include "../assets/globals.h"
#include "../assets/Ticket.h"

using namespace std;

int main ( int argc, char** argv, char** envp) {
	char inputstring[] = "Theeeeeee ee event  Auuuuuuusername 100 264.31";

	Ticket* t = new Ticket( (char*) inputstring );
	
	cout << "Testing Ticket.cpp..." << endl;
	cout << "Event Name: "          << t->eventName << endl;
	cout << "Username: "            << t->username  << endl;
	cout << "Quantity: "            << t->quantity  << endl;
	cout << "Price: "               << t->price     << endl;

	cout << "Done." << endl;

	return 0;
}
