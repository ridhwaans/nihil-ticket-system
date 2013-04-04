//library imports
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;
import transaction.*;

/** @class NTSServer
 * @brief The Java server for the ticket system.
 * 
 * This executable class represents the server for the ticket system. It makes use of every class in the assets and transactions packages in order to parse data, and apply transactions to data.
 **/
public class NTSServer {
	public static void main( String[] args){
		// Setup
		//local variables
		Vector<Account> accounts = new Vector<Account>();
		Vector<Ticket> tickets = new Vector<Ticket>();
		Vector<Transaction> transactions = new Vector<Transaction>();

		//Select the name of the accounts file
		String accountsFile;
		if( args.length > 0)
			accountsFile = args[0];
		else{
			accountsFile = "resources/data.cua";
			System.out.println(
				"Accounts file argument not found, using " + accountsFile);}
		
		//Select the name of the tickets file
		String ticketsFile;
		if( args.length > 1)
			ticketsFile = args[1];
		else{
			ticketsFile = "resources/data.atf";
			System.out.println(
				"Tickets file argument not found, using " + ticketsFile);}
		
		//Select the name of the transactions file
		String transactionsFile;
		if( args.length > 2)
			transactionsFile = args[2];
		else{
			transactionsFile = "output.dtf";
			System.out.println(
				"Transactions file argument not found, using " + transactionsFile);}

		//Select the name of the output accounts file
		String outputAccountsFile;
		if( args.length > 3)
			outputAccountsFile = args[3];
		else{
			outputAccountsFile = "results/data.cua";
			System.out.println(
				"Accounts file output argument not found, using " + outputAccountsFile);}
		
		//Select the name of the output tickets file
		String outputTicketsFile;
		if( args.length > 4)
			outputTicketsFile = args[4];
		else{
			outputTicketsFile = "results/data.atf";
			System.out.println(
				"Tickets file output argument not found, using " + outputTicketsFile);}

		// Load Data
		//try to load the accounts file
		try { loadAccounts( accountsFile, accounts);}
		catch ( FileNotFoundException e){
			System.out.printf(
				"Accounts file not found: %s\n", accountsFile);}
		//try to load the tickets file
		try { loadTickets( ticketsFile, tickets);}
		catch ( FileNotFoundException e){
			System.out.printf(
				"Tickets file not found: %s\n", accountsFile);}
		//try to load the transactions file
		try { loadTransactions( transactionsFile, transactions);}
		catch ( FileNotFoundException e){
			System.out.printf(
				"Transactions file not found: %s\n", accountsFile);}

		// Apply Transactions
		for( Transaction t : transactions)
			try{ t.applyTo( accounts, tickets);}
			catch( TransactionException e){}

		// Write Data
		//try to write the accounts file
		try { writeAccounts( outputAccountsFile, accounts);}
		catch ( FileNotFoundException e){
			System.out.println(e);}
		//try to write the tickets file
		try { writeTickets( outputTicketsFile, tickets);}
		catch ( FileNotFoundException e){
			System.out.println(e);}
	}

	// Auxiliary Functions

	//Data load functions
	private static void loadAccounts(
		String file, Vector<Account> accounts)
			throws FileNotFoundException {
		try {
			//open the file
			Scanner in = new Scanner( new File( file));
			int lineNumber = 0;
			//while eof is not reached
			while( in.hasNextLine()){
				lineNumber++;
				//read the line as a Account, then add it
				try { accounts.add( new Account( in.nextLine()));}
				//catch badly formatted lines
				catch ( DataFormatException e){
					System.out.printf(
						"[%s: %d] %s\n",
						file, lineNumber, e);}}
			//done - close file
			System.out.println(
				"Done loading accounts: End of file reached.");
			in.close();}
		//catch missing file - throw them up the call stack
		catch( FileNotFoundException e){
			throw( e);}}

	private static void loadTickets(
		String file, Vector<Ticket> tickets)
			throws FileNotFoundException {
		try {
			//open the file
			Scanner in = new Scanner( new File( file));
			int lineNumber = 0;
			//while eof is not reached
			while( in.hasNextLine()){
				lineNumber++;
				//read the line as a Ticket, then add it
				try { tickets.add( new Ticket( in.nextLine()));}
				//catch badly formatted lines
				catch ( DataFormatException e){
					System.out.printf(
						"[%s: %d] %s\n",
						file, lineNumber, e);}}
			//done - close file
			System.out.println(
				"Done loading tickets: End of file reached.");
			in.close();}
		//catch missing file - throw them up the call stack
		catch( FileNotFoundException e){
			throw( e);}}

	private static void loadTransactions(
		String file, Vector<Transaction> transactions)
			throws FileNotFoundException {
		try { 
			//open the file
			Scanner in = new Scanner( new File( file));
			int lineNumber = 0;
			boolean terminatorReached = false;
			//while neither eof nor terminator is reached
			while( in.hasNextLine() && ! terminatorReached){
				lineNumber++;
				//read a the line, then open a scanner on it
				String line = in.nextLine();
				Scanner lineParser = new Scanner( line);
				try{
					//read the first token in the line as a code
					int code = lineParser.nextInt();
					//use the code to select the type of transaction, then add it
					switch( code){
						//check for the terminator line
						case 0:
							System.out.println("Done loading transactions: Terminator transaction reached.");
							terminatorReached = true;
							break;
						//read the rest line as an AddCredit Transaction
						case transaction.AddCredit.code:
							transactions.add( new transaction.AddCredit(
								lineParser.nextLine().substring(1)));
							break;
						//read the rest line as a Buy Transaction
						case transaction.Buy.code:
							transactions.add( new transaction.Buy(
								lineParser.nextLine().substring(1)));
							break;
						//read the rest line as a Create Transaction
						case transaction.Create.code:
							transactions.add( new transaction.Create(
								lineParser.nextLine().substring(1)));
							break;
						//read the rest line as a Delete Transaction
						case transaction.Delete.code:
							transactions.add( new transaction.Delete(
								lineParser.nextLine().substring(1)));
							break;
						//read the rest line as a Refund Transaction
						case transaction.Refund.code:
							transactions.add( new transaction.Refund(
								lineParser.nextLine().substring(1)));
							break;
						//read the rest line as a Sell Transaction
						case transaction.Sell.code:
							transactions.add( new transaction.Sell(
								lineParser.nextLine().substring(1)));
							break;
						//check for invalid code characters
						default:
							throw new NumberFormatException();}}
				//catch invalid data formats
				catch( DataFormatException e){
					System.out.printf(
						"[%s: %d] %s\n",
						file, lineNumber, e);}
				//catch invalid transaction codes
				catch( NumberFormatException e){
					System.out.printf(
						"[%s: %d] Invalid transaction code.\n",
						file, lineNumber);
					break;}
				//catch the case of an empty line after the code
				catch( java.util.NoSuchElementException e){
					System.out.printf(
						"[%s: %d] Missing data\n",
						file, lineNumber);}}
			//done - close file
			System.out.println(
				"Done loading transactions: End of file reached.");
			in.close();}
		//catch missing file - throw them up the call stack
		catch( FileNotFoundException e){
			throw( e);}}

	//Data write functions
	private static void writeAccounts(
		String file, Vector<Account> accounts)
			throws FileNotFoundException {
		//open the file
		PrintStream out = new PrintStream( file);
		//write every account
		for( Account account : accounts)
			out.println( account);
		//close the file
		out.close();}

	private static void writeTickets(
		String file, Vector<Ticket> tickets)
			throws FileNotFoundException {
		//open the file
		PrintStream out = new PrintStream( file);
		//write every ticket
		for( Ticket ticket : tickets)
			out.println( ticket);
		//close the file
		out.close();}
}