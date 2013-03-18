#globals
default: all
clean: clean-specials
	tools/cleandir .
	tools/cleandir assets
	tools/cleandir assets/commands
	tools/cleandir results
	tools/cleandir scripts
	tools/cleandir tests
	tools/cleandir tools
clean-specials: remove-results
	rm -f nts-client
freshen: clean all
remove-results:
	rm -rf results/*

#git
git-prepare: clean
	git add -u
	git add *
git-pushall:
	git push origin working
	git push origin merging
	git push origin master
git-updateall:
	git checkout master
	git merge merging
	git merge working
	git checkout merging
	git merge master
	git merge working
	git checkout working
	git merge master
	git merge merging

#groups
all: locals assets commands
locals: \
	nts-client \
	nts-client.o \
	nts-lib.a
assets: \
	assets/Account.o \
	assets/commands.o \
	assets/errors.o \
	assets/functions.o \
	assets/variables.o \
	assets/Ticket.o \
	assets/Transaction.o \
	assets/TransactionFile.o
commands: \
	assets/commands/addCredit.o \
	assets/commands/addCredit_admin.o \
	assets/commands/buy.o \
	assets/commands/create.o \
	assets/commands/delete.o \
	assets/commands/refund.o \
	assets/commands/sell.o
tests: \
		tests/testAccount.out \
		tests/testAccounts.out \
		tests/testBuy.out \
		tests/testError.out \
		tests/testFunctions.out \
		tests/testSell.out \
		tests/testTicket.out \
		tests/testTransaction.out
resources: \
		resources/data.atf \
		resources/data.cua

#locals
nts-client: nts-client.o \
		nts-lib.a
	g++ -o nts-client \
		nts-client.o \
		nts-lib.a
nts-client.o: nts-client.cpp \
		assets/Account.o \
		assets/commands.o \
		assets/errors.o \
		assets/functions.o \
		assets/variables.o \
		assets/Ticket.o \
		assets/Transaction.o \
		assets/TransactionFile.o
	g++ -c -o nts-client.o \
		nts-client.cpp

nts-lib.a: \
		assets/Account.o \
		assets/commands.o \
		assets/errors.o \
		assets/functions.o \
		assets/variables.o \
		assets/Ticket.o \
		assets/Transaction.o \
		assets/TransactionFile.o
	ar rc nts-lib.a \
		assets/Account.o \
		assets/commands.o \
		assets/errors.o \
		assets/functions.o \
		assets/variables.o \
		assets/Ticket.o \
		assets/Transaction.o \
		assets/TransactionFile.o
	ranlib nts-lib.a

#assets
assets/Account.o: \
		assets/Account.h \
		assets/Account.cpp
	g++ -c -o assets/Account.o \
		assets/Account.cpp
assets/commands.o: \
		assets/commands/addCredit.o \
		assets/commands/addCredit_admin.o \
		assets/commands/buy.o \
		assets/commands/create.o \
		assets/commands/delete.o \
		assets/commands/refund.o \
		assets/commands/sell.o
	ld -r -o assets/commands.o \
		assets/commands/addCredit.o \
		assets/commands/addCredit_admin.o \
		assets/commands/buy.o \
		assets/commands/create.o \
		assets/commands/delete.o \
		assets/commands/refund.o \
		assets/commands/sell.o
assets/errors.o: \
		assets/errors.h \
		assets/errors.cpp
	g++ -c -o assets/errors.o \
		assets/errors.cpp
assets/functions.o: \
		assets/debug.h \
		assets/globals.h \
		assets/functions.cpp
	g++ -c -o assets/functions.o \
		assets/functions.cpp
assets/variables.o: \
		assets/globals.h \
		assets/variables.cpp
	g++ -c -o assets/variables.o \
		assets/variables.cpp
assets/Ticket.o: \
		assets/Ticket.h \
		assets/Ticket.cpp
	g++ -c -o assets/Ticket.o \
		assets/Ticket.cpp
assets/Transaction.o: \
		assets/Transaction.h \
		assets/Transaction.cpp
	g++ -c -o assets/Transaction.o \
		assets/Transaction.cpp
assets/TransactionFile.o: \
		assets/TransactionFile.h \
		assets/TransactionFile.cpp \
		assets/Transaction.h \
		assets/Transaction.o
	g++ -c -o assets/TransactionFile.o \
		assets/TransactionFile.cpp

#tests
test-client: nts-client
	./nts-client resources/data.cua resources/data.atf output.dtf
test-allCases: nts-client
	tools/testAllCases

test-account: tests/testAccount.out
	tests/testAccount.out
tests/testAccount.out: tests/testAccount.cpp \
		assets/globals.h \
		nts-lib.a
	g++ -o tests/testAccount.out \
			tests/testAccount.cpp \
			nts-lib.a

test-accounts: tests/testAccounts.out
	tests/testAccounts.out
tests/testAccounts.out: tests/testAccounts.cpp \
		assets/globals.h \
		nts-lib.a
	g++ -o tests/testAccounts.out \
			tests/testAccounts.cpp \
			nts-lib.a

test-buy: tests/testBuy.out
	tests/testBuy.out
tests/testBuy.out: tests/testBuy.cpp \
		assets/globals.h \
		nts-lib.a
	g++ -o tests/testBuy.out \
			tests/testBuy.cpp \
			nts-lib.a

test-error: tests/testError.out
	tests/testError.out
tests/testError.out: tests/testError.cpp \
		assets/globals.h \
		nts-lib.a
	g++ -o tests/testError.out \
			tests/testError.cpp \
			nts-lib.a

test-functions: tests/testFunctions.out
	tests/testFunctions.out
tests/testFunctions.out: tests/testFunctions.cpp \
		assets/globals.h \
		nts-lib.a
	g++ -o tests/testFunctions.out \
			tests/testFunctions.cpp \
			nts-lib.a

test-sell: tests/testSell.out
	tests/testSell.out
tests/testSell.out: tests/testSell.cpp \
		assets/globals.h \
		nts-lib.a
	g++ -o tests/testSell.out \
			tests/testSell.cpp \
			nts-lib.a

test-ticket: tests/testTicket.out
	tests/testTicket.out
tests/testTicket.out: tests/testTicket.cpp \
		assets/globals.h \
		nts-lib.a
	g++ -o tests/testTicket.out \
			tests/testTicket.cpp \
			nts-lib.a

test-tickets: tests/testTickets.out
	tests/testTickets.out
tests/testTickets.out: tests/testTickets.cpp \
		assets/globals.h \
		nts-lib.a
	g++ -o tests/testTickets.out \
			tests/testTickets.cpp \
			nts-lib.a

test-transaction: tests/testTransaction.out
	tests/testTransaction.out
tests/testTransaction.out: tests/testTransaction.cpp \
		assets/globals.h \
		nts-lib.a
	g++ -o tests/testTransaction.out \
			tests/testTransaction.cpp \
			nts-lib.a