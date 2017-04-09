#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include <time.h>
#include "BM.h"

using namespace std;

void main ()
{
	int m, n;
	cout << "Enter m and n:";
	cin >> m >> n;
	cout << endl;
	BM A(m,n);
	BM B(m,n);
	cout << "Enter A:"<<  endl;
	A.Input(m,n);
	cout << endl;
	
	cout << "Enter B: " << endl;
	B.Input(m,n);
	cout << endl;
	
	A&=B;
	A.Output();
	cout << endl;
	A|=B;
	A.Output();
	int i,j;
	cout << "Enter positions for set 1:";
	cin >> i >> j;
	cout << endl;
	A.Set_1(i,j);
	A.Output();
	cout << endl;
		cout << "Enter positions for set 0:";
		int x,z;
		cin >> x >> z;
	cout << endl;
	A.Set_0(x,z);
	A.Output();
	cout << endl;
	cout << "Weight of boolean matrix:" << A.WeightBM() << endl;

}