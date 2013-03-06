#include <cstdio>
#include <string.h>
#include "../assets/globals.h"
#include "../assets/Ticket.h"

int main ( int argc, char** argv, char** envp) {
	error_string = new char[error_size];

	char inputstring[] = "eeeeeeeeeeeeeeeeeee uuuuuuuuuuuuuuu 100 100.00";

	Ticket* t = new Ticket(inputstring);

	
	printf( "Done Testing Ticket\n");
}
