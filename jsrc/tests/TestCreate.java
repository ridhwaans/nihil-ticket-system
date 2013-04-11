package tests;

import static org.junit.Assert.assertEquals;

import java.util.Vector;
import java.util.zip.DataFormatException;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.junit.BeforeClass;
import org.junit.AfterClass;

import transaction.*;
import assets.Account;
import assets.Ticket;

@RunWith(JUnit4.class)
public class TestCreate {
	
@BeforeClass
public static void testSetup() {
}

@AfterClass
public static void testCleanup() {
}
	
@Test 
public void testCreate() throws DataFormatException {
	System.out.println("Test if a Create transaction object is constructed correctly...");
	String line = "manager         AA 001000.00";
	Transaction transaction = new Create( line);
	assertEquals( line, transaction.toString());
}

@Test 
public void testFailure() throws DataFormatException {
	System.out.println("Test if a Create transaction rejects object construction of invalid field attributes...");
	String line = "manag&r         ZZ 001000.00";
	Transaction transaction = new Create( line);
}

@Test
public void testApplyTo() throws DataFormatException{
	System.out.println("Test if a Create transaction is applied correctly...");
	Account account = new Account( "testuser", Account.Buy, 500);
	Transaction transaction = new Create( account.toString());
	//transaction.applyTo(accounts, tickets);
	//if (accounts.contains(account))
	//	assertEquals( account.username.toString(), accounts.getIndexOf(account.username.toString()));
}

//testCreateDuplicate
}