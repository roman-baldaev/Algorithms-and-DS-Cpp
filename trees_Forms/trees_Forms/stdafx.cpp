


#include "stdafx.h"
int N=0;
binaryTree :: binaryTree () {
	root = NULL;
}
binaryTree :: binaryTree ( int n, int range ) {
	srand(time(NULL));
	root = NULL;
	for ( int i = 0; i < n; i++ ) {
		addKeyToTree ( rand()%range );
	}
}

Node * binaryTree :: getRoot () {
	return root;
}
Node * binaryTree :: add_Node ( Node *R, Node *T ) {
	if ( findKey ( R, T -> key ) != NULL ) {
		return NULL;
	}
	if ( R  == NULL ) {
		R = T;
		return R;
	}
	if ( R -> left == NULL ) {
		R -> left = T;
		T -> prev = R;
		return R -> left;
	}
	if ( R -> right == NULL ) {
		R -> right = T;
		T -> prev = R;
		return R -> right;
	}
	if ((rand()%2) == 0) {
		add_Node ( R -> left, T );
	}
	else {
		add_Node ( R -> right, T );
	}
	
}
Node * binaryTree :: findKey ( Node *R, int k ) {  
	if ( (R == NULL) || (R -> key == k) ) return R;
	Node *T;
	if ( (T = findKey ( R->left, k )) != NULL )  return T;
	return (findKey ( R -> right, k ));
}
void   binaryTree :: addKeyToTree ( int k ) {
	if ( root == NULL ) {
		root = new Node ( k );
		
	}
	
	else if ( findKey ( root, k ) == NULL ) {
		addKey ( root, k );
	}
}
bool binaryTree :: deleteKey ( int k ) {
	Node *D = findKey ( root, k );
	if ( D == NULL ) return false;
	if ( (D -> left == NULL) && ( D -> right == NULL ) ) {
		if ( D -> prev -> left == D ) {
			D -> prev -> left = NULL;
		}
		if ( D -> prev -> right == D ) {
			D -> prev -> right = NULL;
		}
	}
	if ( (D -> left) == NULL )  {
		
			Node * d = D;
			D = D -> right;
			delete d;
			return true;
	}
	if ( D -> right == NULL )  {
			Node * d = D;
			D = D -> left;
			delete d;
			return true;
	}
	else {
		srand ( time ( NULL ) );
		Node *leaf;
		if ( rand () % 2 == 0 ) {
			leaf = findLeaf ( D -> left );
		}
/*		else {
			leaf = findLeaf ( D -> right );
		}
			if ( D == P -> left ) {
				P -> left = D -> left;
			}
			else {
				P -> right = D -> left;
			}
			if ( leaf -> left == NULL ) {
				leaf -> left = D -> right;
			}
			else {
				leaf -> right = D -> right;
			}
			delete D;
			return true;
	}
*/
	}
}
Node * binaryTree :: findLeaf ( Node * R ) {
	if ( ( R == NULL ) || ( R -> left == NULL ) || ( R -> right == NULL ) ) return R;
	if ( R -> left ) {
		findLeaf ( R -> left );
	}
	if ( R -> right ) {
		findLeaf ( R -> right );
	}
}
Node * binaryTree :: findPrev ( Node * R, Node * F ) {
	if ( R ) {
		if ( R -> left != NULL) { 
			if ( R -> left == F ) return R;
		}
		if ( R -> right != NULL ) { 
			if ( R -> right == F ) return R;
		}
	}
	if ( R -> left ) findPrev ( R->left, F );
	if ( R -> right ) findPrev ( R -> right, F );
	
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
		case 2: br_e = gcnew SolidBrush(Color::PaleTurquoise); break;
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
void addKey ( Node *R, int k ) {
	if ( R -> getLeft() == NULL ) {
		(R -> getLeft()) = new Node ( k );
		R -> getLeft() -> prev = R;
		return;
	}
	if ( R -> getRight() == NULL ) {
	    R -> getRight() = new Node ( k );
		R -> getRight() -> prev = R;
		return;
	}
	if ( rand() % 2 == 0 ) {
		addKey ( R -> getLeft(), k );
	}
	else {
		addKey ( R -> getRight(), k );
	}
}
