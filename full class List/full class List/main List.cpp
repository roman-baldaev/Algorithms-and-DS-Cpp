#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include <time.h>
#include "List.h"
using namespace std;

void main ()
{
	
	int a[5];
	for (int i=0; i<5; i++)
	{
		cin >> a[i];
	}
	List B(a,5);
	B.sort(1);
	B.Output();
	List C=B;
	C.Output();
	
}
