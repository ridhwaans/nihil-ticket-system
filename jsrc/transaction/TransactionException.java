package transaction;

/** @class TransactionException
 * @brief Represents anything that can go wrong during a transaction.
 **/
public class TransactionException extends Exception {
  public TransactionException() { super(); }
  public TransactionException(String message) { super(message); }
  public TransactionException(String message, Throwable cause) { super(message, cause); }
  public TransactionException(Throwable cause) { super(cause); }
}