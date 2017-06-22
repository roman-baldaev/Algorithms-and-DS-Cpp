#include <fstream>
#include <stdio.h>
#include <iostream>

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
int index_of_Min ( int * a ) {
	int n = 256;
	int i = 0;
	int min;
	while ( ( a[i] == 0 ) && ( i < n ) ) {
		i++;
	}
	min = i;
	for ( ; i < n; i++ ) {
		if ( (a[i] < a[min]) && ( a[i] != 0 ) ) {
			min = i;
		}
	}
	if ( a[min] != 0) return min;
	return -1;
}
class boolVect {
	private:
		friend class Node;
		bool *tab;
	public:
		boolVect () {
			tab = new bool [256];
			for ( int i = 0; i < 256; i++ ) {
				tab[i] = false;
			}
		}
		boolVect ( int set ) {
			tab = new bool [256];
			for ( int i = 0; i < 256; i++ ) {
				tab[i] = false;
			}
			tab[set] = true;
		}
		void set1 ( int i ) {
			tab[i] = true;
		}
		void set0 ( int i ) {
			tab[i] = false;
		}
		bool & operator [] (int i)  //оператор []-возвращает элемент массива объекта класса Array
		{
			if ( i < 0 || i >= 256 )
			{
				cout << "Error. Uncorrect index" << endl;
				
			}
			return tab[i];
		}
		void Print () {
			for ( int i = 0; i < 256; i++ ) {
				if ( tab[i] ) cout << (char)(i);
			}
		}
};

boolVect & operation_AND ( boolVect & V1, boolVect & V2 ) {
	boolVect V3;
	for ( int i = 0; i < 256; i++ ) {
		V3[i] = V1[i] | V2[i];
	}
	return V3;
}

class Node {
	private:
		friend Node * create_Sort_List ( int * , char * );
		friend void Print ( Node *);
		int frequency;
		boolVect V;
		Node *next;
		Node *left;
		Node *right;
	public:
		Node ( int _freq = 0, Node * _next = NULL, Node * _left = NULL, Node * _right = NULL ) {
			frequency = _freq;
			boolVect V;
			next = _next;
			left = _left;
			right = _right;
		}
		int & get_Freq () {
			return frequency;
		}
		Node * get_Next () {
			return next;
		}
		Node * get_Left () {
			return left;
		}
		Node * get_Right () {
			return right;
		}
		
};
void Print ( Node *Sort) {
			Node *P = Sort;
			while ( P ) {
				cout << P -> frequency << " "; 
				P -> V.Print();
				cout << endl;
				P = P -> next;
			}
		}
Node * create_Sort_List ( int * a, char *source_File ) {
	int count = count_Symbols ( source_File, a );
	if ( count == 0 ) return NULL;
	Node * Root = new Node ( a[index_of_Min(a)], NULL, NULL, NULL );
	Root -> V.set1(index_of_Min(a));
	a[index_of_Min(a)] = 0;
	Node *Copy = Root;
	for ( int i = 1; i < count; i++ ) {
		Copy -> next = new Node ( a[index_of_Min(a)], NULL, NULL, NULL );
		Copy -> get_Next() -> V.set1(index_of_Min(a));
		a[index_of_Min(a)] = 0;
		Copy = Copy -> get_Next();
	}
	return Root;
}