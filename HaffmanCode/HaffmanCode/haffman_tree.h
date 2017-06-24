#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>

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
	source.close();
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
		char get_Symbol () {
			for ( int i = 0; i < 256; i++ ) {
				if ( tab[i] ) return (char)(i);
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
		friend class table_Coding;
		friend class Huffman_Tree;
		friend Node * create_Sort_List ( int * , char * );
		friend void Print ( Node *);
		int frequency;
		boolVect V;
		Node *next;
		Node *left;
		Node *right;
		string code;
	public:
		Node ( int _freq = 0, Node * _next = NULL, Node * _left = NULL, Node * _right = NULL ) {
			frequency = _freq;
			boolVect V;
			next = _next;
			left = _left;
			right = _right;
			code = "";
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
class Huffman_Tree {
	private: 
		Node *root;
	public: 
		Huffman_Tree ( Node *r = NULL ) {
			root = r;
		}
		Huffman_Tree ( int * a, char *source_File ) {
			root = create_Sort_List ( a, source_File );
		}
		Node * make_Union_Node ( Node *First, Node *Second ) {
			Node *new_First = new Node ( First -> get_Freq(), NULL, First -> left, First -> right );
			Node *new_Second = new Node ( Second -> get_Freq(), NULL, Second -> left, Second -> right );
			new_First -> V = First -> V;
			new_Second -> V = Second -> V;
			int first_Freq = First -> get_Freq ();
			int second_Freq = Second -> get_Freq ();
			Node * Union = new Node ( first_Freq + second_Freq, NULL, new_First, new_Second );
			Union -> V = operation_AND ( First -> V, Second -> V );
			return Union;
		}
		void unite_Nodes () {
			Node * First = root;
			Node * Second = First -> next;
			Node * Union = make_Union_Node ( First, Second );
			Node * Position = First -> next;
			while ( ( Position -> next ) && ( ( Position -> next -> get_Freq() ) < ( Union -> get_Freq() ) ) ) {
				Position = Position -> next;
			}
			if ( Position -> next == NULL ) {
				Position -> next = Union;
			}
			else {
				Node * next_Position = Position -> next;
				Position -> next = Union;
				Union -> next = next_Position;
			}
			root = Second -> next;
			delete First;
			delete Second;
		}
		Node * get_Root () {
			return root;
		}
		void make_Huffman_Tree ( ) {
			while ( root -> next -> next ) {
				unite_Nodes ();
				Print ( root );
				cout << "//////////////////////////////" << endl;
			}
			root = make_Union_Node ( root, root -> next );
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

class table_Coding {
	private:
		int n, position;
		char * Tab;
		string * tab;
	public:
		table_Coding ( int _n, Node * R ) {
			position = 0;
			n = _n;
			Tab = new char [n];
			tab = new string [n];
			formation_Table ( R );
		}
		void formation_Table ( Node * R ) {
			if ( position == n  ) return; 
			if ( ( R -> left == NULL ) && ( R -> right == NULL ) ) {
				Tab [position] = R->V.get_Symbol();
				tab [position] = R->code;
				position++;
			}
			else {
				R->left->code = R -> code + "0";
				R->right->code = R -> code + "1";
			}
			if ( R -> left ) formation_Table ( R->left );
			 if ( R -> right ) formation_Table ( R->right );
		}
		void Print () {
			cout << "Table coding: " << endl;
			for ( int i = 0; i < n; i++ ) {
				cout << Tab [i] << ": " << tab[i] << endl;
			}
		}
		int find_Symbol ( char s ) {
			for ( int i = 0; i < n; i++ ) {
				if ( Tab [i] == s ) return i;
			}
		}
		string * get_Str_Tab () {
			return tab;
		}
};