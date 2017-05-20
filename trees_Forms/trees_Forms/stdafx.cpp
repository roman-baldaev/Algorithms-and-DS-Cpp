// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// trees_Forms.pch будет предкомпилированным заголовком
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"
int N=0;
binaryTree :: binaryTree () {
	root = NULL;
}
binaryTree :: binaryTree ( int n, int range ) {
	root = madeTree ( n , range );
}
Node * binaryTree :: madeTree ( int n, int range ) {  //функция, создающее дерево минимальной высоты из n элементов
	if ( n == 0 ) return NULL;
	Node *p = new Node ( rand()%range );
	int nL = ( n - 1 ) / 2, nR = n - 1 - nL;
	p->left = madeTree ( nL, range );
	p->right = madeTree ( nR, range );
	return p;
}
Node * binaryTree :: getRoot () {
	return root;
}
Node * binaryTree :: add_Node ( Node *R, Node *T ) {
	if ( R -> left == NULL ) {
		R -> left = T;
		return R -> left;
	}
	if ( R -> right == NULL ) {
		R -> right = T;
		return R -> right;
	}
	if ((rand()%2) == 0) {
		add_Node ( R -> left, T );
	}
	else {
		add_Node ( R -> right, T );
	}
	
}

void PrintT(Graphics^ gr, Node *u, int l, int r, int y, int x_r)
{	int x = (l + r)/2;
	
	int d = 30;
	int s = 4;
	int x1 = x - s;
	int y1 = y - s;
	int s_y = 50;

	if (!u) return;
	
	Pen^ p = gcnew Pen(Color::Gray, 2);
	gr->DrawEllipse(p, x1, y1, d, d);
	Brush^ br_e;
	srand(time(NULL));
	switch ( u -> getStatus () ) {
		case 0: br_e = gcnew SolidBrush(Color::White); break;
		case 1: br_e = gcnew SolidBrush(Color::Yellow); break;
	}
	
	gr -> FillEllipse(br_e, x1, y1, d, d);
	
	if(x_r > 0)
	{
		gr -> DrawLine(p, x_r, y1-s_y+d, x1+d/2, y1);
	}

	String^ str = Convert::ToString(u->key);
	
	Font^ f = gcnew Font("Arial", 12);
	Brush^ br = gcnew SolidBrush(Color::Black);
	gr->DrawString(str,f,br,(float)x,(float)y);

	PrintT(gr, u->left, l, x, y + 50, x1 + d/2);
	PrintT(gr, u->right, x, r, y + 50, x1 + d/2);
}
