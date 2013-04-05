package transaction;

//library imports
import java.util.Vector;
import java.io.*;
//local imports
import assets.*;

public class AddCredit extends Transaction{
	//static field that identifies the transaction to the server
	public static final int code = 6;
	
	String username;
	int type;
	int credit;
	public AddCredit( String s){
	

		this.username = s.substring(3, Account.username_size-1);
		this.credit = Integer.parseInt(s.substring(3 + Account.username_size+1, 9));
		

		System.out.println(s);
	}
	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets)throws TransactionException{
		//account.credit += credit;
	}
}



