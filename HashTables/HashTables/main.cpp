#include "HashTables.h"
#include <conio.h>

using namespace std;

void main () {
	
	int n, *a, key, nkeys, akeys;
	cin >> n;
	a = new int [n];
	for ( int i = 0; i < n; i++) {
		a[i] = rand()%(n*10);
	}
	for ( int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Hash table: " << endl;
	hashTable A (a,n);
	A.Print();
	cout << endl;
	cout << "Enter number of keys for find: ";
	cin >> nkeys;
	for ( int i = 0; i < nkeys; i++ ) {	
		cout << "Enter key for find: ";
		cin >> key;
		A.find_Key ( key );
	}
	cout << "Enter number of keys for add: ";
	cin >> akeys;
	for ( int i = 0; i < akeys; i++ ) {	
		cout << "Enter key for add: ";
		cin >> key;
		A.addKey ( key );
		A.Print();
	}
}