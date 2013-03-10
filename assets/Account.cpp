#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include "Account.h"
#include "globals.h"

Account::Account( char* username, int credit, Type type){
	strcpy( username, this->username);
	this->credit = credit;
	this->type = type;
}

Account::Account( char* line){
	int line_i = 0;
	//read username
	this->username = new char[username_size+1];
	for(int i = 0; i < username_size; i++)
		this->username[i] = line[line_i++];
	this->username[username_size] = '\0';
	//done reading username, format it
	trim(this->username);

	//ensure we are now reading from the correct position
	line_i = username_size+1;
	char* current_field = line + line_i;
	//read type field
	if(!strncmp(current_field,"AA",2))
		this->type = Account::Admin;
	else if(!strncmp(current_field,"BS",2))
		this->type = Account::Buy;
	else if(!strncmp(current_field,"SS",2))
		this->type = Account::Sell;
	else if(!strncmp(current_field,"FS",2))
		this->type = Account::Full;
	else throwError(Error::badTicketStringError);

	//ensure initial credit is 0
	this->credit = 0;
	//ensure we are now reading from the correct position
	line_i = username_size + 1 + type_size + 1;
	current_field = line + line_i;
	char* temp = new char[10];
	strncpy(temp, current_field, credit_size - 3);
	this->credit += 100 * ( atoi( temp));
	//ensure we are now reading from the correct position
	line_i = username_size + 1 + type_size + 1 + credit_size - 2;
	current_field = line + line_i;
	strncpy(temp, current_field, 2);
	temp[2] = '\0';
	this->credit += ( atoi( temp));
	delete temp;
}

bool Account::isEnd(){
	return !strcmp(username, "END");
}