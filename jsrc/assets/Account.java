package assets;

//library imports
import java.util.zip.DataFormatException;

/** @class Account
 * @brief The Java representation of an account.
 * 
 * Represents a user account, with a specified account type, amount of credit, and username.
 **/
public class Account {
	public String username;
	public int type;
	public int credit;
	
	public static final int Admin =	0;
	public static final int Buy   =	1;
	public static final int Sell  =	2;
	public static final int Full  =	3;
	
	public static final int username_size  = 15;
	public static final int type_size = 2;
	public static final int credit_size = 9;
	public static final int dollars_size = 6;
	public static final int cents_size = credit_size - dollars_size - 1;
	public static final int token_size = 1;

	/**
	 * Constructs and sets up an account object using a line of text 
	 * from the current user accounts file.
	 **/
	public Account(String line) throws DataFormatException {
		if( line.length() != 
				username_size + token_size + 
				type_size + token_size + 
				dollars_size + token_size + 
				cents_size)
			throw new DataFormatException("Cannot construct Account: given incorrect ATF line size");

		int currIndex = 0;
		
		this.username = line.substring(currIndex, currIndex + username_size);
		currIndex += username_size + 1;

		String typeString = line.substring(
			currIndex, currIndex + type_size);
		if( typeString.equals("AA"))
			this.type = Admin;
		else if( typeString.equals("BS"))
			this.type = Buy;
		else if( typeString.equals("SS"))
			this.type = Sell;
		else if( typeString.equals("FS"))
			this.type = Full;
		else
			throw new DataFormatException("Invalid account type");
		currIndex += type_size + 1;
		
		//get the dollars portion of the line
		String dollars = line.substring(
			currIndex, currIndex + dollars_size);
		currIndex += dollars_size + 1;
		//get the cents portion of the line
		String cents = line.substring(
			currIndex, currIndex + cents_size);
		try{
			this.credit =
				Integer.parseInt( dollars)*100 +
				Integer.parseInt( cents);
		}
		catch( NumberFormatException e){
			throw new DataFormatException("Invalid credit fields");}
	}
	
	/**
	 * Constructs a new account object with the specified parameters.
	 * This is used by the Create transaction.
	 **/
	public Account(String username, int type, int credit) {
		this.username = username;
		this.type = type;
		this.credit = credit;
	}

	/**
	 *  Returns the string representation of this account, in a format suitable to be written to the current accounts file.
	 **/
	public String toString(){
		String typeString;
		switch( type){
			case Admin:
				typeString = "AA";
				break;
			case Buy:
				typeString = "BS";
				break;
			case Sell:
				typeString = "SS";
				break;
			case Full:
				typeString = "FS";
				break;
			default:
				typeString = "00";
				System.out.println("bad account type");
				break;
		}
		return String.format(
			"%"+username_size+"s %"+type_size+"s %0"+dollars_size+"d.%0"+cents_size+"d",
			username, typeString, credit/100, credit%100);
	}

	public boolean equals( Account other){
		return this.username.equals( other.username);
	}
	public static int maxCredit(){
		return (int) Math.pow(10, dollars_size + cents_size) - 1;
	}
}