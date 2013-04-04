package transaction;

//library imports
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

/** @class Refund
 * @brief Represents a 'refund' transaction.
 **/
public class Refund extends Transaction {
	public static final int code = 5;
	String buyerUsername;
	String sellerUsername;
	int refund;
	public Refund( String s) throws DataFormatException {
		FileInputStream fstream = new FileInputStream("*.dtf");
		DataInputStream in = new DataInputStream(fstream);
		BufferedReader buf = new BufferedReader(new InputStreamReader(in));
		while ((s = buf.readLine()) != null){

			buyerUsername = s.substring(3, username-1);
			sellerUsername = s.substring(3+username+1 , username-1);
			refund = Integer.parseInt(s.substring(3+username+1+username+1, 9));

		}
		System.out.println(s);}
	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets)throws TransactionException{
	
		}
	}

}
