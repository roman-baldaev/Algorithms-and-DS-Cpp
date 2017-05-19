#include <iostream>
#include "bv.h"
#include <string>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <climits>

using namespace std;

void main () { 
	int i, n, V = 0, cV, Y = 0, mask = 1 << 31;
	char *s;
	s = new char [32];
	cin >> s;
	n = strlen(s) - 1;
	i = n;
	cout << s << endl;
	while ( i >= 0 ) {
		if ( s[i] == '1' ) {
			V += (int)pow ( 2.0 , n - i );
		}
		else {
			V += 0;
		}
		i--;
	}
	cout << V << endl;
	n = 0;
	while ( (mask & V) == 0 ) {
		mask = mask >> 1;
		n++;
	}
	cout << endl;
	n = 31 - n;
	for ( i = n; i >= 0; i--) {
		mask = 1 << i;
		
		cout << (bool)(mask & V);
	}
	n += 1;
	cout << endl << n << endl;
	cV = V;
	i = 0;
	mask = 1;
	int mask2 = 1;
	_asm {
		NOT cV
		mov eax, cV
		mov edx, 0
		mov ecx, n
		L:
			mov eax, cV
			
			shr mask, 2
			shr mask2, 1
			mov ebx, eax
			and eax, mask
			add edx, eax
			
			add i, 1
		loop L
		
		mov Y, edx
	}
	cout << "Vector Y: ";
	for ( i = 2*n-1; i >= 0; i--) {
		mask = 1 << i;
		
		cout << (bool)(mask & Y);
	}
}
