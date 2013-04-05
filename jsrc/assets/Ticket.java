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
	public String eventName;
	//Number of tickets being sold
	public int quantity;
	//Ticket Price In Cents
	public int price;	
	//Useranme of Seller
	public String username;
	
	public static final int eventName_size = 19;
	public static final int quantity_size = 3;
	public static final int price_size = 6;
	public static final int dollars_size = 3;
	public static final int cents_size = price_size - dollars_size - 1;
	public static final int username_size = 15;
	public static final int token_size = 1;
	
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
			throw new DataFormatException("Line too long");
		
		int currIndex = 0;
		this.eventName = line.substring(
			currIndex, currIndex + eventName_size);
		currIndex += eventName_size + token_size;
		
		this.username = line.substring(
			currIndex, currIndex + username_size);
		currIndex += username_size + token_size;
		
		this.quantity = Integer.parseInt( line.substring(
			currIndex, currIndex + quantity_size));
		currIndex += quantity_size + 1;
		
		//get the dollars portion of the line
		String dollars = line.substring(currIndex, currIndex + dollars_size);
		currIndex += dollars_size + 1;
		//get the cents portion of the line
		String cents = line.substring(currIndex, currIndex + cents_size);

		try{
			this.price =
				Integer.parseInt( dollars)*100 +
				Integer.parseInt( cents);
		}
		catch( NumberFormatException e){
			throw new DataFormatException("Invalid credit fields");}
	}

	
	/**
	 * Constructs a ticket object representing a group of 'quantity' number of tickets
	 * to some event, being sold from the specified seller (username) 
	 **/
	public Ticket(String eventName, String username, int quantity, int price)
	{
		this.eventName = eventName;
		this.username = username;
		this.quantity = quantity;
		this.price = price;
	}
	
	
	/**
	 * Returns the string representation of this ticket, in a format suitable to be written to an available tickets file.
	 **/
	public String toString(){
		return String.format(
			"%"+eventName_size+"s %"+username_size+"s %0"+
				quantity_size+"d %0"+dollars_size+"d.%0"+cents_size+"d",
			eventName, username, quantity, price/100, price%100);
	}

	public boolean equals( Ticket other){
		return
			this.eventName.equals( other.eventName) &&
			this.username.equals( other.username);
	}
}