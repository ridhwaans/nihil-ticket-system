//library imports
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;
import transaction.*;

public class NTSServer {
	public static void main( String[] args){
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

		// Load Data
		//try to load the accounts file
		try { loadAccounts( accountsFile, accounts);}
		catch ( FileNotFoundException e){
			System.out.println(e);}
		//try to load the tickets file
		try { loadTickets( ticketsFile, tickets);}
		catch ( FileNotFoundException e){
			System.out.println(e);}
		//try to load the transactions file
		try { loadTransactions( transactionsFile, transactions);}
		catch ( FileNotFoundException e){
			System.out.println(e);}

		// Apply Transactions
		for( Transaction t : transactions)
			try{ t.applyTo( accounts, tickets);}
			catch( TransactionException e){}

		// Write Data
		//try to write the accounts file
		try { writeAccounts( accountsFile, accounts);}
		catch ( FileNotFoundException e){
			System.out.println(e);}
		//try to write the tickets file
		try { writeTickets( ticketsFile, tickets);}
		catch ( FileNotFoundException e){
			System.out.println(e);}
	}

	// Auxiliary Functions

	//Data load functions
	private static void loadAccounts(
		String file, Vector<Account> accounts)
			throws FileNotFoundException {
		try { 
			Scanner in = new Scanner( new File( file));
			while( in.hasNextLine()){
				try { accounts.add( new Account( in.nextLine()));}
				catch ( DataFormatException e){
					System.out.println(e);}}
			in.close();}
		catch( FileNotFoundException e){
			throw( e);}}

	private static void loadTickets(
		String file, Vector<Ticket> tickets)
			throws FileNotFoundException {
		try { 
			Scanner in = new Scanner( new File( file));
			while( in.hasNextLine()){
				try { tickets.add( new Ticket( in.nextLine()));}
				catch ( DataFormatException e){
					System.out.println(e);}}
			in.close();}
		catch( FileNotFoundException e){
			throw( e);}}

	private static void loadTransactions(
		String file, Vector<Transaction> transactions)
			throws FileNotFoundException {
		try { 
			Scanner in = new Scanner( new File( file));
			int lineNumber = 0;
			while( in.hasNextLine()){
				lineNumber++;
				String line = in.nextLine();
				Scanner lineParser = new Scanner( line);
				try{
					int code = lineParser.nextInt();
					switch( code){
						case 0:
							System.out.println("Done loading transactions: Terminator transaction reached.");
						case transaction.Buy.code:
							transactions.add( new transaction.Buy(
								lineParser.nextLine().substring(1)));
							break;
						default:
							System.out.println("asdfj");
							break;}}
				catch( DataFormatException e){
					System.out.println(e);}
				catch( NumberFormatException e){
					System.out.printf(
						"[%s: %d] Invalid transaction code.\n",
						file, lineNumber);
					break;}
				catch( java.util.NoSuchElementException e){}}
			System.out.println("Done loading transactions: End of file reached.");
			in.close();}
		catch( FileNotFoundException e){
			throw( e);}}

	//Data write functions
	private static void writeAccounts(
		String file, Vector<Account> accounts)
			throws FileNotFoundException {}

	private static void writeTickets(
		String file, Vector<Ticket> tickets)
			throws FileNotFoundException {}
}