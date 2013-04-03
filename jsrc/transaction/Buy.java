package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

/** @class Buy
 * @brief Represents a 'buy' transaction.
 **/
public class Buy extends Transaction {
	
	//static field that identifies the transaction to the server
	public static final int code = 3;
	
	public Buy( String s) throws DataFormatException {
		System.out.println(s);
	}
	
	public void applyTo(
		Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException {	
		
	}

}