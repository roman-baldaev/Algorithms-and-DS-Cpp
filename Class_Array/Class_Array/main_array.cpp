#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include "Array.h"
using namespace std;

void main ()
{

	Array C(10), D(10), E(10), B;
	cout << "Enter C" << endl;
	C.Formation(-1);
	D.Formation(0);
	E.Formation(1);
	C.Print();
	D.Print();
	E.Print();
	getch ();
	B=(C<<2)+(D<<2)+E-0;
	B.Print();
	
	


}