#include "Transaction.h"
#include "globals.h"
#include <iostream>
using namespace std;


/**
* Determines the transaction code based on the enumeration value received
*
* @param transaction_code
* @return
*/

char* transaction_digit(Transaction::Code transaction_code) {
	char digit [2];
	switch (transaction_code){
	case Transaction::Code::Create:
		digit = "01";
		break;
	case Transaction::Code::Delete:
		digit = "02";
		break;
	case Transaction::Code::Sell:
		digit = "03";
		break;
	case Transaction::Code::Buy:
		digit = "04";
		break;
	case Transaction::Code::Refund:
		digit = "05";
		break;
	case Transaction::Code::AddCredit:
		digit = "06";
		break;
	}
	return digit;
}


/**
* Determines the transaction code based on the enumeration value received
*
* @ Transaction code field value XX
*/

Transaction::Transaction()
{

}

/**
* Determines the transaction code based on the enumeration value received
*
* @return buffer after transaction text line is composed and concatenated for file write
*/

char* Transaction::write()
{
	char buffer[];
	int i;
	char* field = new char[30];

	field = transaction_digit(this->code);
	for(i = 0; field[i] != '\0'; i++)
		buffer[i] = field[i];
	buffer[i] = token;

	switch (code){
	//01-create, 02-delete, 06-addcredit, 00-end of session
	//(X field 2, U field 15, T field 2, C field 9, total 28 + 3 = 31)
	//XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
		case 0:
		case 2:
		case 3:
	//05-refund
	//(X field 2, U field 15, S field 15, C field 9, total 44)
	//XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
		case 5:
		{
			field = this->username;
			for(i = 0; field[i] != '\0'; i++)
				buffer[i] = field[i];
			for( i < username_size; i++;)
				buffer[i] = filler;
			buffer[i] = token;

			switch (code){
			case 5:
				field = this->seller;
				for(i = 0; field[i] != '\0'; i++)
					buffer[i] = field[i];
				for( i < username_size; i++;)
					buffer[i] = filler;
				buffer[i] = token;
				field = this->ticketPrice; //convert to string
				//right justify price field sprintf() sprintf

			default:
				field = this->type;
				for(i = 0; field[i] != '\0'; i++)
				buffer[i] = field[i];
				buffer[i] = token;

			}
		}
			break;
	//03-sell, 04-buy
	//(X field 2, E field 19, S field 15, T field 3, P field 6, total 45+4 = 49)
	//XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSSSS_TTT_PPPPPP
		case 1: //buy
		case 5: //sell
		{

		}
			break;

		}



	return buffer;
}

int main () {

  return 0;
}

