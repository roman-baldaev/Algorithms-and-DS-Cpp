#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <list>
#include <set>

using namespace std;
bool check_easy (int a)
{
	int i;
	if ((a==1)||(a==0)) return false;
	for (i=2; i<=a/2; i++)
	{
		if (a%i==0) return false;
	}
	return true;
}
int max (vector <int> a)
{
	int i, max=a[0];
	for (i=1; i<a.size(); i++)
	{
		if (max<a[i]) max=a[i];
	}
	return max+1;
}
void vector_1 (vector <int> & a, vector <int> & b) //создать массив уникальных чисел заданного массива
{
	a.clear();
	b.clear();
	int i,j,s,n,*tab;
	cout << "Enter the number of numbers: " << endl;
	cin >> n;
	
	
	for (i=0; i < n; i++)
	{
		a.push_back(rand()%100);
	}
	tab=new int[max(a)];
		for (i=0; i < max(a); i++)
	{
		
		tab[i]=0;
	}
	for (i=0; i < n; i++)
	{
		
		tab[a[i]]++;
	}
	for (i=0; i < max(a); i++)
	{
		if (tab[i]!=0) b.push_back(i);
	}
}
void vector_2 (vector <int> & a, vector <int> & b) //в вектор а помещаются рандомные числа,а из них в вектор b выбираются простые.
{
	int i,j,n;
	a.clear();
	b.clear();
	cout << "Enter the number of elements in the array: " << endl;
	cin >> n;
	srand(time(NULL));
	for (i=0; i<n; i++)
	{
		a.push_back(rand()%100);
	}
	for (i=0; i<a.size(); i++)
	{
		if (check_easy(a[i])) 
		{
			b.push_back(a[i]);
		}
	}
}

void vector_5 (vector <string> & a)  //удаление самой длинной строки
{
	int i;
	vector<string>::iterator imax = a.begin();
	vector<string>::iterator k = a.begin();
	for (; imax!=a.end(); imax++)
	{
		if ((k->length())<(imax->length()))
		{
			k=imax;
		
		}
	}
	k=a.erase (k);


}

void vector_6 (vector <int> & a, vector <int> & b) //из чисел фиббоначи выбираются четные и заносятся в новый массив
{
	a.clear();
	int n,i,j;
	cout << "Enter the number of numbers: " << endl;
	cin >> n;
	if (n==1) a.push_back(0);
	if (n==2) 
	{
		a.push_back(0);
		a.push_back(1);
	}
	if (n>2)
	{
		a.push_back(0);
		a.push_back(1);
		for (i=2; i<n; i++)
		{
			a.push_back(a[i-2]+a[i-1]);
		}
	}
	for (i=0; i<a.size(); i++)
	{
		if (a[i]%2==0) b.push_back(a[i]);
	}
}

void list_3 (list <string> & a, string fam)  // перед самой длинной фамилией в списке ставится фамилия fam
{
	int i,j,n;
	list<string>::iterator max=a.begin(), next=a.begin();
	for (; next!=a.end(); next++)
	{
		if (next->length()>max->length()) max=next;
	}
	a.insert(max, fam);
}
void list_8 (list <string> & a)  // вывод и удаление самой длинной фамилии
{
	int i,j,n;
	list<string>::iterator max=a.begin(), next=a.begin();
	for (; next!=a.end(); next++)
	{
		if (next->length()>max->length()) max=next;
	}
	cout << "The most long name is " << *max << endl;
	a.erase(max);
}
void set_9 (char *s1, char *s2) //количество используемых символов в двух разных приложениях
{
	int i;
	set <char> ss1,ss2;
	for (i=0; i<strlen(s1); i++)
	{
		ss1.insert(s1[i]);
	}
	for (i=0; i<strlen(s2); i++)
	{
		ss2.insert(s2[i]);
	}
	if (ss1.size()>ss2.size()) cout << "In this proposal, more characters: " << s1 << endl;
	if (ss1.size()<ss2.size()) cout << "In this proposal, more characters: " << s2 << endl;
	if (ss1.size()==ss2.size()) cout << "The proposals the same number of characters."<< endl;

}

void main ()
{
	/*
	vector <int> a,b;
	vector_2 (a,b);
	for (int i=0; i<a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i=0; i<b.size(); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	NEW_VECTOR_5
	int i,n,j;
	

	vector <string> a;
	cout << "Enter the number of words: " << endl;
	cin >> n;
	cout << endl;
	string *s;
	s=new string[n+1];
	for (i=0; i < n+1; )
	{
		getline (cin, s[i]);
		i++;
	}
	for (i=0; i < n+1; i++)
	{
		a.push_back(s[i]);
	}
	vector_5 (a);
	for (int i=0; i<a.size(); i++)
	{
		cout<<a[i]<<" ";
	}
	cout << endl;
	
	NEW_VECTOR_6
	vector <int> a,b;
	vector_6 (a,b);
	for (int i=0; i<a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i=0; i<b.size(); i++)
	{
		cout << b[i] << " ";
	}
	

	NEW_VECTOR_1
		vector <int> a,b;
	vector_1 (a,b);
	for (int i=0; i<a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i=0; i<b.size(); i++)
	{
		cout << b[i] << " ";
	}
	NEW LIST_3
	int i,n;
		list <string> a;
	cout << "Enter the number of families: " << endl;
	cin >> n;
	cout << endl;
	string *s, fam;
	cin >> fam;
	s=new string[n+1];
	for (i=0; i < n+1; )
	{
		getline (cin, s[i]);
		i++;
	}
	for (i=0; i < n+1; i++)
	{
		a.push_back(s[i]);
	}
	list_3 (a, fam);
	list<string>::iterator next;
	for (next=a.begin(); next!=a.end(); next++)
	{
		cout<<*next<<endl;
	}
	
	NEW_LIST_8
		int i,n;
		list <string> a;
		string *s;
	cout << "Enter the number of families: " << endl;
	cin >> n;
	cout << endl;
	
	s=new string[n+1];
	for (i=0; i < n+1; )
	{
		getline (cin, s[i]);
		i++;
	}
	for (i=0; i < n+1; i++)
	{
		a.push_back(s[i]);
	}
	list_8 (a);
	list<string>::iterator next;
	for (next=a.begin(); next!=a.end(); next++)
	{
		cout<<*next<<endl;
	}
	*/
	char s[80], s2[80];
	gets (s);
	gets (s2);
	set_9 (s,s2);

}