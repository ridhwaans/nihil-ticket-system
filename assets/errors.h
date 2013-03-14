#ifndef assets_errors_h
#define assets_errors_h

//library headers
//local headers

namespace Error {
	extern const char badParameterError[];
	extern const char badTicketStringError[];
	extern const char badAccountStringError[];
	extern const char invalidUsernameCharactersError[];
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
}

#endif
