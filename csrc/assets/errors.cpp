#include "errors.h"

//note: this file is inteded to be viewed full-screen, not half-screen

const char Error::AccountsFileNotFoundError[] = "[Fail] Accounts File Not Found";
const char Error::badAccountStringError[] = "[Fail] Incorrectly formatted account.";
const char Error::badEventStringError[] = "[Fail] Incorrectly formatted event name.";
const char Error::badParameterError[] = "[Fail] Incorrectly formatted parameter.";
const char Error::badTicketStringError[] = "[Fail] Incorrectly formatted ticket.";
const char Error::badUsernameStringError[] = "[Fail] Incorrectly formatted username. Usernames are 1 to 15 alpha-numeric characters.";
const char Error::BuyInsufficientCredit[] = "[Fail] Insufficient credit to buy the requested tickets.";
const char Error::BuyInvalidNumberOfTickets[] = "[Fail] Can not buy the specified number of tickets, there is currently not enought tickets available.";
const char Error::BuySellerDoesNotExist[] = "[Fail] Specified seller does not exst";
const char Error::BuyUserTicketLimitExceeded[] = "[Fail] Your current user account prohibits you from buying more than 4 tickets from another user, in the same transaction.";
const char Error::currentAccountDelete[] = "[Fail] Current account deletion denied";
const char Error::insufficientCreditError[]=	"[Fail] Seller does not have enough credit";
const char Error::InvalidAccountType[] = 	"[Fail] Invalid account type";
const char Error::InvalidLoginError[] = "[Fail] Login invalid";
const char Error::invalidUsernameCharactersError[] = "[Fail] Username has invalid characters.";
const char Error::LineTooLongError[] = "[Fail] Input line too long";
const char Error::LoginRequiredError[] = "[Fail] Login required";
const char Error::maxAccountCreditError[] = 	"[Fail] User account credit cannot be greater than 999,999";
const char Error::sameUserError[]=	"[Fail] Refunder id Refundee";
const char Error::TicketLineTooLongError[] = "[Fail] Ticket could not be created, line must be 45 chars exactly";
const char Error::TicketsFileNotFoundError[] = "[Fail] Tickets File Not Found";
const char Error::TransactionEventNameTooLong[] = 	"[Fail] Transaction event name too long";
const char Error::TransactionInvalidCode[] = 	"[Fail] Transaction given unsupported transaction code";
const char Error::TransactionInvalidCredits[] = "[Fail] Transaction has invalid credit amount";
const char Error::TransactionInvalidTicketAmount[] = "[Fail] Transaction has invalid credit amount";
const char Error::TransactionInvalidTicketPrice[] = "[Fail] Transaction has invalid credit amount";
const char Error::TransactionNullAccountType[] = "[Fail] Transaction missing account type";
const char Error::TransactionNullCode[] = "[Fail] Transaction missing code";
const char Error::TransactionNullEventName[] = "[Fail] Transaction missing event name";
const char Error::TransactionNullUsername[] = "[Fail] Transaction missing username";
const char Error::TransactionUsernameTooLong[] = "[Fail] Transaction username too long";
const char Error::unprivilegedUserError[] = 	"[Fail] Permission denied";
const char Error::UnrecognizedCommandError[] = "[Fail] Unrecognized command";
const char Error::UserNotFound[] = "[Fail] User not found";
