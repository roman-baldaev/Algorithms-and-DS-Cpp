#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include <time.h>
#include "Array.h"
#include <string>
using namespace std;

void main ()
{
	Array <char> h;
	Array <char> mass(5);
	Array <char> job;
	mass.Enter();
	cout << "Enter element for find: " << endl;
	char a;
	cin >> a;
	cout << mass.findElement(a) << endl;
	cout << "Enter element for delete: " << endl;
	char b;
	cin >> b;
	mass=mass-b;
	mass.Print();
	cout << "Enter element and index for add:";
	char c;
	int c1;
	cin >> c >> c1;
	mass.addToPosition (c, c1);
	mass.Print();
	cout << "Enter position of element for delete: " << endl;
	int l;
	cin >> l;
	mass.deleteToPosition(l);
	mass.Print();
	h=mass;
	h=h>>2;
	
	h.Print();
	job=h+mass;
	job.Print();
	
	
	
	
}