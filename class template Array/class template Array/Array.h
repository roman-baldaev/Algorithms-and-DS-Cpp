#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include <time.h>
using namespace std;
template <typename T> class Array
{
	T *a; int n;
	void deleteElement (int l)
		{
			T *b; int i;
			b=new T [n];
			for (int i=0; i<n;i++)
			{
				b[i]=a[i];
			}
			delete [] a;
			n-=1;
			a=new T [n];
			for (i=0; i<l; i++)
			{
				a[i]=b[i];
			}
			int j=l+1;
			for (; i<n && j<n+1; i++, j++)
			{
				a[i]=b[j];
			}
			delete [] b;
		}
	public:
			Array (int = 1);
			Array (T *, int );
			Array (Array <T> &);
			~Array ();
			T& operator [] (int );
			void Enter ();
			void Print ();
			Array <T> & operator = (Array <T> &);
			int operator == (Array <T> &);
			int operator != (Array <T> &);
			int getDimension ();
			int findElement (T);
			void addToPosition (T, int);
			Array <T> & operator += (Array <T> &);
			Array <T> & operator -= (T);
			Array <T> & operator - (T);
			void deleteToPosition (int);
			Array <T> & operator << (int);
			Array <T> & operator >> (int);
			Array <T> operator + (Array <T> &);

		

};



		template <typename T> Array <T>  :: Array (int _n) //консруктор, принимающий в качестве аргумента целое число-размерность массива
		{
			if (_n<=0)
			{
				cout << "Uncorrect dimension, values by default";
				n=1;
				a=new T[n];
			}
			else
			{
			n=_n;
			a=new T [n];
			}
		}  
		template <typename T> Array <T> :: Array (T * _a, int _n) //конструктор, принимающий в качестве аргумент другой массив и его рамерность
		{
			if (_n<=0)
			{
				cout << "Uncorrect dimension, values by default";
				n=1;
				a=new T [n];
			}
			else
			{
			a=new T [n=_n];
			for (int i=0; i < n; i++)
			{
				a[i]=_a[i];
			}
			}
		}
		template <typename T> Array <T> :: Array (Array <T> &_A) //конструктор копирования
		{
			n=_A.n;
			a=new T [n];
			for (int i=0; i<n; i++)
			{
				a[i]=_A.a[i];
			}
		}
		template <typename T> Array <T> :: ~Array ()
			{
				delete [] a;
			} //деструктор
		template <typename T>  T& Array <T> :: operator [] (int i)  //оператор []-возвращает элемент массива объекта класса Array
		{
			if (i<0||i>=n)
			{
				cout << "Error. Uncorrect index" << endl;
				
			}
			return a[i];
		}
		template <typename T> void Array <T> :: Print () //вывод массива с помощбю функции Print ()
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
		template <typename T> void Array <T> :: Enter () //вывод массива через функцию Enter()
		{
			if (n<=0)
			{
				cout << "Error";
			}
			else
			{
				cout << "Enter elements of array:" << endl; 
				for (int i=0; i < n; i++)
				{
					cin >> a[i];
				}
			}
		}
		template <typename T> Array <T>  & Array <T> :: operator = (Array <T> &B) //оператор присвоения двух объекто класса Array
		{
			if (a!=B.a)
			{
			
			delete [] a;
			n=B.n;
			a=new T [n];
			for (int i=0; i < n; i++)
			{
				a[i]=B.a[i];
			}
			return *this;
			}
			return *this;
		}
		template <typename T> int Array <T> :: operator == (Array <T> &B) //оператор сравнения двух объектов класса Array
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
		template <typename T> int Array <T> :: operator != (Array <T> &B)
		{
			if (n!=B.n)
			{
				return 1;
			}
			for (int i=0; i < n; i++)
			{
				if (a[i]!=B.a[i])
				{
					return 1;
				}
			}
			
			return 0;
		}
		template <typename T> int Array <T> :: getDimension ()
		{
			return n;
		}
		template <typename T> int Array <T> :: findElement (T core)
		{
			for ( int i=0; i<n; i++ )
			{
				if (a[i]==core) return i;
			}
			return -1;
		}
		template <typename T> void Array <T> :: addToPosition (T core, int position)
		{
			T *b; 
			int i, j;
			b=new T[n+1];
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
			a=b;
		}
		template <typename T> Array <T> & Array <T> :: operator += (Array <T> &B) // добавить к объекту массив объект типа массив (в конец)
		{
			int i,j;
			T *b;
			b=new T [n+B.n];
			for (i=0; i<n; i++)
			{
				b[i]=a[i];
			}
			
			for (j=0; i<n+B.n && j<B.n; i++, j++)
			{
				b[i]=B.a[j];
			}	
			delete [] a;
			n+=B.n;
			a=b;
			
			return *this;
		}
		template <typename T> Array <T> & Array <T>:: operator -= (T key) //удаление всех вхождений ключа со значением key из объекта типа массив
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
		template <typename T> Array <T> & Array <T>:: operator - (T key) //удаление элемента по значению  из объекта типа массив
		
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
		template <typename T> void Array <T> :: deleteToPosition (int l) //удаление по позиции
		{
			deleteElement (l);
		}
		template <typename T> Array <T> & Array <T> :: operator << (int k) //сдвиг влево на k значений
		{
			if (k>n)
			{
				cout << "Error" << endl;
			}
			else
			{
			while (k)
			{
				deleteElement(0);
				k--;
			}
			}
			return *this;
		}
		template <typename T> Array <T> & Array <T> :: operator >> (int k) //сдвиг вправо на k значений
		{
			if (k>n)
			{
				cout << "Error" << endl;
			}
			else
			{
			while (k)
			{
				deleteElement(n-1);
				k--;
			}
			}
			return *this;
		}
		template <typename T> Array <T> Array <T> :: operator + (Array <T> &B) // сложение двух объектов
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
