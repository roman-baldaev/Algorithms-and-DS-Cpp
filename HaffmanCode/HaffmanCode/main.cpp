#include "haffman_tree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main () {
	int *a, *copy, n = 0, source_summ = 0, code_summ = 0;
	a = new int [256];
	copy = new int [256];
	count_Symbols ( "source.txt", a );
	for ( int i = 0; i < 256; i++ ) {
		copy [i] = a [i];
	}
	for ( int i = 0; i < 256; i++ ) {
		if ( a[i] ) {
			cout << (char)(i) << ": " << a[i] << endl;
			n++;
			source_summ += a[i];
		}
	}
	Huffman_Tree A ( a, "source.txt" );
	Print ( A.get_Root() );
	cout << "//////////////////////////////" << endl;
	A.make_Huffman_Tree();
	Print ( A.get_Root() );
	table_Coding Table ( n, A.get_Root() );
	for ( int i = 0; i < 256; i++ ) {
		if ( copy[i] ) {
			int k = Table.find_Symbol((char)(i));
			code_summ += copy[i] * Table.get_Str_Tab()[k].size();
		}
	}
	Table.Print();
	cout << "Source size: " << source_summ * 8 << " byte" << endl;
	cout << "Code size: " << code_summ << " byte" << endl;
	cout << "Compression ratio: " << (float)((code_summ)/(source_summ * 8.0)) * 100 << "%" << endl;

	fstream source, code_output;
	source.open( "source.txt", ios::in );
	code_output.open( "code_output.txt", ios::out );
	while ( source ) {
		int ch = source.get();
		int k = Table.find_Symbol((char)(ch));
		if ( k < n ) code_output << Table.get_Str_Tab()[k];
	}
}

