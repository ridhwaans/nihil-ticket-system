#globals
default: all
clean:
	tools/cleandir .
	tools/cleandir tests
	tools/cleandir tools
remove-results:
	rm -rf results/*
git-prepare: clean
	git add -u
	git add *

#groups
all: locals assets commands
locals: \
	nts-client \
	nts-client.o \
	nts-lib.a
assets: \
	assets/Account.o \
	assets/commands.a \
	assets/errors.o \
	assets/globals.o \
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
		test-login
resources: \
		resources/data.atf \
		resources/data.cua

#locals
nts-client: nts-client.o \
		nts-lib.a
	g++ -o ntsclient \
		nts-client.o \
		nts-lib.a
nts-client.o: nts-client.cpp \
		assets
	g++ -o nts-client.o \
		nts-client.cpp

nts-lib.a: assets
	ar rc nts-lib.a \
		assets/Account.o \
		assets/commands.a \
		assets/errors.o \
		assets/globals.o \
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
assets/commands.a: \
		commands
	ar rc assets/commands.a \
		assets/commands/addCredit.o \
		assets/commands/addCredit_admin.o \
		assets/commands/buy.o \
		assets/commands/create.o \
		assets/commands/delete.o \
		assets/commands/refund.o \
		assets/commands/sell.o
	ranlib assets/commands.a
assets/errors.o: \
		assets/errors.h \
		assets/errors.cpp
	g++ -c -o assets/errors.o \
		asests/errors.cpp
assets/globals.o \
		assets/globals.h \
		assets/constants.cpp \
		assets/functions.cpp
	g++ -c -o assets/globals.o \
		asests/constants.cpp \
		asests/functions.cpp
assets/Ticket.o
assets/Transaction.o
assets/TransactionFile.o

#tests
test-test:
	tests/testtest.sh
test-login:
	tests/login001.sh

