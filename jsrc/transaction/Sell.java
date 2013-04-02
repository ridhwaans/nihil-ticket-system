package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

/** @class Sell
 * @brief Represents a 'sell' transaction.
 **/
public class Sell extends Transaction {
	//static field that identifies the transaction to the server
	public static final int code = 4;

	public Sell( String s) throws DataFormatException {
		System.out.println(s);
	}
	
	public void applyTo(
		Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException {
		
	}

}