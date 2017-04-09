#include <stdlib.h> 
#include <stdio.h> 
#include <conio.h> 
#include <iostream> 
#include <time.h>
#include "nodes.h"
using namespace std;

void main ()
{
	topologicalSort A;
	A.formLeader();
	A.show_descendants(6);
	
}