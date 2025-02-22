


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
	if ( D == root ) {  // ���� ���������� ���� - ������
		if ( D -> left == NULL ) { // ���� � ����� ��� ������ ���������
			root = D -> right;
			D -> right -> prev = NULL;
			
		}
		else if ( D -> right == NULL ) { // ���� � ����� ��� ������� ���������
			root = D -> left;
			D -> left -> prev = NULL;
			
		}
		else {  
			Node *leaf;
			if ( rand () % 2 == 0 ) {
				D -> left -> prev = NULL;
				root = D -> left;
				leaf = findLeaf ( D -> left );
				leaf -> right = D -> right;
				D -> right -> prev = leaf;
			}
			else {
				D -> right -> prev = NULL;
				root = D -> right;
				leaf = findLeaf ( D -> right );
				leaf -> right = D -> left;
				D -> left -> prev = leaf;
			}
		}
		delete D; 
		return true;
	}
	if ( (D -> left == NULL) && ( D -> right == NULL ) ) {
		if ( D -> prev -> left == D ) {
			D -> prev -> left = NULL;
		}
		else if ( D -> prev -> right == D ) {
			D -> prev -> right = NULL;
		}
		delete D;
			return true;
	}
	if ( D -> left == NULL )  {
		
			if ( D -> prev -> right == D ) {
				D -> prev -> right = D -> right;
				D -> prev -> right -> prev = D -> prev;
			}
			else if ( D -> prev -> left == D ) {
				D -> prev -> left = D -> right;
				D -> prev -> left -> prev = D -> prev;
			}
			delete D;
			return true;
	}
	if ( D -> right == NULL )  {
			if ( D -> prev -> right == D ) {
				D -> prev -> right = D -> left;
				D -> prev -> right -> prev = D -> prev;
			}
			else if ( D -> prev -> left == D ) {
				D -> prev -> left = D -> left;
				D -> prev -> left -> prev = D -> prev;
			}
			delete D;
			return true;
	}
	
	else {
		srand ( time ( NULL ) );
		Node *leaf;
		if ( rand () % 2 == 0 ) {
			leaf = findLeaf ( D -> left );
			if ( rand () % 2 == 0 ) {
				Node *P = new Node ( leaf -> key, D -> right, NULL );
				if ( leaf -> prev -> left == leaf ) {
					leaf -> prev -> left = P;
					P -> prev = leaf -> prev;
				}
				else {
					leaf -> prev -> right = P;
					P -> prev = leaf -> prev;
				}
				
			}
			else {
				Node *P = new Node ( leaf -> key, NULL, D -> right );
				if ( leaf -> prev -> left == leaf ) {
					leaf -> prev -> left = P;
					P -> prev = leaf -> prev;
				}
				else {
					leaf -> prev -> right = P;
					P -> prev = leaf -> prev;
				}
			}
			if ( D -> prev -> left == D ) {
				D -> prev -> left = D -> left;
				D -> prev -> left -> prev = D -> prev;
			}
			else {
				D -> prev -> right = D -> left;
				D -> prev -> right -> prev = D -> prev;
			}
		}
		else {
			leaf = findLeaf ( D -> right );
			if ( rand () % 2 == 0 ) {
				Node *P = new Node ( leaf -> key, D -> left, NULL );
				if ( leaf -> prev -> left == leaf ) {
					leaf -> prev -> left = P;
					P -> prev = leaf -> prev;
				}
				else {
					leaf -> prev -> right = P;
					P -> prev = leaf -> prev;
				}
				
			}
			else {
				Node *P = new Node ( leaf -> key, NULL, D -> left );
				if ( leaf -> prev -> left == leaf ) {
					leaf -> prev -> left = P;
					P -> prev = leaf -> prev;
				}
				else {
					leaf -> prev -> right = P;
					P -> prev = leaf -> prev;
				}
			}
			if ( D -> prev -> left == D ) {
				D -> prev -> left = D -> right;
				D -> prev -> left -> prev = D -> prev;
			}
			else {
				D -> prev -> right = D -> right;
				D -> prev -> right -> prev = D -> prev;
			}
		}
		delete D;
		return true;
	
	}
}
Node * binaryTree :: findLeaf ( Node * R ) {
	if (( R -> left == NULL ) && ( R -> right == NULL ) ) return R;
	if ( R -> left ) {
		return findLeaf ( R -> left );
	}
	if ( R -> right ) {
		return findLeaf ( R -> right );
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
void binaryTree :: obhod ( Node * p, System::String^ &a )  
{if  (p->left) obhod(p->left, a);
   a += p -> key + " ";
  if (p->right) obhod(p->right, a);
  
}

SearchTree :: SearchTree ( int n, int range ) {
	srand(time(NULL));
	root = NULL;
	for ( int i = 0; i < n; i++ ) {
		addKeyToTree ( rand()%range );
	}
}
Node * SearchTree :: addKey ( Node *R, int k ) {
	if ( R -> key == k ) {
		return NULL;
	}
	if ( k < R -> key ) {
		if ( R -> left == NULL ) {
			R -> left = new Node ( k );
			R -> left -> prev = R;
			return R -> left;
		}
		else {
			return addKey ( R -> left, k ); 	
		}	
	}
	if ( k > R -> key ) {
		if ( R -> right == NULL ) {
			R -> right = new Node ( k );
			R -> right -> prev = R;
			return R -> right;
		}
		else {
			return addKey ( R -> right, k ); 	
		}	
	}
}
void SearchTree :: addKeyToTree ( int k ) {
	if ( root == NULL ) {
		root = new Node ( k );
		return;
	}
	addKey ( root, k );
}
Node * SearchTree :: findKey ( Node *R, int k ) {
	if ( R -> key == k ) {
		return R;
	}
	if ( k < R -> key ) {
		if ( R -> left == NULL ) {
			return NULL;
		}
		return findKey ( R -> left, k );
	}
	else if ( k > R -> key ) {
		if ( R -> right == NULL ) {
			return NULL;
		}
		return findKey ( R -> right, k );
	}
}
bool SearchTree :: deleteKey ( int k ) {
	Node *T = findKey ( root, k );
	if ( T == NULL ) {
		return false;
	}
	if ( T -> left == NULL && T -> right == NULL ) {
		if ( T -> prev -> left == T ) {
			T -> prev -> left = NULL;
		}
		else if ( T -> prev -> right == T ) {
			T -> prev -> right = NULL;
		}
		delete T;
		return true;
	}
	if ( T -> left == NULL ) {
		if ( T -> prev -> left == T ) {
			T -> prev -> left = T -> right;
			T -> right -> prev = T -> prev;
		}
		else if ( T -> prev -> right == T ) {
			T -> prev -> right = T -> right;
			T -> right -> prev = T -> prev;
		}
		delete T;
		return true;
	}
	if ( T -> right == NULL ) {
		if ( T -> prev -> left == T ) {
			T -> prev -> left = T -> left;
			T -> left -> prev = T -> prev;
		}
		else if ( T -> prev -> right == T ) {
			T -> prev -> right = T -> left;
			T -> left -> prev = T -> prev;
		}
		delete T;
		return true;
	}
	if ( T -> right -> left == NULL ) {
		Node * N = T -> right;
		if ( N -> right != NULL ) {
			T -> key = N -> key;
			T -> right = N -> right;
			N -> right -> prev = T;
		}
		else {
			T -> key = N -> key;
			T -> right = NULL;
		}
		delete N;
		return true;
	}
	else {
		Node * N = min_Right ( T -> right );
		if ( N -> right == NULL ) {
			T -> key = N -> key;
			N -> prev -> left = NULL;
			delete N;
			return true;
		}
		else {
			T -> key = N -> key;
			N -> prev -> left = N -> right;
			N -> right -> prev = N -> prev;
			delete N;
			return true;
		}
	}
}
Node * SearchTree :: min_Right ( Node * R ) {
	if ( R -> left == NULL ) {
		return R;
	}
	else {
		return min_Right ( R -> left );
	}
}
Node * SearchTree :: addNode ( Node * R ) {
	return addKey ( root, R -> key );
}

BalancedSearchTree :: BalancedSearchTree ( int n, int range ) {
	root = NULL;
	for ( int i = 0; i < n; i++ ) {
		addKeyToTree ( rand()%range );
	}
}
int BalancedSearchTree :: Hight ( Node * R ) {
	if ( R == NULL ) {
		return 0;
	}
	int l, r; 
	l = r = 0;
	if ( R -> left == 0 && R -> right == 0 ) return 1;
	else {
		if ( R -> left ) l = Hight ( R -> left );
        if ( R -> right ) r = Hight ( R -> right );
        if (l < r ) return r + 1;
	    else  return l+1;
    }
}
int BalancedSearchTree :: Balance ( Node * R ) {
	if ( R ) {
		return (Hight ( R -> right ) - Hight (R -> left));
	}
}
Node * BalancedSearchTree :: LR_Once_Rotation ( Node * R ) {
		if ( R == root ) {
			Node * L = R -> left;
			R -> left = L -> right;
			if ( L -> right ) {
				L -> right -> prev = R;
			}
			L -> right = R;
			R -> prev = L;
			root = L;
			return L;
		}
		else {
			Node * P = R -> prev;
			Node * L = R -> left;
			R -> left = L -> right;
			if ( L -> right ) {
				L -> right -> prev = R;
			}
			L -> right = R;
			R -> prev = L;
			L -> prev = P;
			if ( P -> left == R ) {
				P -> left = L;
			}
			else {
				P -> right = L;
			}
			return L;
		}
}
Node * BalancedSearchTree :: RL_Once_Rotation ( Node * R ) {
			if ( R == root ) {
				Node * Rt = R -> right;
				R -> right = Rt -> left;
				if ( Rt -> left ) {
					Rt -> left -> prev = R;
				}
				Rt -> left = R;
				R -> prev = Rt;
				root = Rt;
				return Rt;
			}
			else {
				Node * Rt = R -> right;
				Node * P = R -> prev;
				R -> right = Rt -> left;
				if ( Rt -> left ) {
					Rt -> left -> prev = R;
				}
				Rt -> left = R;
				R -> prev = Rt;
				Rt -> prev = P;
				if ( P -> left == R ) {
					P -> left = Rt;
				}
				else {
					P -> right = Rt;
				}
				return Rt;
			}
		}
Node * BalancedSearchTree :: LR_Double_Rotation ( Node * R ) {
	RL_Once_Rotation ( R -> left );
	return LR_Once_Rotation ( R );
}
Node * BalancedSearchTree :: RL_Double_Rotation ( Node * R ) {
	LR_Once_Rotation ( R -> right );
	return RL_Once_Rotation ( R );
}
Node * BalancedSearchTree :: addKey ( Node * R, int k ) {
	Node * T = SearchTree :: addKey ( root, k );
	Node * lastRotation = T;
	while ( T != root && T != NULL ) {
		Node * Son = T;
		T = T -> prev;
		int b = Balance ( T );
		if (  b == 2 || b == -2 ) { // if need change balance
			if ( b == 2 ) {
				Node * S = T -> right;
				if ( Balance ( S ) == 1 || Balance ( S ) == 0 ) {
					T = RL_Once_Rotation ( T );
				}
				else {
					T = RL_Double_Rotation ( T );
				}
				lastRotation = T;
			}
			else {
				Node * S = T -> left;
				if ( Balance ( S ) == -1 || Balance ( S ) == 0 ) {
					T = LR_Once_Rotation ( T );
				}
				else {
					T = LR_Double_Rotation ( T );
				}
				lastRotation = T;
			}
		}
	}
	return lastRotation;
}
void BalancedSearchTree :: addKeyToTree ( int k ) {
	if ( root == NULL ) {
		root = new Node ( k );
		return;
	}
	addKey ( root, k );
}
bool BalancedSearchTree :: deleteKey ( int k ) {
	if ( SearchTree :: findKey ( root, k ) == NULL ) {
		return false;
	}
	Node * T = SearchTree :: findKey ( root, k );
	if ( T == root ) { // its delete root
		T = ( SearchTree :: min_Right ( root -> right ) ) -> prev;
	
		SearchTree :: deleteKey ( k );
		root -> prev = NULL;
		while ( T != NULL ) {
			int b = Balance ( T );
			if (  b == 2 || b == -2 ) { // if need change balance
				if ( b == 2 ) {
					Node * S = T -> right;
					if ( Balance ( S ) == 1 || Balance ( S ) == 0 ) {
						T = RL_Once_Rotation ( T );
					}
					else {
						T = RL_Double_Rotation ( T );
					}
				
				}
				else {
					Node * S = T -> left;
					if ( Balance ( S ) == -1 || Balance ( S ) == 0 ) {
						T = LR_Once_Rotation ( T );
					}
					else {
						T = LR_Double_Rotation ( T );
					} 
				
				}
			}
			if ( T == root ) break;
			T = T-> prev;
		}
		return true;
	}
	if ( T -> right == NULL ) {
		T = T -> prev;
		SearchTree :: deleteKey ( k );
	}
	else {
		T = ( SearchTree :: min_Right ( root -> right ) ) -> prev;
		SearchTree :: deleteKey ( k );
	}
	while (  T != NULL ) {
		int b = Balance ( T );
		if (  b == 2 || b == -2 ) { // if need change balance
			if ( b == 2 ) {
				Node * S = T -> right;
				if ( Balance ( S ) == 1 || Balance ( S ) == 0 ) {
					T = RL_Once_Rotation ( T );
				}
				else {
					T = RL_Double_Rotation ( T );
				}
				
			}
			else {
				Node * S = T -> left;
				if ( Balance ( S ) == -1 || Balance ( S ) == 0 ) {
					T = LR_Once_Rotation ( T );
				}
				else {
					T = LR_Double_Rotation ( T );
				}
				
			}
		}
		if ( T == root ) break;
		T = T -> prev;
	}
	return true;
}
Node * BalancedSearchTree :: addNode ( Node * R ) {
	return addKey ( root, R -> key );
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
