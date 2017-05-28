// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
#pragma once

// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include <time.h>
#include <stdlib.h>

// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
class Node {
		friend class binaryTree;
		friend class SearchTree;
		friend void PrintT(Graphics^ gr, Node *p, int l, int r, int y, int x_r);
		friend void addKey (Node *, int );
	private:	
		int key;
		
		Node *left, *right, *prev;
	public:
		int status;
		Node ( int k = 0, Node *l = NULL, Node *r = NULL, int s = 0 ) {
			key = k;
			left = l;
			right = r;
			status = s;
		}
		Node *& getLeft () {
			return left;
		}
		Node *& getRight () {
			return right;
		}
		int getStatus () {
			return status;
		}
		
};
class binaryTree {
	protected:
		Node *root;
	public:
		binaryTree ();
		binaryTree ( int, int );
		
		Node * getRoot ();
		Node * add_Node ( Node *, Node * );
		Node * findKey ( Node *, int );
		Node * findPrev ( Node *, Node * ); //search father for node
		Node * findLeaf ( Node * ); // find node with empty subtree 
		void addKeyToTree ( int ); // add key to this tree
		bool deleteKey ( int );
		void obhod ( Node *, System::String^ &); // L-K-R
};

class SearchTree: public binaryTree {
	public:
		SearchTree ( int = 1, int = 100 );
		Node * addKey ( Node *, int );
		void addKeyToTree ( int );
		Node * findKey ( Node *, int );
		bool deleteKey ( int );
		Node * min_Right ( Node * );
		Node * addNode ( Node * );

};
void PrintT(Graphics^ , Node , int , int , int , int ); //print function
void addKey ( Node *, int ); 
