// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
#pragma once

// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include <time.h>
#include <stdlib.h>

// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
class Node {
		friend class binaryTree;
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
	private:
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
	

};
void PrintT(Graphics^ , Node , int , int , int , int ); //print function
void addKey ( Node *, int ); 
