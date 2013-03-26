package transaction;

//library imports
import java.util.Vector;
//local imports
import assets.*;

public abstract class Transaction {
	protected Transaction ( String line){}
	public abstract void applyTo (
		Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException;
}