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

			buyerUsername = s.substring(3, 15);
			buyerUsername.replaceAll(" ","");
			sellerUsername = s.substring(18, 15);
			sellerUsername.replaceAll(" ","");
			refund = Integer.parseInt(s.substring(35, 9));

		}
		System.out.println(s);}
	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets)throws TransactionException{
		FileWriter fstream = new FileWriter("data.cua");
		BufferedWriter out = new BufferedWriter(fstream);
		out.write(buyerUsername);
		out.write(refund);
		out.write(sellerUsername);
		out.write(refund);
		out.close();
	}

}
