#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <time.h> 
#include <iostream> 
using namespace std; 

struct Usel
{
	char sign; 
	int key;
	Usel *next;
	Usel() {sign=' ';key=0; next=NULL;}
};
struct  Stack
{
	Usel *head;
	Stack() {head=NULL;}
	
	void Push(char k);
	char Pop();
	char Top() 
	{	 
		 if (!Empty()) return head->sign;
		 return ' ';
	} 
	bool Empty()
	{
		if (head) return false;
		return true;
	}
	void Print();
};
void Stack:: Push(char k)
{	
	Usel *u=new Usel;
	u->sign=k; u->next=head; head=u;
}
char Stack:: Pop()
{	
	if (!Empty())
	{
		 char k=head->sign;
		 Usel *p=head; 
		 head=head->next;
		 delete p; 
		 return k;
	}
	 puts ("Stack empty");
	 return ' ';
}



void Stack:: Print()
{
	Usel *p;
	for (p=head; p; p=p->next)
	cout << p->sign;
}

	


