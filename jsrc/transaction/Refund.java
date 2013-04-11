package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

/** @class Refund
 * @brief Represents a 'refund' transaction.
 **/
public class Refund extends Transaction {
	//static field that identifies the transaction to the server
	public static final int code = 5;
	public static final int username_size  = 15;
	String buyer_name;
	String seller_name;
	int amount;
	public Refund( String line) throws DataFormatException {
		//current index in the line
		int i = 0;
		
		//extract
		this.buyer_name = line.substring( i, Account.username_size).trim();
		//validate
		if( ! this.buyer_name.matches(""))
			throw new DataFormatException("Invalid buyer username field");
		//increment i
		i += Account.username_size + Account.token_size;
		
		//extract
		this.seller_name = line.substring( i, Account.username_size).trim();
		//validate
		if( ! this.seller_name.matches(""))
			throw new DataFormatException("Invalid seller username field");
		//increment i
		i += Account.username_size + Account.token_size;

		//extract dollars
		String dollars = line.substring( i, i + Account.dollars_size);
		i += Account.dollars_size + 1;
		//extract cents
		String cents = line.substring( i, i + Account.cents_size);
		try{
			this.amount =
				Integer.parseInt( dollars)*100 +
				Integer.parseInt( cents);
		}
		catch( NumberFormatException e){
			throw new DataFormatException("Invalid credit field");}
		//validate
		if( amount < 0)
			throw new DataFormatException("Credit field too small");
		if( amount > Math.pow(10,
				Account.dollars_size + Account.cents_size) - 1)
			throw new DataFormatException("Credit field too large");
	}

	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException{
		int buyer_i = accounts.indexOf(
			new Account( buyer_name, 0,0));
		int seller_i = accounts.indexOf(
			new Account( seller_name, 0,0));
		if( buyer_i < 0)
			throw new TransactionException("Buyer username not found");
		if( seller_i < 0)
			throw new TransactionException("Seller username not found");
		if( accounts.get(buyer_i).credit + amount > Account.maxCredit())
			throw new TransactionException("Buyer has too much credit");
		if( accounts.get(seller_i).credit - amount < 0)
			throw new TransactionException("Seller has too little credit");
		accounts.get(buyer_i).credit += amount;
		accounts.get(seller_i).credit -= amount;
	}
}


