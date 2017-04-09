#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>
	#include <time.h>
	#include "razbienie.h"
#include "sliyanie.h"

	void main ()
	{
		FILE *C;
		int f=0;
	
		while (!f)
		{
			razbienie ("C://files//A.txt", "C://files//B.txt", "C://files//C.txt");
			fcloseall ();
			C=fopen ("C://files//C.txt", "r");
			
			if (feof(C)) f=1;
		
			else
			{
				fcloseall ();
				sliyanie ("C://files//A.txt", "C://files//B.txt", "C://files//C.txt");
				fcloseall ();
			}
		}	
	}
		
		
