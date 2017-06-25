#include <math.h>
#include <iostream>

using namespace std;

class Node {
	private:
		Node * next;
		int key;
	public:
		Node ( Node * _next = NULL, int _key = 0 ) {
			next = _next;
			key = _key;
		}
		Node *& getNext () {
			return next;
		}
		int & getKey () {
			return key;
		}
};

class hashTable {
	private:
		Node ** start;
		int N;
	public:
		hashTable ();
		hashTable ( int * , int );
		int choice_Function ( int  );
		void add_Key_First_H ( int );
		void add_Key_Second_H ( int );
		void Print ();
		void find_Key ( int );
		bool findKey ( int );
		void addKey ( int );
};
	hashTable :: hashTable () {
		start = NULL;
	}
	hashTable :: hashTable ( int * a, int n ) {
		if ( n < 10 ) {
			N = n + 1;
		}
		else {
			N = n/10 + n;
		}
		start = new Node * [N];
		for ( int i = 0; i < N; i++ ) {
			start[i] = new Node();
		}

		if ( choice_Function ( N ) ) {
			for ( int i = 0; i < n; i++ ) {
				add_Key_Second_H ( a[i] );
			}
		}
		else {
			for ( int i = 0; i < n; i++ ) {
				add_Key_First_H ( a[i] );
			}
		}
	}
	int hashTable :: choice_Function ( int n ) {
		int Log = log( (double)(n) )/log( 2.0 );
		for ( int i = 0; i < Log + 1; i++ ) {
			if ( pow (2.0, (double)(i)) == n ) {
				return 1;
			}
		}
		return 0;
	}
	void hashTable :: add_Key_First_H ( int key ) {
		int h = key % N;
		if ( start[h] -> getNext() == NULL ) {
			start[h] -> getNext() = new Node ( NULL, key );	
		}
		else {
			Node * P = start[h];
			while ( P -> getNext() ) {
				P = P -> getNext();
			}
			P -> getNext() = new Node ( NULL, key );
		}
	}
	void hashTable :: add_Key_Second_H ( int key ) {
		int a = ( sqrt(5.0) - 1 ) / 2;
		int h = ( ( key * a ) * N) % N;
		if ( start[h] -> getNext() == NULL ) {
			start[h] -> getNext() = new Node ( NULL, key );	
		}
		else {
			Node * P = start[h];
			while ( P -> getNext() ) {
				P = P -> getNext();
			}
			P -> getNext() = new Node ( NULL, key );
		}
	}
	void hashTable :: Print () {
		for ( int i = 0; i < N; i++ ) {
				cout << i << ": ";
				Node * P = start[i];
				if ( P -> getNext() ) {
					while ( P -> getNext () ) {
						P = P -> getNext ();
						cout << P -> getKey() << " ";
						
					}
				}
				cout << endl;
		}
	}
	void hashTable :: find_Key ( int key ) {
		int h, position = 0;
		bool f = false;
		if ( choice_Function ( N ) ) {
			int a = ( sqrt(5.0) - 1 ) / 2;
			h = ( ( key * a ) * N) % N;
		}
		else {
			h = key % N;
		}
		if ( start[h] -> getNext () == NULL ) {
			cout << "Key not finded" << endl;
			return;
		}
		Node * P = start[h] -> getNext ();
		while ( P ) {
			if ( P -> getKey () == key ) {
				cout << "Key finded. Index: " << h << " Position: " << position << endl;
				return;
			}
			position++;
			P = P -> getNext();
		}

	}
	bool hashTable :: findKey ( int key ) {
		int h, position = 0;
		bool f = false;
		if ( choice_Function ( N ) ) {
			int a = ( sqrt(5.0) - 1 ) / 2;
			h = ( ( key * a ) * N) % N;
		}
		else {
			h = key % N;
		}
		if ( start[h] -> getNext () == NULL ) {
			
			return false;
		}
		Node * P = start[h] -> getNext ();
		while ( P ) {
			if ( P -> getKey () == key ) {
				
				return true;
			}
			position++;
			P = P -> getNext();
		}
		return false;
	}
	void hashTable :: addKey ( int key ) {
		if ( findKey ( key ) ) {
			cout << "Key already exists" << endl;
		}
		else {
			if ( choice_Function ( N ) ) {
				add_Key_Second_H ( key );
			}
			else {
				add_Key_First_H ( key );
			}
		}
	}