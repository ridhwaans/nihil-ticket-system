package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

public class Create extends Transaction {
	public static final int code = 1;
	public Create( String s) throws DataFormatException {
		System.out.println(s);}
	public void applyTo (
		Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException{}
}