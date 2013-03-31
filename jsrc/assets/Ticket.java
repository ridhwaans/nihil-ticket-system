
package assets;

//library imports
import java.util.zip.DataFormatException;


/**
 * Represents a ticket line from an available tickets file, containing
 * a quantity of tickets from being sold from some seller, to some event.
 */
public class Ticket {
	private String 	eventName;		//Eventname that the tickets are being sold to
	private int 	quantity;		//Number of tickets being sold
	private int 	price;			//Ticket Price In Cents
	private String 	username;		//Useranme of Seller
	
	public static final int eventName_size = 19;
	public static final int quantity_size  =  3;
	public static final int price_size     =  6;
	public static final int username_size  = 15;
	
	
	/**
	 * Constructs a new Ticket object, from the given line of text
     * from the available tickets file.
     */
	public Ticket(String ATFLine) throws DataFormatException {
		int CurIndex = 0;
		this.eventName = 	ATFLine.substring( CurIndex, CurIndex + eventName_size-1);
		CurIndex 	   += 	eventName_size + 1;
		this.username  = 	ATFLine.substring( CurIndex, CurIndex + username_size - 1);
		CurIndex 	   += 	username_size + 1;
		this.quantity  = 	Integer.parseInt( ATFLine.substring(CurIndex, CurIndex + quantity_size - 1 ));
		CurIndex	   +=   quantity_size + 1;
		this.price 	   = 	0;
		this.price     += 	100 * Integer.parseInt( ATFLine.substring(CurIndex, CurIndex + 2) );
		CurIndex 	   +=   4;	//skip first 3 digits of price and the period
		this.price     += 	Integer.parseInt( ATFLine.substring(CurIndex, CurIndex + 1));
	}


	/**
     *  Returns the string representation of this ticket, in a format
     *  suitable to be written to an available tickets file.
     */
	public String toString() {
		String LineString = "";
		
		LineString += padString( this.eventName, this.eventName_size );
		LineString += " ";
		LineString += padString( this.username,  this.username_size  );
		LineString += " ";
		LineString += padString( Integer.toString(quantity), this.quantity_size );
		LineString += " ";
		LineString += padString( Integer.toString(price / 100) );
		LineString += ".";
		LineString += padString( Integer.toString(price % 100) );		
		
		return LineString;
	}	
	
	
	/**
	 * Pads the given string adding spaces to the end of it untill its size
	 * is equal to NumOfChars.
	 */
	private String padString(String S, int NumOfChars)
	{
		if( S.length() >= NumOfChars ) return S;
		int SpacesToAdd = NumOfChars - S.length();
		for(int i = 0;  i<SpacesToAdd;  i++)
			S += " ";
		return S;
	}
	
	
	public String getEventName()
	{
		return this.eventName;
	}
	
	
	public int getQuantity()
	{
		return this.quantity;
	}

	
	public int getPrice()
	{
		return this.price;
	}
	
	
	public String  getUsername()
	{
		return this.username;
	}
	
	


}




