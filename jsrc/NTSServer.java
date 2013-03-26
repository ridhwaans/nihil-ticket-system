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
		String accountsFile;
		if( args.length > 0)
			accountsFile = args[0];
		else{
			accountsFile = "resources/data.cua";
			System.out.println(
				"Accounts file argument not found, using " + accountsFile);}
		String ticketsFile;
		if( args.length > 1)
			ticketsFile = args[1];
		else{
			ticketsFile = "resources/data.atf";
			System.out.println(
				"Tickets file argument not found, using " + ticketsFile);}
		String transactionsFile;
		if( args.length > 2)
			transactionsFile = args[2];
		else{
			transactionsFile = "output.dtf";
			System.out.println(
				"Transactions file argument not found, using " + transactionsFile);}

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

		//aply every transaction
		for( Transaction t : transactions)
			try{ t.applyTo( accounts, tickets);}
			catch( TransactionException e){}

		//try to write the accounts file
		try { writeAccounts( accountsFile, accounts);}
		catch ( FileNotFoundException e){
			System.out.println(e);}
		//try to write the tickets file
		try { writeTickets( ticketsFile, tickets);}
		catch ( FileNotFoundException e){
			System.out.println(e);}
	}

	//data load functions
	private static void loadAccounts(
		String file, Vector<Account> accounts)
			throws FileNotFoundException {
		try { 
			Scanner in = new Scanner( new File( file));
			while( in.hasNextLine()){
				try { accounts.add( new Account( in.nextLine()));}
				catch ( DataFormatException e){
					System.out.println(e);}}}
		catch ( FileNotFoundException e){
			throw( e);}}

	private static void loadTickets(
		String file, Vector<Ticket> tickets)
			throws FileNotFoundException {}
	private static void loadTransactions(
		String file, Vector<Transaction> transactions)
			throws FileNotFoundException {}

	//data write functions
	private static void writeAccounts(
		String file, Vector<Account> accounts)
			throws FileNotFoundException {}
	private static void writeTickets(
		String file, Vector<Ticket> tickets)
			throws FileNotFoundException {}
}