#include "errors.h"

const char Error::badParameterError[] = 
	"[Fail] Incorrectly formatted parameter.";
const char Error::badTicketStringError[] = 
	"[Fail] Incorrectly formatted ticket.";
const char Error::badAccountStringError[] = 
	"[Fail] Incorrectly formatted account.";
const char Error::invalidUsernameCharactersError[] = 
	"[Fail] Username has invalid characters.";
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
