#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main ()
{
	int a,b,c,max, min;
	scanf ("%d", &a);
	scanf ("%d", &b);
	scanf ("%d", &c);
	__asm 
	{
		MOV eax, a
		CMP eax, b
		jge F1
		MOV eax, b
		MOV ebx, a
F1: MOV ebx, b
	}
	__asm
	{
		CMP eax, c
		jl F2
		F2: MOV eax, c
	}	
	__asm		
	{	
	CMP c, ebx
		jl F3
F3: MOV ebx, c
	}
	__asm
	{
		MOV max, eax
		MOV min, ebx
	}
	printf ("%d", max);
	printf ("%d", min);
	getch ();
}