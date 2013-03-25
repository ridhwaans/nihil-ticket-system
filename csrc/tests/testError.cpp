#include <cstdio>
#include <string.h>
#include "../assets/globals.h"
#include "../assets/errors.h"

int main ( int argc, char** argv, char** envp) {
	input = new char[input_size];
	error_string = new char[error_size];
	throwError( Error::badParameterError);
	printf( "{%d, %s}\n", error, error_string);
}
