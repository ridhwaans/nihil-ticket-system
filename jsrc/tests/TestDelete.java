package tests;

import static org.junit.Assert.assertEquals;

import java.util.zip.DataFormatException;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.junit.BeforeClass;
import org.junit.AfterClass;

import assets.Account;

@RunWith(JUnit4.class)
public class TestDelete {
	
@BeforeClass
public static void testSetup() {
}

@AfterClass
public static void testCleanup() {
}
	  
@Test
public void testRead() throws DataFormatException {
	System.out.println("Test if Delete reads a transaction correctly...");
	String line = "manager         AA 001000.00";
	Account account = new Account( line);
	//assertEquals( line.equals( account.toString()), true);
	assertEquals( line, account.toString());
}

@Test
public void testWrite() throws DataFormatException {
	System.out.println("Test if Delete applies a transaction correctly...");
	Account account = new Account( "testuser", Account.Buy, 500);
	assertEquals( true, account.equals( new Account( account.toString())));
}

@Test
public void testApply() {
	System.out.println("Test if Delete applies a transaction correctly...");
}


@Test
public void testEquals() {

}
}