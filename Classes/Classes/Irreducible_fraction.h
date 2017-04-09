#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <math.h>
using namespace std;

class Irreducible_fraction
{
	public:
		
	
		Irreducible_fraction (int=0, int=1);
		Irreducible_fraction (const Irreducible_fraction &);
		void Check1 (Irreducible_fraction &);
		int Check ();
		void setNumerator (int);
		void setDenominator (int);
		int getNumerator ();
		int getDenominator ();
		void Enter ();
		void Print ();
		int Max(int , int );
		int Min(int , int );
		int Euclid_algorithm (Irreducible_fraction &);
		Irreducible_fraction operator + (const Irreducible_fraction &);
		Irreducible_fraction operator - (const Irreducible_fraction &);
		Irreducible_fraction operator * (const Irreducible_fraction &);
		Irreducible_fraction operator / (const Irreducible_fraction &);
	private:
		int numerator, denominator;
		
	
};