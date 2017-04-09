#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>
void sliyanie (char *a, char *b, char *c)
{
	int b1,b2,c1,c2;
	FILE *A,*B,*C;
	A=fopen (a, "w");
	B=fopen (b, "r");
	C=fopen (c, "r");
	fscanf (B, "%d", &b1); 
	fscanf (C, "%d", &c1);
    while (!feof(B)&&!feof(C))
	{
 	 	if (b1<c1)
		  {
		  		  fprintf (A, "%d ", b1);
		  		  fscanf (B, "%d", &b2);
		  		  if ((!feof(B))&&(b1>b2))
		  		  {
                            fprintf (A, "%d ", c1);
  		     				fscanf (C, "%d", &c2);
  		     				while ((!feof(C))&&(c1<=c2))
  		     				{
  		     					c1=c2;
  		     					 fprintf (A, "%d ", c1);
		  		  				 fscanf (C, "%d", &c2);
  		     				}
  		     				c1=c2;
		  		  }
		  		  b1=b2;
		  }  
		  else
		  {
                   fprintf (A, "%d ", c1);
				   fscanf (C, "%d", &c2);
				   if ((!feof(C))&&(c1>c2))
				   {
				   	  fprintf (A, "%d ", b1);
		  		  	  fscanf (B, "%d", &b2);
		  		  	  while ((!feof(B))&&(b1<=b2))
		  		  	  {
		  		  	  	b1=b2;
	  	  	            fprintf (A, "%d ", b1);
				        fscanf (B, "%d", &b2);
		  		  	  }
  		  	    	  b1=b2;
				   }
				   c1=c2;
		  }
	}
	
	while (!feof(B))
	{
		fprintf (A, "%d ", b1);
		fscanf (B, "%d", &b1);
	}
	while (!feof(C))
	{
		fprintf (A, "%d ", c1);
		fscanf (C, "%d", &c1);
	}
}