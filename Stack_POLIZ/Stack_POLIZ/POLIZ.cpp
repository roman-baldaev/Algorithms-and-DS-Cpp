#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <time.h> 
#include <iostream> 
#include "Stack.h"
using namespace std; 
int Prior (char a)
	{
		if (a=='(') return 0;
		if (a==')') return 1;
		if ((a=='-')||(a=='+')) return 2;
		if ((a=='*')||(a=='/')) return 3;
		if (a=='^') return 4;
		if (a<='9' && a>='0') return -1;
	}
int Check (char a)
{
	if (a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9'||a=='0'||a=='-'||a=='+'||a=='*'||a=='/'||a=='^') return 1;
	return 0;
}
	
void main ()
{
	int i,j;
	char *s, *POLIZ, m;
	s=new char[80];
	POLIZ=new char [80];
	Stack poliz;
	char h='9';
	int h1;
	h1=(int)'9'-(int)'0';
	cout << h1+10;
	getch();
	cout << "Enter s: " << endl;
	gets (s) ;

	for (i=j=0; i < strlen(s); i++)
	{
		if (Prior(s[i])<0) 
		{	
			POLIZ[j]=s[i];
			j++;
		}
		else
		{
			if (s[i]=='(') poliz.Push(s[i]);
			else if (s[i]==')')
			{
				while (poliz.Top()!='(')
				{
					POLIZ[j]=poliz.Pop();
					j++;
				}
				m=poliz.Pop();
			}
			else 
			{
				int si=Prior(s[i]);
				int pt=Prior(poliz.Top());
				while ((!(poliz.Empty()))&&(si<=pt)&&(si>=0))
				{
					POLIZ[j]=poliz.Pop();
					j++;
					pt=Prior(poliz.Top());
				}
					
				if (poliz.Empty()||(si>=pt))
				{
					poliz.Push(s[i]);
				}
			}
		}	
	}
	while ((!poliz.Empty()))
	{
		POLIZ[j]=poliz.Pop();
		j++;
	}
	int LEN_POLIZ=j;
	char *NEW_POLIZ;
	Stack poliz1;
	for (i=0; i<j; i++)
	{
		int a,b,c;
		if (Prior(POLIZ[i])==-1)
		{
			poliz1.Push(POLIZ[i]);
		}
		else 
		{
			b=(int)(poliz1.Pop())-(int)'0';
			a=(int)(poliz1.Pop())-(int)'0';
			
			switch (POLIZ[i])
			{
			case '+': c=a+b; break;
			case '-': c=a-b; break;
			case '*': c=a*b; break;
			case '/': c=a/b; break;
			case '^': { a=1; for (int k=1; k<=b;k++) a*=a;;} break;
			}
			
			poliz1.Push((char)(c+(int)'0'));
		}
	}
		cout << poliz1.Pop()<< endl;
	puts (POLIZ);
	getch ();
}