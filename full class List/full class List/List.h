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
 
	