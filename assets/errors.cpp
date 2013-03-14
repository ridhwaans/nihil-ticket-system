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
	"[Fail] Login required";
const char Error::UnrecognizedCommandError[] =
	"[Fail] Login required";
const char Error::TicketLineTooLongError[] =
	"[Fail] Ticket could not be created, line must be 45 chars exactly";
const char Error::UserNotFound[] =
	"[Fail] User not found";
const char Error::currentAccountDelete[]=
	"[Fail] Current account deletion denied";
const char Error::LineTooLongError[]=
		"[Fail] Input line too long.";
const char Error::unprivilegedUserError[]=
		"[Fail] Not a privileged user. Permission denied";
const char Error::InvalidAccountType[]=
		"[Fail] Invalid account type. Two letter uppercase codes indicate Admin, Full Standard, Buy Standard, or Sell Standard account types";
