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
	String buyerUsername;
	String sellerUsername;
	int refund;
	public Refund( String s) throws DataFormatException {


		this.buyerUsername = s.substring(3, username_size - 1);
		this.sellerUsername = s.substring(3 + username_size + 1 , username_size-1);
		this.refund = Integer.parseInt(s.substring(3 + username_size + 1+username_size + 1, 9));

		//validate all fields

	}

	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException{
		//account[buyerUsername].credit += refund;
		//account[sellerUsername].credit -= refund;
	}
}


