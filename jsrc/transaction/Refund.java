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
	public static final int code = 5;
	public Refund( String s) throws DataFormatException {
		System.out.println(s);}
	public void applyTo (
		Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException{}
}