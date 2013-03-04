#ifndef assets_globals_h
#define assets_globals_h

#include <vector.h>

#define username_size 15
#define eventName_size 30

char input[255];
int input_size = 255;
vector<Account> accounts;
vector<Ticket> tickets;

char* format( char* original);
char* get line();

#endif
