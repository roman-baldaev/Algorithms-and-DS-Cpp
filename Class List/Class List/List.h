class  Node // класс "Узел" - класс, описывающий основную составляющую списка
{
	int  key;
	Node  *prev, *next;
	public:
	Node (int _key=0, Node *_prev=0, Node *_next=0)
	{
		key=_key; 
		prev=_prev; 
		next=_next;
	}
	int & Key() 
	{
		return key;
	}
	Node *& Prev() 
	{
		return  prev;
	}
	Node *& Next() 
	{
		return  next;
	}

}; 
class List 
{
	Node *head, *tail;
	void del ()
	{
		Node * x;
		for (x=head->Next(); x!=tail; x=head->Next())
		{
			x->Prev()->Next()=x->Next();
			x->Next()->Prev()=x->Prev();
		}
		delete x;
	}
	void add (Node * x,int _key)
	{
		Node * _x= new Node (_key, x, x->Next());
		x->Next()=_x;
		_x->Next()->Prev()=_x;

	}
	void  del (Node * x)  
	{
		x->Prev()->Next()=x->Next();
		x->Next()->Prev()=x->Prev();
	}
	void swap (Node * a, Node * b)
	{
		int data;
		data=a->Key();
		a->Key()=b->Key();
		b->Key()=data;
	}
	public:
	List(); //конструктор по умолчанию
	List (int *, int); //конструктор с аргументами в виде массива ключей и размерности
	~List ();
	List (List&);
	List & operator = (List &);
	
	void addOnPosition (int, int);
	void addToTail(int);
	void addList(const List &);
	void addAfterKey (int);
	
	void deleteOfHead();
	void deleteOfTail();
	void deleteOfPosition(int);
	void deleteKey(int);

	bool isEmpty()  
	{
		if (head->Next() == tail) return true;
		return  false;
	}

	Node* findKey (int);
	Node* findPosition (int);
	int findMax();
	int findMin();

	void Input();
	void Output();

	void sort (int);
}; //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
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
		for (int i=0, Node *p=head; i<n; i++, p=p->Next())
		{
			add ( p, keys[i]);
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
		tail= new Node (0, head);
		head->Next()=tail;
		Node *p=l.head; 
		Node *_p=head;
		for (p->Next(); p!=l.tail; p=p->Next(), _p=_p->Next())
		{
			add (_p, p.Key());
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
		Node *p=l.head; 
		Node *_p=head;
		for (p->Next(); p!=l.tail; p=p->Next(), _p=_p->Next())
		{
			add (_p, p.Key());
		}
		return *this;
	}
	void List:: addOnPosition (int position, int key)
	{  
		Node* p = findPosition(position);
		Add(p->Prev(), key);
	}
	void List:: addToTail( int key)
	{
		Node* p=tail->Prev();

		if(p->Next() != head)
		{
			Add(tail->Prev(), key);
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
		Node * p = head->Next();
		Node * pn = p->Next();
		if (k==1)
		{
			while (pn!=tail)
			{
				if (p->Key()>pn->Key())
				{
					swap (p, pn);
					if (p!=head->Next())
					{
						p=p->Prev();
						pn=pn->Prev();
					}
				}
				p=p->Next();
				pn=pn->Next();
			}
		}
	}


 