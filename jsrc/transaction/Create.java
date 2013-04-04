package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

/** @class Create class represents a 'create' transaction.
 **/
public class Create extends Transaction {
	public static final int code = 1;
	
	
	public static final int username_size  = 15;
	public static final int credit_size = 6;
	public static final int usertype_size = 2;
	
	//Create Transaction Parameters
	public String username; //username of new account to be created
	public int type; //usertype for the specified user to be created
	public int credit; //initial account balance for the user account to be created
	
	
	/**
	* Constructs a create transaction object with the necessary field attributes upon receiving and input 
	* string line parameter from the merged transaction file
	*/
	public Create( String s) throws DataFormatException {
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
			accounts.add(new Account(this.username, this.type, this.credit));}
	
	
	private boolean isInteger(String s) {
	    try { 
	        Integer.parseInt(s); 
	    } catch(NumberFormatException e) { 
	        return false;}
	    return true;}}
