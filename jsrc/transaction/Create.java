package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

/** @class Create class represents a 'create' transaction.
 *
 **/
public class Create extends Transaction {
	//static field that identifies the transaction to the server
	public static final int code = 1;
	
	//Create Transaction Parameters
	//username of new account to be created
	public String username;
	//usertype for the specified user to be created
	public int type;
	//initial account balance for the user account to be created
	public int credit;
	
	/**
	* Constructs a create transaction object with the necessary field attributes upon receiving and input 
	* string line parameter from the merged transaction file
	*/
	public Create( String line) throws DataFormatException {
		int i = 0;
		this.username = line.substring( i, Account.username_size).trim();
		i += Account.username_size + Account.token_size;
		
		String typeString = line.substring( i, i + Account.type_size);
		if( typeString.equals("AA"))
			this.type = Account.Admin;
		else if( typeString.equals("BS"))
			this.type = Account.Buy;
		else if( typeString.equals("SS"))
			this.type = Account.Sell;
		else if( typeString.equals("FS"))
			this.type = Account.Full;

		String dollars = line.substring( i, i + Account.dollars_size);
		i += Account.dollars_size + 1;
		//get the cents portion of the line
		String cents = line.substring( i, i + Account.cents_size);
		try{
			this.credit =
				Integer.parseInt( dollars)*100 +
				Integer.parseInt( cents);
		}
		catch( NumberFormatException e){
			throw new DataFormatException("Invalid credit fields");}
	}
	
	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets) throws TransactionException{
		//validation?
		accounts.add(new Account(this.username, this.type, this.credit));}
}
