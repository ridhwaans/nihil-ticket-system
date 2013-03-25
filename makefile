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
	rm -rf bin/*
clean-specials: remove-results
	rm -f nts-client
	rm -f output.dtf
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
all: cAll jall
resources: \
	resources/data.atf \
	resources/data.cua

#C++ groups
cAll: cLocals cAssets cCommands
cLocals: \
	bin/nts-client \
	bin/nts-client.o \
	bin/nts-lib.a
cAssets: \
	bin/assets/Account.o \
	bin/assets/commands.o \
	bin/assets/errors.o \
	bin/assets/functions.o \
	bin/assets/variables.o \
	bin/assets/Ticket.o \
	bin/assets/Transaction.o \
	bin/assets/TransactionFile.o
cCommands: \
	bin/assets/commands/addCredit.o \
	bin/assets/commands/addCredit_admin.o \
	bin/assets/commands/buy.o \
	bin/assets/commands/create.o \
	bin/assets/commands/delete.o \
	bin/assets/commands/refund.o \
	bin/assets/commands/sell.o
cTests: \
	bin/tests/testAccount.out \
	bin/tests/testAccounts.out \
	bin/tests/testBuy.out \
	bin/tests/testError.out \
	bin/tests/testFunctions.out \
	bin/tests/testSell.out \
	bin/tests/testTicket.out \
	bin/tests/testTransaction.out

#Java Groups
jAll: \


#C locals
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

#C assets
bin/assets/:
	mkdir -p bin/assets/
bin/assets/Account.o: \
		bin/assets/ \
		csrc/assets/Account.h \
		csrc/assets/Account.cpp
	g++ -c -o bin/assets/Account.o \
		csrc/assets/Account.cpp
bin/assets/commands.o: \
		bin/assets/ \
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
		bin/assets/ \
		csrc/assets/errors.h \
		csrc/assets/errors.cpp
	g++ -c -o bin/assets/errors.o \
		csrc/assets/errors.cpp
bin/assets/functions.o: \
		bin/assets/ \
		csrc/assets/debug.h \
		csrc/assets/globals.h \
		csrc/assets/functions.cpp
	g++ -c -o bin/assets/functions.o \
		csrc/assets/functions.cpp
bin/assets/variables.o: \
		bin/assets/ \
		csrc/assets/globals.h \
		csrc/assets/variables.cpp
	g++ -c -o bin/assets/variables.o \
		csrc/assets/variables.cpp
bin/assets/Ticket.o: \
		bin/assets/ \
		csrc/assets/Ticket.h \
		csrc/assets/Ticket.cpp
	g++ -c -o bin/assets/Ticket.o \
		csrc/assets/Ticket.cpp
bin/assets/Transaction.o: \
		bin/assets/ \
		csrc/assets/Transaction.h \
		csrc/assets/Transaction.cpp
	g++ -c -o bin/assets/Transaction.o \
		csrc/assets/Transaction.cpp
bin/assets/TransactionFile.o: \
		bin/assets/ \
		csrc/assets/TransactionFile.h \
		csrc/assets/TransactionFile.cpp \
		csrc/assets/Transaction.h \
		bin/assets/Transaction.o
	g++ -c -o bin/assets/TransactionFile.o \
		csrc/assets/TransactionFile.cpp

#commands
bin/assets/commands/:
	mkdir -p bin/assets/commands/
bin/assets/commands/addCredit.o: \
		bin/assets/commands/ \
		csrc/assets/commands.h \
		csrc/assets/commands/addCredit.cpp
	g++ -c -o bin/assets/commands/addCredit.o \
		csrc/assets/commands/addCredit.cpp

bin/assets/commands/addCredit_admin.o: \
		bin/assets/commands/ \
		csrc/assets/commands.h \
		csrc/assets/commands/addCredit_admin.cpp
	g++ -c -o bin/assets/commands/addCredit_admin.o \
		csrc/assets/commands/addCredit_admin.cpp

bin/assets/commands/buy.o: \
		bin/assets/commands/ \
		csrc/assets/commands.h \
		csrc/assets/commands/buy.cpp
	g++ -c -o bin/assets/commands/buy.o \
		csrc/assets/commands/buy.cpp

bin/assets/commands/create.o: \
		bin/assets/commands/ \
		csrc/assets/commands.h \
		csrc/assets/commands/create.cpp
	g++ -c -o bin/assets/commands/create.o \
		csrc/assets/commands/create.cpp

bin/assets/commands/delete.o: \
		bin/assets/commands/ \
		csrc/assets/commands.h \
		csrc/assets/commands/delete.cpp
	g++ -c -o bin/assets/commands/delete.o \
		csrc/assets/commands/delete.cpp

bin/assets/commands/refund.o: \
		bin/assets/commands/ \
		csrc/assets/commands.h \
		csrc/assets/commands/refund.cpp
	g++ -c -o bin/assets/commands/refund.o \
		csrc/assets/commands/refund.cpp

bin/assets/commands/sell.o: \
		bin/assets/commands/ \
		csrc/assets/commands.h \
		csrc/assets/commands/sell.cpp
	g++ -c -o bin/assets/commands/sell.o \
		csrc/assets/commands/sell.cpp


#C tests
test-client: nts-client
	./nts-client resources/data.cua resources/data.atf output.dtf
test-allCases: nts-client
	csrc/tools/testAllCases

test-account: bin/tests/testAccount.out
	bin/tests/testAccount.out
bin/tests/testAccount.out: csrc/tests/testAccount.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testAccount.out \
			csrc/tests/testAccount.cpp \
			bin/nts-lib.a

test-accounts: bin/tests/testAccounts.out
	bin/tests/testAccounts.out
csrc/tests/testAccounts.out: csrc/tests/testAccounts.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testAccounts.out \
			csrc/tests/testAccounts.cpp \
			bin/nts-lib.a

test-buy: bin/tests/testBuy.out
	bin/tests/testBuy.out
bin/tests/testBuy.out: csrc/tests/testBuy.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testBuy.out \
			csrc/tests/testBuy.cpp \
			bin/nts-lib.a

test-error: bin/tests/testError.out
	bin/tests/testError.out
bin/tests/testError.out: csrc/tests/testError.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testError.out \
			csrc/tests/testError.cpp \
			bin/nts-lib.a

test-functions: bin/tests/testFunctions.out
	bin/tests/testFunctions.out
bin/tests/testFunctions.out: csrc/tests/testFunctions.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testFunctions.out \
			bin/tests/testFunctions.cpp \
			bin/nts-lib.a

test-sell: bin/tests/testSell.out
	bin/tests/testSell.out
bin/tests/testSell.out: csrc/tests/testSell.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testSell.out \
			csrc/tests/testSell.cpp \
			bin/nts-lib.a

test-ticket: bin/tests/testTicket.out
	bin/tests/testTicket.out
bin/tests/testTicket.out: csrc/tests/testTicket.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testTicket.out \
			bin/tests/testTicket.cpp \
			bin/nts-lib.a

test-tickets: bin/tests/testTickets.out
	bin/tests/testTickets.out
bin/tests/testTickets.out: csrc/tests/testTickets.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testTickets.out \
			bin/tests/testTickets.cpp \
			bin/nts-lib.a

test-transaction: bin/tests/testTransaction.out
	bin/tests/testTransaction.out
bin/tests/testTransaction.out: bin/tests/testTransaction.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testTransaction.out \
			csrc/tests/testTransaction.cpp \
			bin/nts-lib.a