#include "globals.h"
#include "Account.h"
#include "Ticket.h"
#include "TransactionFile.h"

char* input;
char* buffer;

bool error;
char* error_string;

int currentAccount_index;
Account* currentAccount;

std::vector<Account> accounts;
std::vector<Ticket> tickets;
TransactionFile* transactionFile;
