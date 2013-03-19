#include "errors.h"

const char Error::badParameterError[] = 
	"[Fail] Incorrectly formatted parameter.";
const char Error::badTicketStringError[] = 
	"[Fail] Incorrectly formatted ticket.";
const char Error::badAccountStringError[] = 
	"[Fail] Incorrectly formatted account.";
const char Error::invalidUsernameCharactersError[] = 
	"[Fail] Username has invalid characters.";
const char Error::badEventStringError[] =
	"[Fail] Incorrectly formatted event name.";
const char Error::LoginRequiredError[] =
	"[Fail] Login required";
const char Error::InvalidLoginError[] =
	"[Fail] Login invalid";
const char Error::UnrecognizedCommandError[] =
	"[Fail] Unrecognized command";
const char Error::TicketLineTooLongError[] =
	"[Fail] Ticket could not be created, line must be 45 chars exactly";
const char Error::AccountsFileNotFoundError[] =
	"[Fail] Accounts File Not Found";
const char Error::TicketsFileNotFoundError[] =
	"[Fail] Tickets File Not Found";
const char Error::UserNotFound[] =
	"[Fail] User not found";
const char Error::currentAccountDelete[]=
	"[Fail] Current account deletion denied";
const char Error::LineTooLongError[]=
	"[Fail] Input line too long";
const char Error::TransactionNullUsername[]=
	"[Fail] Transaction missing username";
const char Error::TransactionNullAccountType[]=
	"[Fail] Transaction missing account type";
const char Error::TransactionInvalidCredits[]=
	"[Fail] Transaction has invalid credit amount";
const char Error::unprivilegedUserError[]=
		"[Fail] Permission denied";
const char Error::InvalidAccountType[]=
		"[Fail] Invalid account type";
const char Error::maxAccountCreditError[]=
		"[Fail] User account credit cannot be greater than 999,999";
const char Error::insufficientCreditError[]=
		"[Fail] User account does not have enough credits for this transaction";

