package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

public class AddCredit extends Transaction{
	//static field that identifies the transaction to the server
	public static final int code = 6;
	
	String username;
	int type;
	int credit;
	public AddCredit( String line) throws DataFormatException{
		//current index in the line
		int i = 0;
		//extract
		this.username = line.substring( i, Account.username_size).trim();
		//validate
		if( ! this.username.matches(""))
			throw new DataFormatException("Invalid username field");
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
		//validate
		if( credit < 0)
			throw new DataFormatException("Credit field too small");
		if( credit > Math.pow(10,
				Account.dollars_size + Account.cents_size) - 1)
			throw new DataFormatException("Credit field too large");
	}
	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets)	throws TransactionException{
		try{
			Account account = new Account(this.username, this.type, 0);
			int index = accounts.indexOf( account);
			accounts.get( index).credit += this.credit;}
		catch( ArrayIndexOutOfBoundsException e){}
	}
}



