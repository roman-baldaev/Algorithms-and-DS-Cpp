#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;
#include "Irreducible_fraction.h"
#include <math.h>

void main ()
{
	Irreducible_fraction one, two,sum,diff,op,quo;
	one.Enter();
	one.Print();
	two.Enter();
	two.Print();
	sum=one+two;
	sum.Print();
	diff=one-two;
	diff.Print();
	op=one*two;
	op.Print();
	quo=one/two;
	quo.Print();
	getch ();
	
}