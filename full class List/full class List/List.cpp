#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include <time.h>
#include "List.h"
using namespace std;

List :: List ()
	{
		head = new Node;
		tail = new Node (0, head);
		head->Next()=tail;
	}
	List :: List ( int * keys, int n)
	{
		head= new Node;
		tail= new Node (0, head);
		head->Next()=tail;
		Node *p=head;
		for (int i=0; i<n; i++)
		{
			add ( p, keys[i]);
			p=p->Next();
		}
	}
	List :: ~List()
	{
		del(); 
		delete  head; 
		delete  tail;
	}
	List :: List (List &l)
	{
		head= new Node;
		tail=new Node;
		head->Next()=tail;
		tail->Prev()= head;
		Node *p=l.head->Next(); 
		Node *_p=head;
		for (; p!=l.tail; p=p->Next(), _p=_p->Next())
		{
			add (_p, p->Key());
		}
	}
	List & List :: operator = (List &l)
	{
		del(); 
		delete  head; 
		delete  tail;
		head= new Node;
		tail= new Node (0, head);
		head->Next()=tail;
		Node *p=l.head->Next(); 
		Node *_p=head;
		for (; p!=l.tail; p=p->Next(), _p=_p->Next())
		{
			add (_p, p->Key());
		}
		return *this;
	}
	void List:: addOnPosition (int position, int key)
	{  
		Node* p = findPosition(position);
		add(p->Prev(), key);
	}
	void List:: addToTail( int key)
	{
		Node* p=tail->Prev();

		if(p->Next() != head)
		{
			add(tail->Prev(), key);
		}
	}
	void List:: addAfterKey (int key)
	{
		Node *p = findKey(key);
		add(p, key);

	}
	void List:: addList(const List &x)  
	{
		Node *p;
		for(p=x.head->Next(); p!=x.tail; p=p->Next())
		{
			addToTail(p->Key());
		}
	}
	void List:: deleteOfPosition(int position)
{
	Node *p = findPosition (position);
	del(p);
}
	void List:: deleteOfHead()
	{
		del(head->Next());
	}
	void List:: deleteOfTail()
	{
		del(tail->Prev());
	}
	Node* List:: findKey(int key)
	{
		for(Node *p = head->Next(); p!=tail; p=p->Next())
		if  (p->Key() == key) return p;
			return 0;
	 }
	Node* List:: findPosition(int position)
	{
		int i;
		Node* p=head->Next();
	  for(i = 1; p != tail && i < position; i++, p = p->Next());
	  if (p == tail) cout << "Number uncorrect " ;
	  return p;
	}
	void List:: deleteKey(int key)
	{
		Node *p = findKey(key);
		if (p) del(p);
	}


	int List:: findMax ()
	{ 
		int Max = head->Next()->Key();
	  for(Node* p = head->Next(); p != tail; p = p->Next())
		  if(p->Key() >= Max) Max = p->Key();
	  return Max;
	}
	int List:: findMin()
	{ 
		int Min = head->Next()->Key();
		for(Node* p = head->Next(); p != tail; p = p->Next())
		  if(p->Key() <= Min)
			  Min = p->Key();
	  return Min;
	}
	void List::  Input()
	{
		int size;
		int i;
		int x;

	  del();
	  cout << "Input size" << ' '; cin >> size;
	  cout << "Input keys: ";
	  for (i = 1; i <= size; i++) 
	  {cin >> x; addToTail(x);}
	}
	void List:: Output()
	{
		cout << "The List: ";
		for  (Node *p = head->Next(); p != tail; p=p->Next())
		cout << p->Key()<< ' ';
	}
	void List :: sort (int k)
	{
		Node *p=head->Next()->Next();
		for(;p!=tail;p=p->Next())
		{
			Node *pn=p;
			Node *pn1=p->Prev();
			for	(;pn->Key()<pn1->Key() && pn!=head->Next();pn=pn->Prev(), pn1=pn1->Prev()) 
			swap(pn, pn1); 
		}

	}