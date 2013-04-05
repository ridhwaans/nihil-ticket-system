package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;

//local imports
import assets.*;

/** @class Sell
 * @brief Represents a 'sell' transaction.
 **/
public class Sell extends Transaction {
	//static field that identifies the transaction to the server
	public static final int code = 4;

	public static final int eventName_size = 19;
	public static final int quantity_size  =  3;
	public static final int price_size     =  6;
	public static final int username_size  = 15;
	
	//Sell Transaction Parameters
	public String eventName;	//eventname of which the tickets are being sold to
	public String seller;		//username of seller
	public int numTickets;		//number of tickets to sell
	public int ticketPrice;		//in cents
	
	/**
	 * Constructs a sell transaction object, using the (remainder of a) text from a line of the
	 * merged transaction file.
	 */
	public Sell( String s) throws DataFormatException {
		//read remaining portion of line from merged dtf, extracting the necesary parameters
		//of this sell transact
		
		this.eventName  = s.substring(0, eventName_size-1).trim();
		
		this.seller     = s.substring(eventName_size+1, eventName_size+1 + username_size-1);
		
		this.numTickets = Integer.parseInt( s.substring( eventName_size+1 + username_size + 1, eventName_size+1 + username_size + 1 + 2) );
		
		//extract integer portion of ticket price  (in hundreds of cents)
		this.ticketPrice = 100* Integer.parseInt( s.substring( eventName_size+1 + username_size + 1 + 3 + 1, eventName_size+1 + username_size + 1 + 3 + 1 + 2 ) );   
		
		//now extract decimal portion adding it to ticket price (# of cents)
		this.ticketPrice += Integer.parseInt( s.substring( eventName_size+1 + username_size + 1 + 3 + 1, eventName_size+1 + username_size + 1 + 3 + 1 + 2 ) );
		System.out.println(s);
	}
	
	/**
	 * Applies this sell transaction to the given vectors of tickets and accounts.
	 * 
	 * @param accounts	Vector of account classes, representing the systems currently
	 *                  available user accounts.
	 * @param tickets   Vector of tickets representing the systems current set of
	 *                  tickets being sold from various sellers.
	 */
	public void applyTo(Vector<Account> accounts, Vector<Ticket> tickets) throws TransactionException {
		
		//Create a new ticket object representing the tickets to be sold, with the parameters set up
		//during the constructor, then add this ticket object to the vector of tickets.
		tickets.add( new Ticket( this.eventName, this.quantity_size, this.ticketPrice, this.seller ) );
		
	}

}