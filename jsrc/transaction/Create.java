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
		//current index in the line
		int i = 0;
		//extract
		this.username = line.substring( i, Account.username_size).trim();
		//validate
		if( ! this.username.matches(""))
			throw new DataFormatException("Invalid username field");
		if( this.username.matches("([A-Za-z0-9_]+)")==false)
			throw new DataFormatException("Invalid username field");
		if (this.username.trim().length() <= 0)
			throw new DataFormatException("Username field too small");
		if (this.username.trim().length() > Account.username_size)
			throw new DataFormatException("Username field too large");
		//increment i
		i += Account.username_size + Account.token_size;

		//extract
		String typeString = line.substring( i, i + Account.type_size);
		if( typeString.equals("AA"))
			this.type = Account.Admin;
		else if( typeString.equals("BS"))
			this.type = Account.Buy;
		else if( typeString.equals("SS"))
			this.type = Account.Sell;
		else if( typeString.equals("FS"))
			this.type = Account.Full;
		//validate
		else
			throw new DataFormatException("Invalid type field");

		//extract dollars
		String dollars = line.substring( i, i + Account.dollars_size);
		i += Account.dollars_size + 1;
		//extract cents
		String cents = line.substring( i, i + Account.cents_size);
		try{
			this.credit =
					Integer.parseInt( dollars)*100 +
					Integer.parseInt( cents);
		}
		catch( NumberFormatException e){
			throw new DataFormatException("Invalid credit field");}
		//Validate credit
		if( credit < 0)
			throw new DataFormatException("Credit field too small");
		if( credit > Math.pow(10,
				Account.dollars_size + Account.cents_size) - 1)
			throw new DataFormatException("Credit field too large");
	}

	/**
	 * Applies a specified Create transaction by carrying out and adding a new Account to the Accounts vector list 
	 */
	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException{
		
		//Username field validation
		if( this.username.matches("([A-Za-z0-9_]+)")==false)
			throw new TransactionException("Invalid username field");
		//if(( 0 <= this.username.trim().length() && this.username.trim().length() <= Account.username_size)==false)
		if (this.username.trim().length() <= 0)
			throw new TransactionException("Username field too small");
		if (this.username.trim().length() > Account.username_size)
			throw new TransactionException("Username field too large");

		//Type field validation
		if(( 0 <= this.type && this.type < 3)==false)
			throw new TransactionException("Invalid type field");

		//Credit field validation
		if( this.credit < 0)
			throw new TransactionException("Credit field too small");
		if( this.credit > Math.pow(10,
				Account.dollars_size + Account.cents_size) - 1)
			throw new TransactionException("Credit field too large");
			
		Account account = new Account(this.username, this.type, this.credit);
		if( ! accounts.contains( account))
			accounts.add(account);
		else //specified user, account already exists
			throw new TransactionException("Username already exists");
	}
}