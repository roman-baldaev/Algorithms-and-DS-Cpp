#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>
	#include <time.h>
	#include "razbienie.h"
#include "sliyanie.h"
#include <iostream>

using namespace std;

	void main ()
	{
		FILE *A, *source, *C;
		int f=0, n;
		cout << "Enter amount of numbers: ";
		cin >> n;
		
		source=fopen("C://files//source.txt", "w");
		for ( int i = 0; i < n; i++) {
			fprintf ( source, "%d ", rand()%100 );
		}
		fcloseall ();
		A = fopen ("C://files//A.txt", "w");
		source=fopen("C://files//source.txt", "r");
		int x;
		for ( int i = 0; i < n; i++) {
			fscanf ( source, "%d", &x);
			fprintf ( A, "%d ", x);
		}
		fcloseall ();
		while (!f)
		{
			razbienie ("C://files//A.txt", "C://files//B.txt", "C://files//C.txt");
			
			C=fopen ("C://files//C.txt", "r");
			int x;
			fscanf(C,"%d",&x);
			if (feof(C)) {
				f=1;
				
			}
			fcloseall();
			if (!f)
			{
				
				sliyanie ("C://files//A.txt", "C://files//B.txt", "C://files//C.txt");
				
			}
			
		}	
	}
		
		
