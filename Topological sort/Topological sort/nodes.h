#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include <time.h>
using namespace std;

class leader 
{
	friend class trailer;
	int key;
	int st;
	leader *nextldr;
	trailer *tr;
	public:
		leader (int _key=0, int _st=0, leader *_nextldr=NULL)
		{
			key=_key; 
			st=_st; 
			nextldr=_nextldr;
		}
		int & Key ()
		{
			return key;
		}
		int & St ()
		{
			return st;
		}
		leader *& Leader ()
		{
			return nextldr;
		}
		trailer *& Trailer ()
		{
			return tr;
		}

};
class trailer
{
	friend class leader;
	leader *ldr;
	trailer *next;
	public:
		trailer (leader *_ldr=NULL,trailer *_next=NULL)
		{
			ldr=_ldr;
			next=_next;
		}
	leader *& Ldr ()
	{
		return ldr;
	}
	trailer *& Next ()
	{
		return next;
	}
};
class topologicalSort
{
	leader *LD, *pa, *pb;
	public:
		void formLeader ()
		{
			int a, b, n;
			cout << "Enter number of vertises: " << endl;
			cin >> n;
			cout << endl;
			for (int i=1; i<=n; i++)
			{
				cout << "Enter a" << i << ":" << endl;
				cin >> a;
				cout << "Enter b" << i << ":" << endl;
				cin >> b;
				if (a==0) break;
				if (findKey(a)) pa=findKey(a);
				else 
				{
					leader *q=new leader; 
					q->Key()=a;
					q->Leader()=LD;
					q->St()=0;
					q->Trailer()=NULL;
					pa=LD;
				}
				
				if (findKey(b)) pb=findKey(b);
				else 
				{
					leader *q=new leader; 
					q->Key()=b;
					q->Leader()=LD;
					q->St()=0;
					q->Trailer()=NULL;
					pb=LD;
				}
				pb->St()++;
				pa->Trailer()->Ldr()=pb;
			}
		}
		void show_descendants (int k)
		{
			leader *p=findKey(k);
			trailer *t=p->Trailer();
			for (;t!=NULL; t=t->Next())
			{
				cout << t->Ldr()->Key() << endl;
			}
		}
		leader *  findKey(int key)
		{
			leader *p =LD;
			for(p=LD; p!=NULL; p=p->Leader())
			if  (p->Key() == key) return p;
				return 0;
		}
};