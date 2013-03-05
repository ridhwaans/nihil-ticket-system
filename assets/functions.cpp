#include <cstdio>
#include <ctype.h>
#include <iostream>
#include <string.h>	
#include "globals.h"

using namespace std;

//initialization functions
bool init(
		char* accountsFilename,
		char* ticketsFilename,
		char* transactionFilename){
	//initialize global variables
	input = new char[input_size];
	buffer = new char[buffer_size];
	error_string = new char[error_size];
	//prepare the transactions file for output
	transactionFile = new TransactionFile( transactionFilename);
	//load data files
	return
		loadAccounts( accountsFilename) ?
		loadTickets( ticketsFilename) : false;}

bool deinit (){
	delete input;
	delete buffer;
	delete error_string;
	delete transactionFile;}

//input functions
char* format( char* original){
	//this string defines all the chars we want to ignore
	string whitespaces(" \t\f\v\n\r");
	//defines the next place to insert a char
	int j = 0;
	for(int i = 0; original[i]!='\0'; i++){
			//for every character in the original
		if( whitespaces.find(original[i]) == string::npos){
				//if the character is not in the subset of bad chars
			original[j++] = original[i];}}
				//insert the character into the new location, as well as increment j, so that the next character to be inserted will not overwrite desired data.
	original[j] = '\0';
		//add the null terminator character to ensure other functions, for example print statements, know when the string ends.
	//finish
	return original;}
char* format_command( char* original){
	format(original);
	for(int i = 0; original[i]; i++)
		original[i] = (char) tolower(original[i]);
	return original;}
char* trim( char* original){
	string ori_string(original);
	string whitespaces (" \t\f\v\n\r");
	int first = ori_string.find_first_not_of(whitespaces);
	if ( first == std::string::npos)
		first = 0;
	printf("first:%d\n",first);
	int last = ori_string.find_last_not_of(whitespaces);
	printf("last:%d\n",last);
	int length = last - first;
	if( length < 0)
		length = 0;
	printf("length:%d\n",length);
	int i;
	for( i = 0; (i <= length) && (original[first+i] != '\0'); i++)
		original[i] = original[first+i];
	printf("%d, %d\n",(i < length),(original[first+i] != '\0'));
	original[first+i] = '\0';
	return original;}

char* getLine(){
	//get input
	cin.getline( input, input_size);
	//return input
	return input;}

//data load functions
bool loadAccounts( char* accountsFilename){
	return true;}
bool loadTickets( char* ticketsFilename){
	return true;}

//error functions 
/*
void throwError( const char* newError_string){
	error = true;
	int i;
	for( i = 0; error_string[i] != '\0'; i++)
		error_string[i] = newError_string[i];
	error_string[i] = '\0';}
	//or:*/ //
//*
void throwError( const char* newError_string){
	error = true;
	strcpy(error_string, newError_string);}
	//*/
void clearError(){
	error = false;}
