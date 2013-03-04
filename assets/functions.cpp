#include <iostream>
#include "globals.h"

using namespace std;

char* format( char* original){
	string bad(" \n\r\t");
	int j = 0;
	for(int i = 0; original[i]!='\0'; i++){
		cout<<"checkinging "<<original[i]<<endl;
		cout<<bad.find(original[i])<<endl;
		if( bad.find(original[i]) ==string::npos){
			cout<<"moved "<<original[i]<<" to "<<j<<endl;
			original[j++] = original[i];}}
	original[j] = '\0';
	return original;}
char* getLine(){
	cin.getline(input,input_size);
	cout<<"got input: "<<input<<endl;
	return format(input);}
