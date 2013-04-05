package transaction;

//library imports
import java.util.Vector;
import java.util.zip.DataFormatException;

//local imports
import assets.*;

/** 
 * @class 	Buy
 * @brief 	Represents a 'buy' transaction.
 **/
public class Buy extends Transaction {
	//static field that identifies the transaction to the server
	public static final int code = 3;

	//Parameters for the Buy Transaction
	public String eventName;	//eventname of which the tickets to
	public String seller;		//username of seller
	public int numTickets;		//number of tickets to buy
	
	/**
	 * Constructs a buy transaction given the text line from a merged DTF (minus the code at the beginning
	 * that was extracted by NTSServer).
	 */
	public Buy( String s) throws DataFormatException {
		//read remaining portion of line from merged dtf, extracting the necesary parameters
		//of this buy transact
		
		this.eventName  = s.substring(0, Ticket.eventName_size-1).trim();
		
		this.seller     = s.substring(Ticket.eventName_size+1, Ticket.eventName_size+1 + Ticket.username_size-1);
		
		this.numTickets = Integer.parseInt( s.substring( Ticket.eventName_size+1 + Ticket.username_size + 1, Ticket.eventName_size+1 + Ticket.username_size + 1 + 2) );
		
	}
	
	/**
	 * Applies this buy transaction, updating the given vectors of accounts and available tickets 
	 * accordingly.
	 */
	public void applyTo(Vector<Account> accounts, Vector<Ticket> tickets) throws TransactionException {	
		
		//Search the Vector of tickets for a ticket(s) with the specified seller and event,
		//take note of the maximum quantity of tickets available from the seller to the event
		int MaxTickets = 0;
		int MaxTickets_TicketIndex = 0; //index into tickets,of ticket with this largest quantity
		for(int i = 0;  i<tickets.size();  i++)
			if( tickets.get(i).username.equals(this.seller) && tickets.get(i).eventName.equals(this.eventName) ) {
				if( tickets.get(i).quantity > MaxTickets )
				{
					MaxTickets = tickets.get(i).quantity;
					MaxTickets_TicketIndex = i;					
				}
			}
		
		//if 0 tickets available or not enough tickets to the seller/eventname, purchase can not be conducted
		if( MaxTickets == 0 || this.numTickets > MaxTickets ) 
			throw new TransactionException(); //"Insufficient tickets are available to the specified event, from the specified seller."
		
		//Check if this user has enough credit to purchase the tickets
		
	}

}