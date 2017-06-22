#include "haffman_tree.h"
#include <iostream>
#include <fstream>

using namespace std;

void main () {
	int *a;
	a = new int [256];
	count_Symbols ( "source.txt", a );
	for ( int i = 0; i < 256; i++ ) {
		if ( a[i] ) {
			cout << (char)(i) << ": " << a[i] << endl;
		}
	}
	Node * R = create_Sort_List ( a, "source.txt" );
	Print ( R );
}

