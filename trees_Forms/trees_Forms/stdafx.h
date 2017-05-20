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
		friend void PrintT(Graphics^ gr, Node *p, int l, int r, int y, int x_r);
	private:	
		int key;
		
		Node *left, *right;
	public:
		int status;
		Node ( int k = 0, Node *l = NULL, Node *r = NULL, int s = 0 ) {
			key = k;
			left = l;
			right = r;
			status = s;
		}
		Node * madeTree ( int n, int range ) {
			srand(time(NULL));
			if ( n == 0 ) return NULL;
			int nL = (n-1)/2, nR = n - 1 - nL;
			Node *node = new Node ( rand()%range );
			node->left = madeTree (nL, range);
			node->right = madeTree (nR, range);
			return node;
		}
	
		int getStatus () {
			return status;
		}
		
};
class binaryTree {
	private:
		Node *root;
	public:
		binaryTree ();
		binaryTree ( int, int );

		Node * madeTree ( int, int ); 
		Node * getRoot ();
		Node *  add_Node ( Node *, Node * );
};
void PrintT(Graphics^ , Node , int , int , int , int );
