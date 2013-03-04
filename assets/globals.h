#ifndef assets_globals_h
#define assets_globals_h

//library headers
#include <vector>
//local headers
#include "Ticket.h"
#include "TransactionFile.h"

//forward declarations
class Account;
class Ticket;

//transaction string sizes
#define code_size 2
//account string sizes
#define username_size 15
#define credit_size 9
#define type_size 2
//ticket string sizes
#define eventName_size 19
#define quantity_size 3
#define price_size 6
//string format chars
#define token ' '
#define filler ' '

#define input_size 255
extern char* input;

extern bool error;
extern char* error_string;

extern std::vector<Account> accounts;
extern std::vector<Ticket> tickets;
extern TransactionFile* transactionFile;

char* format( char* original);
char* getLine();

bool init();
bool loadAccounts();
bool loadTickets();

#endif
