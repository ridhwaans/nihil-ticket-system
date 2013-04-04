package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;
//local imports
import assets.*;

/** @class Delete
 * @brief Represents a 'delete' transaction.
 **/
public class Delete extends Transaction {
	public static final int code = 2;
	public String deleteTransactionLine;
	
	public Delete( String s) throws DataFormatException {
		System.out.println(s);
		deleteTransactionLine = s;}
	
	public void applyTo (Vector<Account> accounts, Vector<Ticket> tickets) throws TransactionException{
		boolean validLine= true; //Use boolean flag to determine if all fields in input string parameter line are valid
		
		String username;
		int type=0;
		int credit=0;
		
		int CurIndex = 0;
		username =  deleteTransactionLine.substring(CurIndex, CurIndex + username_size -1);
		CurIndex += username_size + 1;
		
		if(	deleteTransactionLine.substring(CurIndex, CurIndex + 2).toLowerCase().equals("AA") )
			type = 0;
		else if( deleteTransactionLine.substring(CurIndex, CurIndex + 2).toLowerCase().equals("BS") )
			type = 1;
		else if( deleteTransactionLine.substring(CurIndex, CurIndex + 2).toLowerCase().equals("SS") )
			type = 2;
		else if( deleteTransactionLine.substring(CurIndex, CurIndex + 2).toLowerCase().equals("FS") )
			type = 3;
		else
			validLine = false;
		
		CurIndex += 2 + 1;
		
		if ((isInteger(deleteTransactionLine.substring(CurIndex, CurIndex + 2))==true) && (isInteger(deleteTransactionLine.substring(CurIndex+4, CurIndex+4+1))==true))
			credit = Integer.parseInt(deleteTransactionLine.substring(CurIndex, CurIndex + 2))*100  +  Integer.parseInt(deleteTransactionLine.substring(CurIndex+4, CurIndex+4+1)); 
		else
			validLine = false;
	    
		if (validLine == true){ //if true, apply the transaction
			Account a = new Account(username, type, credit);
			accounts.add(a);
			if (accounts.indexOf(username) == -1){ //or contains
				accounts.remove(accounts.indexOf(username));}}}
	

	private boolean isInteger(String s) {
	    try { 
	        Integer.parseInt(s); 
	    } catch(NumberFormatException e) { 
	        return false;}
	    return true;}}
