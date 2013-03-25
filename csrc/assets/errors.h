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
	extern const char BuyInsufficientCredit[];
	extern const char BuyInsufficientTickets[];
	extern const char BuyInvalidNumberOfTickets[];
	extern const char BuyInvalidNumberOfTickets[];
	extern const char BuySellerDoesNotExist[];
	extern const char BuyUserTicketLimitExceeded[];
	extern const char BuyUserTicketLimitExceeded[];
	extern const char currentAccountDelete[];
	extern const char insufficientCreditError[];
	extern const char InvalidAccountType[];
	extern const char InvalidLoginError[];
	extern const char invalidUsernameCharactersError[];
	extern const char LineTooLongError[];
	extern const char LoginRequiredError[];
	extern const char maxAccountCreditError[];
	extern const char sameUserError[];
	extern const char TicketLineTooLongError[];
	extern const char TicketsFileNotFoundError[];
	extern const char TransactionEventNameTooLong[];
	extern const char TransactionInvalidCode[];
	extern const char TransactionInvalidCredits[];
	extern const char TransactionInvalidTicketAmount[];
	extern const char TransactionInvalidTicketPrice[];
	extern const char TransactionNullAccountType[];
	extern const char TransactionNullCode[];
	extern const char TransactionNullEventName[];
	extern const char TransactionNullUsername[];
	extern const char TransactionUsernameTooLong[];
	extern const char unprivilegedUserError[];
	extern const char UnrecognizedCommandError[];
	extern const char UserNotFound[];
}
#endif
