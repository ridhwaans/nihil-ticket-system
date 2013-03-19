#ifndef assets_errors_h
#define assets_errors_h

//library headers
//local headers

namespace Error {
	extern const char AccountsFileNotFoundError[];
	extern const char badAccountStringError[];
	extern const char badEventStringError[];
	extern const char badParameterError[];
	extern const char badTicketStringError[];
	extern const char badUsernameStringError[];
	extern const char BuyUserTicketLimitExceeded[];
	extern const char currentAccountDelete[];
	extern const char InvalidAccountType[];
	extern const char InvalidLoginError[];
	extern const char invalidUsernameCharactersError[];
	extern const char LineTooLongError[];
	extern const char LoginRequiredError[];
	extern const char maxAccountCreditError[];
	extern const char TicketLineTooLongError[];
	extern const char TicketsFileNotFoundError[];
	extern const char TransactionInvalidCode[];
	extern const char TransactionInvalidCredits[];
   extern const char BuySellerDoesNotExist[];
   extern const char BuyInsufficientCredit[];
   extern const char BuyInvalidNumberOfTickets[];
	extern const char BuyInsufficientTickets[];
	extern const char BuyUserTicketLimitExceeded[];
	extern const char TransactionNullAccountType[];
	extern const char TransactionNullUsername[];
	extern const char TransactionNullCode[];
	extern const char TransactionUsernameTooLong[];
	extern const char unprivilegedUserError[];
	extern const char UnrecognizedCommandError[];
	extern const char UserNotFound[];
   extern const char BuyInvalidNumberOfTickets[];
}
#endif
