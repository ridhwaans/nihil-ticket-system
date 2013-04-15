package tests;

import assets.*;
import transaction.*;

import java.util.Vector;
import java.util.zip.DataFormatException;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import static org.junit.Assert.assertEquals;
import org.junit.BeforeClass;
import org.junit.AfterClass;

/**
 * This TestCreate class is a JUnit testing class that exercises the constructor and different class associated methods to test 
 * different scenarios and cases of create transactions in the Nihil Ticket System
 */

@RunWith(JUnit4.class)
public class TestCreate {

	@BeforeClass
	public static void testSetup() {
	}

	@AfterClass
	public static void testCleanup() {
	}

	/**
	 * CreateTest 1: Test if a Create transaction object is constructed correctly with valid username, usertype and credit field values,
	 * Create parses and extracts lines with format "UUUUUUUUUUUUUUU TT CCCCCCCCC" (U username, T type, C credit)
	 * @throws DataFormatException
	 * @result Object of class Create is constructed with the specified username, type and credit
	 */
	@Test 
	public void testCreate() throws DataFormatException {
		System.out.println("CreateTest 1: Test if a Create transaction object is constructed correctly with valid data...");
		String line = "manager         AA 001000.00";				
		Create TestCreate = new Create( line);
		assertEquals( line, TestCreate.toString());
	}

	/**
	 * CreateTest 2: Tests if Create constructor catches and rejects invalid DTF lines of incorrect sizes, 
	 * line data format that is not "UUUUUUUUUUUUUUU TT CCCCCCCCC" (U username, T type, C credit)
	 * @throws DataFormatException
	 * @result Create constructor catches error in line parsing, DataFormatException is thrown
	 */
	@Test (expected = DataFormatException.class)
	public void testCreate_InvalidLine() throws DataFormatException {
		System.out.println("CreateTest 2: Tests if constructor rejects catches invalid DTF lines of incorrect sizes...");
		String line = "invalid DTF line"; 
		Create TestCreate = new Create( line);
	}

	/**
	 * CreateTest 3: Test if a Create transaction rejects object construction of invalid username field values (i.e. special characters)
	 * @throws DataFormatException
	 * @result Create constructor catches invalid username character error in line parsing, DataFormatException is thrown
	 */
	@Test (expected = DataFormatException.class)
	public void testCreate_InvalidUsername() throws DataFormatException {
		System.out.println("CreateTest 3: Test if a Create transaction catches invalid username field values, rejects object construction...");
		String line = "m@nag&r         AA 001000.00";
		Create TestCreate = new Create( line);
	}

	/**
	 * CreateTest 4: Test if a Create transaction rejects object construction if username is too large (username exceeds 15 character size limit)
	 * @throws DataFormatException
	 * @result Create constructor determines that extracted username substring is too long, catches username error in line parsing, DataFormatException is thrown
	 */
	@Test (expected = DataFormatException.class)
	public void testCreate_UsernameTooLarge() throws DataFormatException {
		System.out.println("CreateTest 4: Test if a Create transaction rejects object construction if username is too large...");
		String line = "username1111222344455555longggggg         AA 001000.00";
		Create TestCreate = new Create( line);
	}

	/**
	 * CreateTest 5: Test if a Create constructor while line parsing catches invalid type values (i.e. values that are not AA, BS, SS, FS) 
	 * @throws DataFormatException
	 * @result Create constructor catches invalid type value 'ZZ' after extracting substring, DataFormatException is thrown
	 */
	@Test (expected = DataFormatException.class)
	public void testCreate_InvalidUserType() throws DataFormatException {
		System.out.println("CreateTest 5: Test if a Create transaction rejects object construction of invalid usertype field values...");
		String line = "manager         ZZ 001000.00";
		Create TestCreate = new Create( line);
	}

	/**
	 * CreateTest 6: Test if a Create transaction rejects object construction if credit amount has invalid characters (not numeric)
	 * @throws DataFormatException
	 * @result Create constructor catches credit error with invalid amount value (because of invalid characters) from parsing, DataFormatException is thrown
	 */
	@Test (expected = DataFormatException.class)
	public void testCreate_InvalidCredit() throws DataFormatException {
		System.out.println("CreateTest 6: Test if a Create transaction rejects object construction if credit amount has invalid characters (not numeric)...");
		String line = "manager         AA invalid(.0";
		Create TestCreate = new Create( line);
	}

	/**
	 * CreateTest 7: Tests constructor's ability to catch credit amount values in DTFLine that have two or more invalid decimal places
	 * @throws DataFormatException
	 * @result Constructor catches erroneous credit amount, DataFormatException thrown
	 */
	@Test (expected = DataFormatException.class)
	public void testCreate_InvalidCreditDecimal() throws DataFormatException {
		System.out.println("CreateTest 7: Tests constructor's ability to catch credit amount values in DTFLine that have two or more invalid decimal places...");
		String line = "manager         AA 00.10.00.00";
		Create TestCreate = new Create( line);
	}

	/**
	 * CreateTest 8: Tests constructor's ability to catch and reject credit amount values less than zero or have invalid (minus,-) characters
	 * @throws DataFormatException
	 * @result Constructor catches erroneous credit amount, DataFormatException thrown
	 */
	@Test (expected = DataFormatException.class)
	public void testCreate_NegativeInvalidCredit() throws DataFormatException {
		System.out.println("CreateTest 8: Tests constructor's ability to catch and reject credit amount values less than zero or have invalid (minus,-) characters...");
		String line = "manager         AA -99.99";
		Create TestCreate = new Create( line);
	}

	/**
	 * CreateTest 9: Tests constructor's ability to catch credit amount values that are exceed the maximum size limit
	 * @throws DataFormatException
	 * @result Constructor catches erroneous credit amount, DataFormatException thrown
	 */
	@Test (expected = DataFormatException.class)
	public void testCreate_CreditTooLarge() throws DataFormatException {
		System.out.println("CreateTest 9: Tests constructor's ability to catch credit amount values that are exceed the maximum size limit...");
		String line = "manager         AA 9999999.99";
		Create TestCreate = new Create( line);
	}

	/**
	 * CreateTest 10: Test the applyTo() method, test if a Create transaction is applied correctly with a valid user account entry
	 * @throws DataFormatException, TransactionException
	 * @result The create transaction object is constructed from valid data (specified username, type, credit fields) 
	 * and also added to the accounts vector successfully, indicating a new user account created in the system
	 */
	@Test
	public void testApplyTo() throws DataFormatException, TransactionException{
		Vector<Account> TestAccounts = new Vector<Account>();
		Vector<Ticket> TestTickets = new Vector<Ticket>();

		System.out.println("CreateTest 10: Test if a Create transaction is applied correctly with a valid user account entry...");
		Create TestCreate = new Create("newuser         SS 000500.00");
		//TestAccounts will be empty, thus a new account 'newuser' can be created
		TestCreate.applyTo(TestAccounts, TestTickets);
	}

	/**
	 * CreateTest 11: Test the Create applyTo() where the create transaction is attempting to create a (duplicate) user whose account already exists
	 * @throws DataFormatException, TransactionException
	 * @result The create transaction object is constructed from valid data, but TestAccounts vector already contains newuser account added previously, 
	 * Create transaction attempts to create and apply a duplicate newuser, applyTo() catches the error, transaction exception thrown
	 */
	@Test(expected = TransactionException.class)
	public void testApplyTo_UserAlreadyExists() throws DataFormatException, TransactionException{
		Vector<Account> TestAccounts = new Vector<Account>();
		Vector<Ticket> TestTickets = new Vector<Ticket>();

		System.out.println("CreateTest 11: Test the Create applyTo where the create transaction is attempting to create a (duplicate) user whose account already exists");
		
		//NOTE: initial test account "newuser" added to accounts vector to test create transaction
		TestAccounts.add(new Account( "newuser", Account.Sell, 500));
		
		//TestAccounts has newuser account, but Create transaction is trying to create a duplicate newuser
		Create TestCreate = new Create("newuser         SS 000500.00");
		TestCreate.applyTo(TestAccounts, TestTickets);
	}
}