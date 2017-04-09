#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>
void razbienie (char *a, char *b, char *c)
{
	FILE *A,*B, *C;
	int a1, a2;
	A=fopen (a, "r");
	B=fopen (b, "w");
	C=fopen (c, "w");
	fscanf (A, "%d", &a1);
	while (!feof(A))
	{
			
				if (!feof(A))
				{
					fprintf (B, "%d ", a1);
					fscanf (A, "%d", &a2);
				
				while ((a1<=a2)&&(!feof(A)))
				{
				a1=a2;
				fprintf (B, "%d ", a1);
				fscanf (A, "%d", &a2);
				}
				}
				a1=a2;
	
				if (!feof(A))
				{
					fprintf (C, "%d ", a1);
					fscanf (A, "%d", &a2);
				
	
				while ((a1<=a2)&&(!feof(A)))
				{
				a1=a2;
				fprintf (C, "%d ", a1);
				
				fscanf (A, "%d", &a2);
				}
				}
				a1=a2;
	}
				
	
}