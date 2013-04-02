package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

/** @class AddCredit
 * @brief Represents an 'addcredit' transaction.
 **/
public class AddCredit extends Transaction {
	public static final int code = 6;
	public AddCredit( String s) throws DataFormatException {
		System.out.println(s);}
	public void applyTo (
		Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException{}
}