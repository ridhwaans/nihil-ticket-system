package transaction;

//library imports
import java.util.Vector;
//local imports
import assets.*;

public class Create {
	public Create( String s){
		System.out.println(s);}
	public void applyTo (
		Vector<Account> accounts, Vector<Ticket> tickets)
			throws TransactionException{}
}