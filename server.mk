
#Server Groups
server-all: server-assets server-locals server-transactions
server-assets: \
	bin/assets/Account.class \
	bin/assets/Ticket.class
server-locals: \
	bin/NTSServer.class
server-transactions: \
	bin/transaction/AddCredit.class \
	bin/transaction/Buy.class \
	bin/transaction/Create.class \
	bin/transaction/Delete.class \
	bin/transaction/Refund.class \
	bin/transaction/Sell.class \
	bin/transaction/TransactionException.class \
	bin/transaction/Transaction.class
server-tests: \
	bin/tests/TestAccount.class \
	bin/tests/TestTicket.class \
	bin/tests/TestAddCredit.class \
	bin/tests/TestBuy.class \
	bin/tests/TestCreate.class \
	bin/tests/TestDelete.class \
	bin/tests/TestRefund.class \
	bin/tests/TestSell.class
server-test-all:
	server-test-account \
	server-test-account2 \
	server-test-ticket \
	server-test-addcredit \
	server-test-buy \
	server-test-create \
	server-test-delete \
	server-test-refund \
	server-test-sell

#Server locals
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

#Server assets
bin/assets/Account.class: \
		jsrc/assets/Account.java
	javac $(cp) $(dest) jsrc/assets/Account.java

bin/assets/Ticket.class: \
		jsrc/assets/Ticket.java
	javac $(cp) $(dest) jsrc/assets/Ticket.java

#Server transactions
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

#Server tests
server-test: bin/NTSServer.class
	java $(cp) NTSServer \
		resources/data.cua \
		resources/data.atf \
		resources/data.dtf

server-test-account: bin/tests/TestAccount.class
	java $(cp) org.junit.runner.JUnitCore tests.TestAccount
server-test-account2: bin/tests/TestAccount.class
	java $(cp) tests.TestAccount
bin/tests/TestAccount.class: jsrc/tests/TestAccount.java \
		bin/assets/Account.class
	javac $(cp) $(dest) jsrc/tests/TestAccount.java

server-test-ticket: bin/tests/TestTicket.class
	java $(cp) org.junit.runner.JUnitCore tests.TestTicket
bin/tests/TestTicket.class: jsrc/tests/TestTicket.java \
		bin/assets/Ticket.class
	javac $(cp) $(dest) jsrc/tests/TestTicket.java

server-test-addcredit: bin/tests/TestAddCredit.class
	java $(cp) org.junit.runner.JUnitCore tests.TestAddCredit
bin/tests/TestAddCredit.class: jsrc/tests/TestAddCredit.java \
		bin/transaction/AddCredit.class
	javac $(cp) $(dest) jsrc/tests/TestAddCredit.java

server-test-buy: bin/tests/TestBuy.class
	java $(cp) org.junit.runner.JUnitCore tests.TestBuy
bin/tests/TestBuy.class: jsrc/tests/TestBuy.java \
		bin/transaction/Buy.class
	javac $(cp) $(dest) jsrc/tests/TestBuy.java

server-test-create: bin/tests/TestCreate.class
	java $(cp) org.junit.runner.JUnitCore tests.TestCreate
bin/tests/TestCreate.class: jsrc/tests/TestCreate.java \
		bin/transaction/Create.class
	javac $(cp) $(dest) jsrc/tests/TestCreate.java

server-test-delete: bin/tests/TestDelete.class
	java $(cp) org.junit.runner.JUnitCore tests.TestDelete
bin/tests/TestDelete.class: jsrc/tests/TestDelete.java \
		bin/transaction/Delete.class
	javac $(cp) $(dest) jsrc/tests/TestDelete.java

server-test-refund: bin/tests/TestRefund.class
	java $(cp) org.junit.runner.JUnitCore tests.TestRefund
bin/tests/TestRefund.class: jsrc/tests/TestRefund.java \
		bin/transaction/Refund.class
	javac $(cp) $(dest) jsrc/tests/TestRefund.java

server-test-sell: bin/tests/TestSell.class
	java $(cp) org.junit.runner.JUnitCore tests.TestSell
bin/tests/TestSell.class: jsrc/tests/TestSell.java \
		bin/transaction/Sell.class
	javac $(cp) $(dest) jsrc/tests/TestSell.java
