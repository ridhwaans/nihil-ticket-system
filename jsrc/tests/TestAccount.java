package tests;

//local includes
import assets.*;
//library includes
import java.util.zip.DataFormatException;
import org.junit.Test;
import org.junit.Ignore;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import static org.junit.Assert.assertTrue;

@RunWith(JUnit4.class)
public class TestAccount {
	public static void main( String[] args) throws DataFormatException{
		String line = "manager         AA 001000.00";
		Account manager = new Account( line);
		System.out.println(manager.toString());
		System.out.println(line);}

	@Test
	public void testRead() throws DataFormatException {
		String line = "manager         AA 001000.00";
		Account account = new Account( line);
		assertTrue( line.equals( account.toString()));
	}

	@Test
	public void testWrite() throws DataFormatException {
		Account account = new Account( "manager", Account.Admin, 100);
		assertTrue( account.equals( new Account( account.toString())));
	}

	@Test
	public void testEquals() {
		assertTrue(
			new Account("name", 0, 0).equals(
			new Account("name", 0, 0)));
		/*assertEquals(
			new Account("name", 0, 0),
			new Account("name", 0, 1));
		assertEquals(
			new Account("name", 0, 0),
			new Account("name", 1, 0));
		assertEquals(
			new Account("name", 0, 0),
			new Account("name", 1, 1));*/
	}
}