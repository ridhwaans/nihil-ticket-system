
package assets;

//library imports
import java.util.zip.DataFormatException;

/** @class Ticket
 * @brief The Java representation of a ticket.
 * 
 * Represents a ticket line from an available tickets file, containing a quantity of tickets from being sold from some seller, to some event.
 **/
public class Ticket {
	//Eventname that the tickets are being sold to
	public String 	eventName;
	//Number of tickets being sold
	public int quantity;
	//Ticket Price In Cents
	public int price;	
	//Useranme of Seller
	public String username;
	
	public static final int eventName_size = 19;
	public static final int quantity_size  =  3;
	public static final int price_size     =  6;
	public static final int username_size  = 15;
	public static final int token_size  = 1;
	
	/**
	 * Constructs a new Ticket object, from the given line of text
	 * from the available tickets file.
	 **/
	public Ticket(String line) throws DataFormatException {
		if( line.length() != 
				eventName_size + token_size +
				quantity_size + token_size +
				price_size + token_size +
				username_size)
			throw new DataFormatException("Can not contruct ticket: Line from ATF is not of correct length!");
		
		int currIndex = 0;
		this.eventName = 	line.substring( currIndex, currIndex + eventName_size);
		
		currIndex 	   += 	eventName_size + 1;
		this.username  = 	line.substring( currIndex, currIndex + username_size - 1);
		
		currIndex 	   += 	username_size + 1;
		this.quantity  = 	Integer.parseInt( line.substring(currIndex, currIndex + quantity_size - 1 ));
		
		currIndex	   +=   quantity_size + 1;
		this.price 	   = 	0;
		this.price     += 	100 * Integer.parseInt( line.substring(currIndex, currIndex + 2) );
		currIndex 	   +=   4;	//skip first 3 digits of price and the period
		this.price     += 	Integer.parseInt( line.substring(currIndex, currIndex + 1));
	}

	
	/**
	 * Constructs a ticket object representing a group of 'quantity' number of tickets
	 * to some event, being sold from the specified seller (username) 
	 **/
	public Ticket(String eventName, int quantity, int price, String username)
	{
		this.eventName = eventName;
		this.quantity = quantity;
		this.price = price;
		this.username = username;
	}
	
	
	/**
	 *  Returns the string representation of this ticket, in a format suitable to be written to an available tickets file.
	 **/
	public String toString() {
		String LineString = "";
		
		LineString += padString( this.eventName, this.eventName_size );
		LineString += " ";
		LineString += padString( this.username,  this.username_size  );
		LineString += " ";
		LineString += padString( Integer.toString(quantity), this.quantity_size );
		LineString += " ";
		LineString += padString( Integer.toString(price / 100), 3 );
		LineString += ".";
		LineString += padString( Integer.toString(price % 100), 2 );		
		
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
	
	
}