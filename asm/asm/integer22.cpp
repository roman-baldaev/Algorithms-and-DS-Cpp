#include <iostream>
using namespace std;

void main () {
	int N=0, a=0;
	while ( N < 3600 )
	{
		cout << "Please, repeat enter" << endl;
		cin >> N;
	}
	_asm {
		mov edx,0;
		mov eax, N;
		mov ebx, 3600;
		div ebx;
		mov a, EDX;
	}
	cout << a;
}