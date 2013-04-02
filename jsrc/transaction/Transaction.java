package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

public abstract class Transaction {
	public abstract void applyTo (
		Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException;
}