#ifndef assets_errors_h
#define assets_errors_h

//library headers
//local headers

namespace Error {
	extern const char badParameterError[];
	extern const char badTicketStringError[];
	extern const char badAccountStringError[];
	extern const char invalidUsernameCharactersError[];
	extern const char badUsernameStringError[];
	extern const char badEventStringError[];
	extern const char LoginRequiredError[];
	extern const char InvalidLoginError[];
	extern const char UnrecognizedCommandError[];
	extern const char TicketLineTooLongError[];
	extern const char AccountsFileNotFoundError[];
	extern const char TicketsFileNotFoundError[];
	extern const char UserNotFound[];
	extern const char currentAccountDelete[];
	extern const char LineTooLongError[];
	extern const char TransactionNullUsername[];
	extern const char TransactionNullAccountType[];
	extern const char TransactionInvalidCredits[];
   extern const char BuySellerDoesNotExist[];
   extern const char BuyInsufficientCredit[];
   extern const char BuyInvalidNumberOfTickets[];
	extern const char BuyInsufficientTickets[];
	extern const char BuyUserTicketLimitExceeded[];
	extern const char unprivilegedUserError[];
	extern const char InvalidAccountType[];
}
#endif
