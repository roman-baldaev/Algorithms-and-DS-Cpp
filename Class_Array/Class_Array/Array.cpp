#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include <time.h>
#include "Array.h"
using namespace std;

		Array :: Array (int _n) //консруктор, принимающий в качестве аргумента целое число-размерность массива
		{
			if (_n<=0)
			{
				cout << "Uncorrect dimension, values by default";
				n=1;
				a=new int[n];
			}
			else
			{
			n=_n;
			a=new int [n];
			}
		}  
		Array :: Array (int * _a, int _n) //конструктор, принимающий в качестве аргумент другой массив и его рамерность
		{
			if (_n<=0)
			{
				cout << "Uncorrect dimension, values by default";
				n=1;
				a=new int[n];
			}
			else
			{
			a=new int [n=_n];
			for (int i=0; i < n; i++)
			{
				a[i]=_a[i];
			}
			}
		}
		Array :: Array (Array &_A) //конструктор копирования
		{
			n=_A.n;
			a=new int [n];
			for (int i=0; i<n; i++)
			{
				a[i]=_A.a[i];
			}
		}
		Array :: ~Array ()
			{
				delete [] a;
			} //деструктор
		int & Array :: operator [] (int i)  //оператор []-возвращает элемент массива объекта класса Array
		{
			if (i<0||i>=n)
			{
				cout << "Error. Uncorrect index" << endl;
				
			}
			return a[i];
		}
		void Array :: Enter () //вывод массива через функцию Enter()
		{
			if (n<=0)
			{
				cout << "Error";
			}
			else
			{
				for (int i=0; i < n; i++)
				{
					cin >> a[i];
				}
			}
		}
		void Array :: Print () //вывод массива с помощбю функции Print ()
		{
			if (n<=0)
			{
				cout << "Error";
			}
			else
			{
				for (int i = 0; i<n; i++)
				{
					cout << a[i] << " ";
				}
				cout << endl;
			}
		}
		Array & Array :: operator = (Array &B) //оператор присвоения двух объекто класса Array
		{
			Array _A;
			if (anyWay(B)==0)
			{
			_A.a=new int [n];
			for (int i = 0; i < n; i++)
			{
				_A.a[i]=a[i];
			}
			delete [] a;
			n=B.n;
			a=new int [n];
			for (int i=0; i < n; i++)
			{
				a[i]=B.a[i];
			}
			return *this;
			}
			return *this;
		}
		int Array :: operator == (Array &B) //оператор сравнения двух объектов класса Array
		{
			if (n!=B.n)
			{
				return 0;
			}
			for (int i=0; i < n; i++)
			{
				if (a[i]!=B.a[i])
				{
					return 0;
				}
			}
			return 1;
		}
		int Array :: operator != (Array &B)
		{
			if (anyWay(B)==0)
			{
				return 1;
			}
			return 0;
		}
		int Array :: getDimension ()
		{
			return n;
		}
		int Array :: Order ()//проверка на упорядоченность
		{
			int i=0, k;
			while (a[i]==a[i+1] && i<n-1)
			{
				i++;
			}
			if (i==n-1)
			{
				cout << "Order no." << endl;
				return 0;
			}
			k=i;
			if (a[i]<=a[i+1])
			{
				while (a[i]<=a[i+1] && i<n-1)
				{
					i++;
				}
				if (i==n-1)
				{ 
					cout << "Ascending order." << endl;
					return 1;
				}
			}
			i=k;
			while (a[i]>=a[i+1] && i<n-1)
			{
				i++;
			}
			if (i==n-1)
			{
				cout << "Descending order." << endl;
				return -1;
			}
			cout << "Order no." << endl;
			return 0;
		}

		int Array :: Find (int core)
		{
			for ( int i=0; i<n; i++ )
			{
				if (a[i]==core) return i;
			}
			return -1;
		}
		void Array :: addToPosition (int core, int position)
		{
			int *b, i, j;
			b=new int[n+1];
			for (i=0; i<position; i++)
			{
				b[i]=a[i];
			}
			b[position]=core;
			for (j=i, i=position+1; j<n && i<n+1; i++, j++)
			{
				b[i]=a[j];
			}
			delete [] a;
			n+=1;
			a=new int [n];
			for (int i=0; i<n+1; i++)
			{
				a[i]=b[i];
			}
			delete [] b;
		}
		Array & Array :: operator += (Array &B) // добавить к объекту массив объект типа массив (в конец)
		{
			Array _A;
			_A.a=new int [n];
			for (int i=0; i<n; i++)
			{
				_A.a[i]=a[i];
			}
			int k=n;		
			delete [] a;
			
			n=n+B.n;
			a=new int [n];
			for (int i=0; i<k; i++)
			{
				a[i]=_A.a[i];
			}
			int j=0;
			for (int i=k; i<n; i++, j++)
			{
				a[i]=B.a[j];
			}
			return *this;
		}
		Array Array :: operator + (Array &B) // сложение двух объектов
		{
			Array A(n+B.n);
			for (int i=0; i < n; i++)
			{
				A.a[i]=a[i];
			}
			for (int i=n, j=0; i<A.n && j<B.n; i++, j++)
			{
				A.a[i]=B.a[j];
			}
			return A;
		}
		Array & Array :: operator -= (int key) //удаление всех вхождений числа со значением key из объекта типа массив
		{
			int  i=0, f=0;
			for (; i<n; )
			{
				if (a[i]==key)
				{
					deleteElement (i);
					f++;
				}
				else
				{
					i++;
				}
			}
			if (f==0) 
			{
				cout << "Element with value of key not found." << endl;
			}
			return *this;
		}
		Array & Array :: operator - (int key)	//удаление из объекта типа массив	
		{
			int  i=0, f=0;
			for (; i<n; )
			{
				if (a[i]==key)
				{
					deleteElement (i);
					f++;
				}
				else
				{
					i++;
				}
			}
			if (f==0) 
			{
				cout << "Element with value of key not found." << endl;
			}
			return *this;
		}
		void Array :: deleteToPosition (int l) //удаление по позиции
		{
			deleteElement (l);
		}
		Array & Array :: operator << (int k) //сдвиг влево на k значений
		{
			while (k)
			{
				deleteElement(0);
				k--;
			}
			return *this;
		}
		Array & Array :: operator >> (int k) //сдвиг вправо на k значений
		{
			while (k)
			{
				deleteElement(n-1);
				k--;
			}
			return *this;
		}
		void Array :: Formation (int s)
		{
			srand(time(NULL));
			if (s==0)
			{
				for (int i=0; i < n; i++)
				{
					a[i]=rand()%1000;
				}
			}
			else  if (s==-1)
			{
				a[0]=rand()%1000;
				for (int i=1; i < n; i++)
				{
					a[i]=a[i-1]-rand()%1000;
				}
			}
			else if (s==1)
			{
				a[0]=rand()%1000;
				for (int i=1; i < n; i++)
				{
					a[i]=a[i-1]+rand()%1000;
				}
			}
			else 
			{
				cout << "Uncorrect parametr" << endl;
			}
		}