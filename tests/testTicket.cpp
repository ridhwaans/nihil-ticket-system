#include <cstdio>
#include <string.h>
#include "../assets/globals.h"
#include "../assets/Ticket.h"

using namespace std;


int main ( int argc, char** argv, char** envp) {

	char inputstring[] = "Theeeeeeeeeeeeevent Auuuuuuusername 100 100.00";

	Ticket* t = new Ticket( (char*) inputstring );
	
	
   cout << "Testing Ticket.cpp..." << endl;
   cout << "Event Name: "          << t->eventName << endl;
	cout << "Username: "            << t->username  << endl;
	cout << "Quantity: "            << t->quantity  << endl;
   cout << "Price: "               << t->price     << endl;

	cout << "Done.";


	return 0;
}
