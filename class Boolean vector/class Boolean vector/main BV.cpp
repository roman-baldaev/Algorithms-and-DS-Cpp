#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include <time.h>
#include "BV.h"

using namespace std;

void main ()
{
	char a[80], b[80];
	cout << "Enter boolean vector: ";
	BV A;
	A.Input ();
	A.Output();
	cout << endl;

	cout << "Enter boolean vector for logical operations: ";
	BV B;
	B.Input();
	B.Output();
	cout << endl;
	cout << "A&B:" ;
	A&=B;
	A.Output();
	cout << endl;
	cout << "A|B:" << endl;
	A|=B;
	A.Output();
	cout << " Enter index and number for set 1:" << endl;
	int i,k;
	cin >> i >> k;
	A.Set_1(i,k);
	A.Output();
	cout << "Enter number of <<:";
	int j;
	cin >> j;
	cout << endl;
	A<<=j;
	A.Output();
	cout << endl;
	~A;
	

}