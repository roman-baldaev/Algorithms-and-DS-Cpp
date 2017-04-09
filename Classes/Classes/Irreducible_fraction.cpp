#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;
#include "Irreducible_fraction.h"
#include <math.h>

	
		Irreducible_fraction :: Irreducible_fraction (int _numerator, int _denominator)
		{
			
			numerator=_numerator;
			denominator=_denominator;
			
		}
		Irreducible_fraction :: Irreducible_fraction (const Irreducible_fraction &cpy)
		{
			numerator=cpy.numerator;
			denominator=cpy.denominator;
		}
		void Irreducible_fraction :: Check1 (Irreducible_fraction &f)
		{
			if ((f.numerator<0)&&(f.denominator<0))
			{
				f.numerator*=-1;
				f.denominator*=-1;
			}
			if ((f.numerator>0)&&(f.denominator<0))
			{
				f.numerator*=-1;
				f.denominator*=-1;
			}
			
			if (f.denominator==0)
			{
				
				f.numerator=0;
				f.denominator=1;
			}
			if (f.numerator==0)
			{
				f.numerator=0;
				f.denominator=1;
				
			}
			else
			{
				int k=Euclid_algorithm (f);
				f.numerator=f.numerator/k;
				f.denominator=f.denominator/k;
			}
		}
		int Irreducible_fraction :: Check ()
		{
			if ((numerator<0)&&(denominator<0))
			{
				numerator*=-1;
				denominator*=-1;
			}
			if ((numerator>0)&&(denominator<0))
			{
				numerator*=-1;
				denominator*=-1;
			}
			if (denominator==0)
			{
				cout<<"Division by zero is forbidden. Please enter new values." << endl;
				return 0;
			}
			if (numerator==0)
			{
				cout<<"This an NULL. Please enter new values" << endl;
				return 0;
			}
			int k=Euclid_algorithm (*this);
			numerator=numerator/k;
			denominator=denominator/k;
			if (numerator%denominator==0)
			{
				cout<<"This is an integer " << numerator << ". Please enter new values." << endl;
				return 0;
			}
		
			
			cout << "Fractions reduction to standard form." << endl;
			return 1;
		}
		void Irreducible_fraction::setNumerator (int N)
		{
			numerator=N;
		}
		void Irreducible_fraction::setDenominator (int D)
		{
			denominator=D;
		}
		int Irreducible_fraction::getNumerator ()
		{
			return numerator;
		}
		int Irreducible_fraction::getDenominator ()
		{
			return denominator;
		}
		void Irreducible_fraction :: Enter ()
		{
	
			cout <<  "Enter numerator: ";
			cin >> numerator;;
			cout << "Enter denominator: ";
			cin >> denominator;
			cout << endl;
			while (Check()==0)
			{
				cout <<  "Enter numerator: ";
				cin >> numerator;;
				cout << "Enter denominator: ";
				cin >> denominator;
				cout << endl;
			}
		
		}
		void Irreducible_fraction :: Print ()
		{
			if (Check()!=0)
			{
				cout << numerator << "/" << denominator<< endl;
			}
			else
			{
				if (numerator%denominator==0)
				{
					cout << numerator << endl;
				}
			}
		}
		int Irreducible_fraction :: Max(int a, int b)
		{
			if (a>b) return a;
			else return b;
		}
		int Irreducible_fraction :: Min(int a, int b)
		{
			if (a<b) return a;
			else return b;
		}
		int	Irreducible_fraction :: Euclid_algorithm (Irreducible_fraction &eA)
		{
			int R=-1,k,N,D,l;
			N=abs(eA.numerator); D=abs(eA.denominator);
			while (R!=0)
			{
				l=R;
				k=Max(N,D)/Min(N,D);
				R=Max(N,D)-k*Min(N,D);
				if (R==0) 
				{
					l=Min(N,D);
				}
				N=Min(N,D);
				D=R;
			}
				return l;
			
		}
		Irreducible_fraction Irreducible_fraction :: operator + (const Irreducible_fraction &add)
		{
			Irreducible_fraction sum;
			sum.numerator=numerator*add.denominator+add.numerator*denominator;
			sum.denominator=denominator*add.denominator;
			Check1(sum);
			return sum;
		}
		Irreducible_fraction Irreducible_fraction :: operator - (const Irreducible_fraction &sub)
		{
			Irreducible_fraction diff;
			diff.numerator=numerator*sub.denominator-sub.numerator*denominator;
			diff.denominator=denominator*sub.denominator;
			Check1 (diff);
			return diff;
		}
		Irreducible_fraction Irreducible_fraction :: operator * (const Irreducible_fraction &multip)
		{
			Irreducible_fraction op;
			op.numerator=numerator*multip.numerator;
			op.denominator=denominator*multip.denominator;
			Check1(op);
			return op;
		}
		Irreducible_fraction Irreducible_fraction :: operator / (const Irreducible_fraction &segmen)
		{
			Irreducible_fraction quotient;
			quotient.numerator=numerator*segmen.denominator;
			quotient.denominator=segmen.numerator*denominator;
			Check1(quotient);
			return quotient;
		}

