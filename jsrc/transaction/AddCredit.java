package transaction;

//library imports
import java.util.Vector;
import java.io.*;
//local imports
import assets.*;

public class AddCredit extends Transaction{
	public static final int code = 6;
	String username;
	int type;
	int credit;
	public AddCredit( String s){
		FileInputStream fstream = new FileInputStream("*.dtf");
		DataInputStream in = new DataInputStream(fstream);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		while ((s = br.readLine()) != null){

			username = s.substring(3, username_size-1);
			credit = Integer.parseInt(s.substring(3 + username+1, 9));
		}

		System.out.println(s);
	}
	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets)throws TransactionException{
		account.credit += credit;
	}
}



