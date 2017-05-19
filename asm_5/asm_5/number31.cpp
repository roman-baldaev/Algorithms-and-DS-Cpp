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
		mov edx, eax
		mov ecx, n
		L:
			mov eax, cV
			cmp i, 0
				jne L1
		R:	and eax, mask
			imul i, 2
			cmp i, 0
			jne L2
		R1:	add edx, eax
			idiv i, 2
			add i, 1
			mov mask, 1
		loop L
		jmp FIN
		L1: mov ebx, ecx
			ecx, i
			l1: imul mask, 2
			loop l1
			jmp R
		L2: ecx, i
			l1: imul mask, 2
			loop l1
			jmp R1
		FIN: mov Y, edx
	}
	cout << "Vector Y: ";
	for ( i = 2*n; i >= 0; i--) {
		mask = 1 << i;
		
		cout << (bool)(mask & Y);
	}
}
