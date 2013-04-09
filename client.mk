
#Client groups
client-all: client-locals client-assets client-commands
client-locals: \
	bin/nts-client \
	bin/nts-client.o \
	bin/nts-lib.a
client-assets: \
	bin/assets/Account.o \
	bin/assets/commands.o \
	bin/assets/errors.o \
	bin/assets/functions.o \
	bin/assets/variables.o \
	bin/assets/Ticket.o \
	bin/assets/Transaction.o \
	bin/assets/TransactionFile.o
client-commands: \
	bin/assets/commands/addCredit.o \
	bin/assets/commands/addCredit_admin.o \
	bin/assets/commands/buy.o \
	bin/assets/commands/create.o \
	bin/assets/commands/delete.o \
	bin/assets/commands/refund.o \
	bin/assets/commands/sell.o
client-tests: \
	bin/tests/testAccount.out \
	bin/tests/testAccounts.out \
	bin/tests/testBuy.out \
	bin/tests/testError.out \
	bin/tests/testFunctions.out \
	bin/tests/testSell.out \
	bin/tests/testTicket.out \
	bin/tests/testTransaction.out

#Client locals
nts-client: bin/nts-client
	cp bin/nts-client .
bin/nts-client: bin/nts-client.o \
		bin/nts-lib.a
	g++ -o bin/nts-client \
		bin/nts-client.o \
		bin/nts-lib.a
bin/nts-client.o: csrc/nts-client.cpp \
		bin/assets/Account.o \
		bin/assets/commands.o \
		bin/assets/errors.o \
		bin/assets/functions.o \
		bin/assets/variables.o \
		bin/assets/Ticket.o \
		bin/assets/Transaction.o \
		bin/assets/TransactionFile.o
	g++ -c -o bin/nts-client.o \
		csrc/nts-client.cpp

bin/nts-lib.a: \
		bin/assets/Account.o \
		bin/assets/commands.o \
		bin/assets/errors.o \
		bin/assets/functions.o \
		bin/assets/variables.o \
		bin/assets/Ticket.o \
		bin/assets/Transaction.o \
		bin/assets/TransactionFile.o
	ar rc bin/nts-lib.a \
		bin/assets/Account.o \
		bin/assets/commands.o \
		bin/assets/errors.o \
		bin/assets/functions.o \
		bin/assets/variables.o \
		bin/assets/Ticket.o \
		bin/assets/Transaction.o \
		bin/assets/TransactionFile.o
	ranlib bin/nts-lib.a

#Client assets
bin/assets/Account.o: \
		csrc/assets/Account.h \
		csrc/assets/Account.cpp
	$(dir_guard)
	g++ -c -o bin/assets/Account.o \
		csrc/assets/Account.cpp
bin/assets/commands.o: \
		bin/assets/commands/addCredit.o \
		bin/assets/commands/addCredit_admin.o \
		bin/assets/commands/buy.o \
		bin/assets/commands/create.o \
		bin/assets/commands/delete.o \
		bin/assets/commands/refund.o \
		bin/assets/commands/sell.o
	ld -r -o bin/assets/commands.o \
		bin/assets/commands/addCredit.o \
		bin/assets/commands/addCredit_admin.o \
		bin/assets/commands/buy.o \
		bin/assets/commands/create.o \
		bin/assets/commands/delete.o \
		bin/assets/commands/refund.o \
		bin/assets/commands/sell.o
bin/assets/errors.o: \
		csrc/assets/errors.h \
		csrc/assets/errors.cpp
	$(dir_guard)
	g++ -c -o bin/assets/errors.o \
		csrc/assets/errors.cpp
bin/assets/functions.o: \
		csrc/assets/debug.h \
		csrc/assets/globals.h \
		csrc/assets/functions.cpp
	$(dir_guard)
	g++ -c -o bin/assets/functions.o \
		csrc/assets/functions.cpp
bin/assets/variables.o: \
		csrc/assets/globals.h \
		csrc/assets/variables.cpp
	$(dir_guard)
	g++ -c -o bin/assets/variables.o \
		csrc/assets/variables.cpp
bin/assets/Ticket.o: \
		csrc/assets/Ticket.h \
		csrc/assets/Ticket.cpp
	$(dir_guard)
	g++ -c -o bin/assets/Ticket.o \
		csrc/assets/Ticket.cpp
bin/assets/Transaction.o: \
		csrc/assets/Transaction.h \
		csrc/assets/Transaction.cpp
	$(dir_guard)
	g++ -c -o bin/assets/Transaction.o \
		csrc/assets/Transaction.cpp
bin/assets/TransactionFile.o: \
		csrc/assets/TransactionFile.h \
		csrc/assets/TransactionFile.cpp \
		csrc/assets/Transaction.h \
		bin/assets/Transaction.o
	$(dir_guard)
	g++ -c -o bin/assets/TransactionFile.o \
		csrc/assets/TransactionFile.cpp

#commands
bin/assets/commands/addCredit.o: \
		csrc/assets/commands.h \
		csrc/assets/commands/addCredit.cpp
	$(dir_guard)
	g++ -c -o bin/assets/commands/addCredit.o \
		csrc/assets/commands/addCredit.cpp

bin/assets/commands/addCredit_admin.o: \
		csrc/assets/commands.h \
		csrc/assets/commands/addCredit_admin.cpp
	$(dir_guard)
	g++ -c -o bin/assets/commands/addCredit_admin.o \
		csrc/assets/commands/addCredit_admin.cpp

bin/assets/commands/buy.o: \
		csrc/assets/commands.h \
		csrc/assets/commands/buy.cpp
	$(dir_guard)
	g++ -c -o bin/assets/commands/buy.o \
		csrc/assets/commands/buy.cpp

bin/assets/commands/create.o: \
		csrc/assets/commands.h \
		csrc/assets/commands/create.cpp
	$(dir_guard)
	g++ -c -o bin/assets/commands/create.o \
		csrc/assets/commands/create.cpp

bin/assets/commands/delete.o: \
		csrc/assets/commands.h \
		csrc/assets/commands/delete.cpp
	$(dir_guard)
	g++ -c -o bin/assets/commands/delete.o \
		csrc/assets/commands/delete.cpp

bin/assets/commands/refund.o: \
		csrc/assets/commands.h \
		csrc/assets/commands/refund.cpp
	$(dir_guard)
	g++ -c -o bin/assets/commands/refund.o \
		csrc/assets/commands/refund.cpp

bin/assets/commands/sell.o: \
		csrc/assets/commands.h \
		csrc/assets/commands/sell.cpp
	$(dir_guard)
	g++ -c -o bin/assets/commands/sell.o \
		csrc/assets/commands/sell.cpp

#Client top-level functionality tests
tests/cases.zip:
	zip -rq tests/cases.zip tests/*/
	rm -rf tests/*/
test-case-files:
	unzip -q tests/cases.zip
	rm -f tests/cases.zip

#Client component tests
client-test: nts-client
	./nts-client resources/data.cua resources/data.atf output.dtf
client-test-cases: nts-client \
		tests/*/*
	tools/testAllCases

client-test-account: bin/tests/testAccount.out
	bin/tests/testAccount.out
bin/tests/testAccount.out: csrc/tests/testAccount.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testAccount.out \
			csrc/tests/testAccount.cpp \
			bin/nts-lib.a

client-test-accounts: bin/tests/testAccounts.out
	bin/tests/testAccounts.out
csrc/tests/testAccounts.out: csrc/tests/testAccounts.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testAccounts.out \
			csrc/tests/testAccounts.cpp \
			bin/nts-lib.a

client-test-buy: bin/tests/testBuy.out
	bin/tests/testBuy.out
bin/tests/testBuy.out: csrc/tests/testBuy.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testBuy.out \
			csrc/tests/testBuy.cpp \
			bin/nts-lib.a

client-test-error: bin/tests/testError.out
	bin/tests/testError.out
bin/tests/testError.out: csrc/tests/testError.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testError.out \
			csrc/tests/testError.cpp \
			bin/nts-lib.a

client-test-functions: bin/tests/testFunctions.out
	bin/tests/testFunctions.out
bin/tests/testFunctions.out: csrc/tests/testFunctions.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testFunctions.out \
			bin/tests/testFunctions.cpp \
			bin/nts-lib.a

client-test-sell: bin/tests/testSell.out
	bin/tests/testSell.out
bin/tests/testSell.out: csrc/tests/testSell.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testSell.out \
			csrc/tests/testSell.cpp \
			bin/nts-lib.a

client-test-ticket: bin/tests/testTicket.out
	bin/tests/testTicket.out
bin/tests/testTicket.out: csrc/tests/testTicket.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testTicket.out \
			bin/tests/testTicket.cpp \
			bin/nts-lib.a

client-test-tickets: bin/tests/testTickets.out
	bin/tests/testTickets.out
bin/tests/testTickets.out: csrc/tests/testTickets.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testTickets.out \
			bin/tests/testTickets.cpp \
			bin/nts-lib.a

client-test-transaction: bin/tests/testTransaction.out
	bin/tests/testTransaction.out
bin/tests/testTransaction.out: bin/tests/testTransaction.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testTransaction.out \
			csrc/tests/testTransaction.cpp \
			bin/nts-lib.a