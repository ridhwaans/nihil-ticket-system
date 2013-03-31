package assets;

//library imports
import java.util.zip.DataFormatException;


/**
 * Represents a user account, with a specified account type,
 * amount of credit, and username.
 */
public class Account {
	private String username;
	private    int type;
	private    int credit;
	
	public static final int Admin =	0;
	public static final int Buy   =	1;
	public static final int Sell  =	2;
	public static final int Full  =	3;
	
	
	public static final int username_size  = 15;
	
	/**
	 * Constructs and sets up an account object using a line of text 
	 * from the current user accounts file.
	 */
	public Account(String Line) throws DataFormatException {
		int CurIndex = 0;
		
		this.username = Line.substring(CurIndex, CurIndex + username_size -1);
		
		CurIndex += username_size + 1;
		if( 	 Line.substring(CurIndex, CurIndex + 2).toLowerCase().equals("AA") )
			this.type = Admin;
		else if( Line.substring(CurIndex, CurIndex + 2).toLowerCase().equals("BS") )
			this.type = Buy;
		else if( Line.substring(CurIndex, CurIndex + 2).toLowerCase().equals("SS") )
			this.type = Sell;
		else
			this.type = Full;
		CurIndex += 2 + 1;
		
		this.credit = Integer.parseInt(Line.substring(CurIndex, CurIndex + 2))*100  +  Integer.parseInt(Line.substring(CurIndex+4, CurIndex+4+1)); 
	}
	
	
	public String getUsername()
	{
		return this.username;
	}
	
	public int getType()
	{
		return this.type;
	}
	
	public int getCredit()
	{
		return this.credit;
	}
	
	public void setCredit(int NewAmountOfCredit)
	{
		this.credit = NewAmountOfCredit;
	}
	
	
	
	
	
}