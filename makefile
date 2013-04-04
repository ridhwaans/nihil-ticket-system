#globals
default: all
freshen: clean all
clean: clean-specials
	tools/cleandir .
	tools/cleandir assets
	tools/cleandir assets/commands
	tools/cleandir results
	tools/cleandir scripts
	tools/cleandir tests
	tools/cleandir tools
	rm -rf bin/*
clean-specials: \
		tests/cases.zip
	rm -rf results/*
	rm -rf documentation
	rm -f nts-client
	rm -f output.dtf
docs: doxyfile
	doxygen
docs-view: docs
	chromium-browser documentation/html/index.html

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
git-fetchall:
	git fetch wes
	git fetch ridhwaan
	git fetch bryce

#variables
cp = -cp jsrc:bin:libs/*
dest = -d bin
dir_guard = @mkdir -p $(@D)

#groups
all: c_all j_all
resources: \
	resources/data.atf \
	resources/data.cua

#Java Groups
j_all: j_assets j_locals j_transactions
j_assets: \
	bin/assets/Account.class \
	bin/assets/Ticket.class
j_locals: \
	bin/NTSServer.class
j_transactions: \
	bin/transaction/AddCredit.class \
	bin/transaction/Buy.class \
	bin/transaction/Create.class \
	bin/transaction/Delete.class \
	bin/transaction/Refund.class \
	bin/transaction/Sell.class \
	bin/transaction/TransactionException.class \
	bin/transaction/Transaction.class

#Java locals
bin/NTSServer.class: \
		jsrc/NTSServer.java \
		bin/assets/Account.class \
		bin/assets/Ticket.class \
		bin/transaction/AddCredit.class \
		bin/transaction/Buy.class \
		bin/transaction/Create.class \
		bin/transaction/Delete.class \
		bin/transaction/Refund.class \
		bin/transaction/Sell.class \
		bin/transaction/TransactionException.class \
		bin/transaction/Transaction.class
	javac $(cp) $(dest) jsrc/NTSServer.java

#Java assets
bin/assets/Account.class: \
		jsrc/assets/Account.java
	javac $(cp) $(dest) jsrc/assets/Account.java

bin/assets/Ticket.class: \
		jsrc/assets/Ticket.java
	javac $(cp) $(dest) jsrc/assets/Ticket.java

#Java transactions
bin/transaction/AddCredit.class: \
		jsrc/transaction/AddCredit.java \
		bin/transaction/Transaction.class \
		bin/assets/Account.class
	javac $(cp) $(dest) jsrc/transaction/AddCredit.java

bin/transaction/Buy.class: \
		jsrc/transaction/Buy.java \
		bin/transaction/Transaction.class \
		bin/assets/Account.class \
		bin/assets/Ticket.class
	javac $(cp) $(dest) jsrc/transaction/Buy.java

bin/transaction/Create.class: \
		jsrc/transaction/Create.java \
		bin/transaction/Transaction.class \
		bin/assets/Account.class
	javac $(cp) $(dest) jsrc/transaction/Create.java

bin/transaction/Delete.class: \
		jsrc/transaction/Delete.java \
		bin/transaction/Transaction.class \
		bin/assets/Account.class
	javac $(cp) $(dest) jsrc/transaction/Delete.java

bin/transaction/Refund.class: \
		jsrc/transaction/Refund.java \
		bin/transaction/Transaction.class \
		bin/assets/Account.class
	javac $(cp) $(dest) jsrc/transaction/Refund.java

bin/transaction/Sell.class: \
		jsrc/transaction/Sell.java \
		bin/transaction/Transaction.class \
		bin/assets/Account.class \
		bin/assets/Ticket.class
	javac $(cp) $(dest) jsrc/transaction/Sell.java

bin/transaction/TransactionException.class: \
		jsrc/transaction/TransactionException.java
	javac $(cp) $(dest) jsrc/transaction/TransactionException.java

bin/transaction/Transaction.class: \
		jsrc/transaction/Transaction.java
	javac $(cp) $(dest) jsrc/transaction/Transaction.java

#Java tests
test-server: bin/NTSServer.class
	java $(cp) NTSServer \
		resources/data.cua \
		resources/data.atf \
		resources/data.dtf

#C++ groups
c_all: c_locals c_assets c_commands
c_locals: \
	bin/nts-client \
	bin/nts-client.o \
	bin/nts-lib.a
c_assets: \
	bin/assets/Account.o \
	bin/assets/commands.o \
	bin/assets/errors.o \
	bin/assets/functions.o \
	bin/assets/variables.o \
	bin/assets/Ticket.o \
	bin/assets/Transaction.o \
	bin/assets/TransactionFile.o
c_commands: \
	bin/assets/commands/addCredit.o \
	bin/assets/commands/addCredit_admin.o \
	bin/assets/commands/buy.o \
	bin/assets/commands/create.o \
	bin/assets/commands/delete.o \
	bin/assets/commands/refund.o \
	bin/assets/commands/sell.o
c_tests: \
	bin/tests/testAccount.out \
	bin/tests/testAccounts.out \
	bin/tests/testBuy.out \
	bin/tests/testError.out \
	bin/tests/testFunctions.out \
	bin/tests/testSell.out \
	bin/tests/testTicket.out \
	bin/tests/testTransaction.out

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

#C top-level functionality tests
tests/cases.zip:
	zip -rq tests/cases.zip tests/*/
	rm -rf tests/*/
test-case-files:
	unzip -q tests/cases.zip
	rm -f tests/cases.zip

#C component tests
test-client: nts-client
	./nts-client resources/data.cua resources/data.atf output.dtf
test-allCases: nts-client \
		tests/*/*
	tools/testAllCases

test-client-account: bin/tests/testAccount.out
	bin/tests/testAccount.out
bin/tests/testAccount.out: csrc/tests/testAccount.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testAccount.out \
			csrc/tests/testAccount.cpp \
			bin/nts-lib.a

test-client-accounts: bin/tests/testAccounts.out
	bin/tests/testAccounts.out
csrc/tests/testAccounts.out: csrc/tests/testAccounts.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testAccounts.out \
			csrc/tests/testAccounts.cpp \
			bin/nts-lib.a

test-client-buy: bin/tests/testBuy.out
	bin/tests/testBuy.out
bin/tests/testBuy.out: csrc/tests/testBuy.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testBuy.out \
			csrc/tests/testBuy.cpp \
			bin/nts-lib.a

test-client-error: bin/tests/testError.out
	bin/tests/testError.out
bin/tests/testError.out: csrc/tests/testError.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testError.out \
			csrc/tests/testError.cpp \
			bin/nts-lib.a

test-client-functions: bin/tests/testFunctions.out
	bin/tests/testFunctions.out
bin/tests/testFunctions.out: csrc/tests/testFunctions.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testFunctions.out \
			bin/tests/testFunctions.cpp \
			bin/nts-lib.a

test-client-sell: bin/tests/testSell.out
	bin/tests/testSell.out
bin/tests/testSell.out: csrc/tests/testSell.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testSell.out \
			csrc/tests/testSell.cpp \
			bin/nts-lib.a

test-client-ticket: bin/tests/testTicket.out
	bin/tests/testTicket.out
bin/tests/testTicket.out: csrc/tests/testTicket.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testTicket.out \
			bin/tests/testTicket.cpp \
			bin/nts-lib.a

test-client-tickets: bin/tests/testTickets.out
	bin/tests/testTickets.out
bin/tests/testTickets.out: csrc/tests/testTickets.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testTickets.out \
			bin/tests/testTickets.cpp \
			bin/nts-lib.a

test-client-transaction: bin/tests/testTransaction.out
	bin/tests/testTransaction.out
bin/tests/testTransaction.out: bin/tests/testTransaction.cpp \
		csrc/assets/globals.h \
		bin/nts-lib.a
	g++ -o bin/tests/testTransaction.out \
			csrc/tests/testTransaction.cpp \
			bin/nts-lib.a