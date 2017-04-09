#include <fstream>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <string.h>

#include "functions.h"

using namespace std;

fstream **f, *ffile, source_file;
int n, number_sf, *a, *d, L, j, tmp, newd; //n - number of files, number_sf - amount of numbers in source file

char **names, *name;

void main () {
	char error[20] = "Error of open files";
	cout << "Enter number of files: ";
	cin >> n;
	//Create an array of names
	
	names = new char *[n];
	for ( int i = 0; i < n; i++)
	{
		names[i] = new char[8];
		strcpy(names[i],"f ");
		char c='0'+(i);
		names[i][1]=c;
		strcat( names[i],".txt\0" );
	}
	
	//Create an array of files
	f=new fstream*[n];
	for( int i=0; i<n; i++) {
		f[i] = new fstream ( names[i],ios::out );
	}
	//Create the source file
	cout << "Enter amount of numbers in source file: ";
	cin >> number_sf;
	fstream source_file;
	source_file.open("sourcef.txt", ios::out);
	srand(time(0));
	int num[17]={5, 12, 4, 3,7,8,5,9,6,3,15,18,20,10,11,1,2};
	for ( int i = 0; i < number_sf; i++ ) {
	
		source_file << num[i] << " ";
	}
	source_file.close();
	//Reading from source file
	int x, y;
	source_file.open( "sourcef.txt", ios::in );
	if (!source_file) {
		cout << error << endl;
		return;
	}
	source_file >> x >> y;
	while ( source_file ) {
		if ( x <= y ) {
			*f[n-1] << x << " ";
			x = y;
			source_file >> y;
		}
		else {
			*f[n-1] << x << " " << "-1" << " ";
			x = y;
			source_file >> y;
		}
	}
	*f[n-1] << x << " " << "-1" << " ";
	f[n-1]->close();
	source_file.close();
	//Phase of split
	
	f[n-1]->open(names[n-1], ios::in);
	a=new int[n];
	d=new int[n];
	for(int i=0;i<n-1;i++) {
		a[i]=1;
		d[i]=1;
	}
	d[n-1]=0;
	a[n-1]=0;
	int L=1,j=0;
	*f[n-1] >> x;
	while ( *f[n-1] ) {
		while ( x != -1 )
		{
			*f[j] << x <<" ";
			*f[n-1] >> x;
		}
		*f[j] << x << " ";
		d[j]--;
		if ( ( *f[n-1] >> x ) == NULL ) break;
		else {
			if(d[j]<d[j+1]) j++;
			else if(d[j]==0) {	
				L++;
				tmp=a[0];
				for ( int i = 0; i < n-1; i++ ) {
					d[i] = a[i+1] - a[i] + tmp;
					a[i] = a[i+1] + tmp;
				}
				j=0;
			}
			else j=0;
		}
	}			
	for( int i = 0; i < n; i++ ) {
		f[i] -> close();
	}
	f[n-1] -> clear();
	//Phase of merger
	
	int min, prev;
	ffile = new fstream;
	for ( int i = 0; i < n-1; i++ ) {
		f[i] -> open (names[i], ios::in);
	}
	f[n-1] -> open (names[n-1], ios::out);
	while ( L > 0 ) 
	{
		while ( check_0 (d, n-1) ) {
				for ( int j = 0; j < n-1; j++) 
				{
					d[j]--;
				}
				d[n-1]++;
			}
		while ( true ) {
			
	
			if(d[n-2])
			{
				a[n-2] = -1;
				d[n-2]--;
			}
			else {
				*f[n-2] >> x ;
				if( f[n-2] -> eof()) break;
				a[n-2] = x;
			}
			for ( int i = 0; i < n-2; i++)
			{
					if ( d[i] ) {
						a[i]=-1;
						d[i]--;
					}
					else {
						*f[i] >> a[i];
					}
			}
			 while ( !check_minus_1 (a,n-1) ) {
					min = find_minArr ( a, n-1 );
					*f[n-1] << a[min] << " ";
					*f[min] >> a[min];
					if( f[n-2] -> eof()) break;
			 }
			
		}	
			 getch();
			L--;
			f[n-1]->close();
			f[n-2]->close();
			f[n-1]->clear();
			f[n-2]->clear();
			f[n-1]->open(names[n-1],ios::in);
			f[n-2]->open(names[n-2],ios::out);
			ffile=f[n-1];
			name=names[n-1];
			newd=d[n-1];
			for( int i = n-1; i > 0; i--)
			{
				f[i] = f[i-1];
				names[i] = names[i-1];
				d[i] = d[i-1];
			}
			f[0]=ffile;
			names[0]=name;
			d[0]=newd;
	}	
	for ( int i = 0; i < n ; i++ )
	f[i]->close();
}