package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

/** @class Delete class represents a 'delete' transaction.
 **/
public class Delete extends Transaction {
	//static field that identifies the transaction to the server
	public static final int code = 2;
	
	public static final int username_size  = 15;
	public static final int credit_size = 6;
	public static final int usertype_size = 2;
	
	//Delete Transaction Parameters
	public String username; //username of new account to be deleted
	public int type; //usertype for the specified user to be deleted
	public int credit; //initial account balance for the user account to be deleted
	
	public String deleteTransactionLine;
	
	public Delete( String s) throws DataFormatException {
		//read and extract fields from the transaction string
		this.username = s.substring(0,username_size-1).trim();
				
		if(	s.substring(username_size+1,username_size+1+usertype_size-1).toUpperCase().equals("AA") )
			this.type = 0;
		else if( s.substring(username_size+1,username_size+1+usertype_size-1).toUpperCase().equals("BS") )
			this.type = 1;
		else if( s.substring(username_size+1,username_size+1+usertype_size-1).toUpperCase().equals("SS") )
			this.type = 2;
		else if( s.substring(username_size+1,username_size+1+usertype_size-1).toUpperCase().equals("FS") )
			this.type = 3;
				
		//extract integer portion of ticket price (in hundreds of cents)
		this.credit = 100* Integer.parseInt( s.substring( username_size + 1 + usertype_size + 1, username_size + 1 + usertype_size + 1 + 2 ) );

		//now extract decimal portion adding it to ticket price (# of cents)
		this.credit += Integer.parseInt( s.substring( username_size + 1 + usertype_size + 1, username_size + 1 + usertype_size + 1 + 2 ) );
		System.out.println(s);		
	
	}
	
	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets) throws TransactionException{
			//can alternatively use vector<Account>.contains 
			if (accounts.indexOf(this.username) != -1){ //if specified username of the account to be deleted is found
				accounts.remove(accounts.indexOf(this.username));}}
	

	private boolean isInteger(String s) {
	    try { 
	        Integer.parseInt(s); 
	    } catch(NumberFormatException e) { 
	        return false;}
	    return true;}}
