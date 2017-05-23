// Дан массив целых чисел, в котором есть группа из пяти рядом стоящих элементов,
// сумма которых равна целому К. Обнулить эту группу.

#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

/* int findIndexOfBeginGroup ( int * a, int n ) { //функция поиска индекса первого элемента этой группы
	int i = -1;
	_asm {
		
		mov ebx, 0
		xor eax, eax
		mov ecx, 5
		L: add eax, a[ebx]
		add ebx, type a
		dec ecx
		loop L
		mov i, eax
	}
	return i;

}
*/
 int get(int *arr, unsigned int index) {
     int*  p      = arr;
     int   num = 0;
    __asm {
                    mov esi, p
           mov edx, dword ptr index
           mov ebx,  [esi+edx*4]
           mov dword ptr num, ebx
    };
    return  num;
 }
  int summOfFive ( int * arr, unsigned int n, int K ) {
     int *  p      = arr;
	 int i=-1;
     int   num = 0;
    __asm {
           mov ecx, 5
		   xor eax, eax
		   mov edi,  dword ptr K
		   
			L: mov esi, p
           mov ebx, [esi+eax*4]
           add dword ptr num, ebx
		   inc eax
			loop L
			cmp edi, num
			je FIN2
			sub n, 5
			mov ecx, n
			mov edx, 0
			F: mov esi, p 
		   mov ebx,  [esi+eax*4] 
			add dword ptr num, ebx
			mov ebx,  [esi+edx*4]
			sub dword ptr num, ebx
			inc eax
			inc edx
			cmp edi, num
			je FIN
			loop F
			FIN: mov i, edx
			jmp ENDD
			FIN2: mov i, 0
			ENDD: xor ecx, ecx
    };
    return  i;
 }
  void Set_0 (int * arr, unsigned int index) {
    int*  p   = arr;
    __asm {
             mov esi, p
			 mov ecx, 5
			mov edx, dword ptr index             
			SET: mov [esi+edx*4], 0
			 inc edx
			 loop SET
    };
      }
void main () {
	  int *a, K, i;
	  unsigned int n;
	cout << "Enter number of elements: ";
	cin >> n;
	a = new  int [ n ];
	cout << endl;
	srand ( time ( NULL ) );
	for ( int i = 0; i < n; i++ ) {
		a[i] = rand() % 10 + 1;
	}
	cout << endl;
	for ( int i = 0; i < n; i++ ) {
		 cout << a[i] << " ";
	}
	cout << endl;
	cin >> K;
	
	Set_0 ( a, summOfFive (a, n, K));
	cout << endl;
	for ( int i = 0; i < n; i++ ) {
		 cout << a[i] << " ";
	}
/*	_asm {
		
		lea esi, a
		xor eax, eax
		mov ecx, 5
		mov edx, 0
		mov ebx, 0
		L: add eax, a[ebx]
			add ebx, type a
			dec ecx
		cmp ecx, 0
		jne L
		mov i, eax
	}
	cout << "Summ: " << i; 
	getch ();
*/
}