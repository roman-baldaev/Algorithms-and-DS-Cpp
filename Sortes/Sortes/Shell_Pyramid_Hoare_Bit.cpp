#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>
	#include <time.h>
#include <iostream>
using namespace std ;

void Shell_Sort (int *a, int n)
{
	

	int i,j,k, C;
	
	for(k = n/2; k > 0; k /=2)
        for(i = k; i < n; i++)
        {
            C = a[i];
            for(j = i; j>=k; j-=k)
            {
                if(C < a[j-k])
                    a[j] = a[j-k];
				else break;
            }
            a[j] = C;
        }

}
void sifting ( int *a, int n, int i)
{
	int j=2*i+1;
	int x=a[i];
	int f=1;
	while (j<n && f)
	{
		if (j+1>=n)
		{
			if (a[j]>x)
			{
				a[i]=a[j];
				i=j;
				j=2*i+1;
			}
			else f=0;
		}
		else 
		{ 
			if (a[j+1]>a[j])
			{
				j=j+1;
			}
			if (a[j]>x)
			{
				a[i]=a[j];
				i=j;
				j=2*i+1;
			}
			else f=0;
		}
	}
	a[i]=x;
}
void pyramidalSort (int *a, int n)
{
	int i, k;
	for ( i = n/2-1; i>=0; i--)
	{
		sifting (a,n,i);
	}
	for ( i = n-1; i>=1; i--)
	{
		k=a[i];
		a[i]=a[0];
		a[0]=k;
		sifting (a,i-1,0);
	}

}
void hoare3 (int *a, int left, int right)
{
	if (left<right)
	{
		int i=left, j=right;
		int x=a[(i+j)/2];
		while (i<=j)
		{
			while (a[i]<x) i++;
			while (a[j]>x) j--;
			if (i<=j) 
			{
				swap (a[i], a[j]);
				i++;
				j--;
			}
		}
		hoare3 (a, left, j);
		hoare3 (a, i, right);
	}
}
void main ()
{
	int *a,n,i;
	cin >>n;
	a=new int [n];
	srand(time(NULL));
	for (i=0; i<n; i++)
	{
		a[i]=rand()%1000;
		
	}

		cout << endl;
			for (i=0; i<n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	hoare3 (a, 0, n-1);
	for (i=0; i<n; i++)
	{
		cout << a[i] << " ";
	}
}

	