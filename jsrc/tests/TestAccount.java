package tests;

import java.util.zip.DataFormatException;

import static org.junit.Assert.assertEquals;

import org.junit.Test;
import org.junit.Ignore;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import assets.Account;

@RunWith(JUnit4.class)
public class TestAccount {
	@Test
	public void testRead() throws DataFormatException{
		String line = "manager         AA 001000.00";
		Account account = new Account( line) ;
		assertEquals( line, account.toString());
	}

	@Test
	public void testWrite() throws DataFormatException {
		Account account = new Account( "manager", Account.Admin, 100);
		assertEquals( account, new Account( account.toString()));
	}

	@Test
	public void testEquals() {
	}
}