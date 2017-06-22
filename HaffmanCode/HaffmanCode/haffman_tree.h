#include <fstream>
#include <stdio.h>

using namespace std;

int count_Symbols ( char *source_File, int *a ) { // Function for calculating symbol frequencies
	int number = 0;
	fstream source;
	source.open( source_File, ios::in );
	for ( int i = 0; i < 256; i++ ) {
		a[i] = 0;
	}
	while ( source ) {
		int ch = source.get();
		a[ch]++;
	}
	for ( int i = 0; i < 256; i++ ) {
		if ( a[i] ) number++;
	}
	return number;
}