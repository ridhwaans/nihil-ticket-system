#include <cstdio>
#include <string.h>
#include "../assets/globals.h"
#include "../assets/Ticket.h"
#include "../assets/commands.h"


using namespace std;

int main ( int argc, char** argv, char** envp) {

	if( argc == 0 ) {
		cout <<"TestSell:  you must launch this test program with 3 arguments, to specify: " << endl;
		cout <<"                    

	}
	cout << "Testing Sell.cpp..." << endl;

	
	command_sell();
	
	
	cout << "Done." << endl;

	return 0;
}
