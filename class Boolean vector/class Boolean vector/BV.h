#define  UC  unsigned  char
using namespace std;

class BV
{
	UC  *bv;
	int bit; 
	int byte;

void print(int, int );
int scan(char*, int, int, int);



public:

	BV(int _bit=0, int _byte=1);
	BV(char*);
	BV(char*, int _bit);
	~BV() {delete []bv;}
	BV(BV&);
	BV operator =(BV);


	BV operator &(BV&);
	BV operator |(BV& );
	BV operator ^(BV& );
	BV operator &=(BV&);
	BV operator |=(BV&);
	BV operator ^=(BV&);
	int operator [](int);
	void operator~ ();

	BV operator <<(int);
	void operator <<=(int);
	BV operator >>(int);
	void operator >>=(int);

	int Weght();


	void Set_1(int, int);
	void Set_1(int);
	void Set_0(int, int);
	void Set_0(int);
		void copy(UC *, int);
	void Input();
	void Output();

 };

int BV:: Weght()
{
	int counter = 0;
	int i;

	for ( i = bit - 1; i >= 0; i--)
		if(operator[](i)) counter++;
	return counter; 
}
BV:: BV(BV &x)  
{
	bit=x.bit;
	byte=x.byte; 
	bv = new UC[byte];
    copy (x.bv, byte);
}
void BV:: copy (UC *_bv, int _byte)  
{       
	int i; 
	for(i = 0; i < _byte; i++) 
		bv[i]=_bv[i]; 
}
BV:: BV(int _bit, int _byte)
 {
	 bit=_bit;
	 byte=_byte;
	 bv = new UC[byte]; 
     for(int i=0; i < byte; i++)
		bv[i] = 0;
 }
void BV:: print(int i, int nbit)
{
	UC mask=1;
 for(mask <<= nbit-1; mask; mask>>=1)
 if (bv[i] & mask) cout << '1';   // & - '*' 
 else  cout << '0';
}
void BV:: Output()
{
 int  i;
 int residue = bit%8;
	print(0, residue);
	for(i=1; i < byte; i++) print(i, 8);
}
void BV:: Input() 
{
	char line[100];
 char *s; 

scanf("%s", &line); 
bit = strlen(line); 
s = new char[bit]; 
strcpy(s, line); 
byte = bit/8; 
int i;
int k = bit%8;
int is = 0; 
if (k) byte++; 
bv = new UC[byte];
if(k) { 
is=scan(s,0,k,is); 
for(i=1; i<byte; i++) 
is = scan(s,i,8,is);} 
else {for(i=0; i<byte; i++) 
is=scan(s,i,8,is);} 
};
BV BV:: operator= (BV x)
{
	bit=x.bit;
	byte=x.byte;
	delete []bv;
	bv = new UC[byte];
	copy (x.bv, byte);
	return *this;
}
BV:: BV (char* s)
{
 bit=strlen(s);
 byte = bit/8; 
 int i;
 int residue = bit%8;
 int is = 0;

	if (residue) byte++;
	 bv=new UC [byte];
	is=scan(s, 0, residue, is);
	for(i=1; i<byte; i++) 
		is = scan(s, i, 8, is);
}
int BV:: scan(char* s, int i, int nbit, int is)//i Цномер элемента в массиве байт,
											   //nbit Ц количество вводимых бит 
											   //// is Ц индекс строки
{
UC mask = 1;
int ibit = 0;

	 for(bv[i] = 0; ibit<nbit; ibit++, is++)
  {
	  bv[i] <<= 1; 
	 if (s[is] == '1') bv[i] |= mask;
  }

return is;
}
BV BV:: operator &(BV& x)
{
int min=bit; 
int i;
int ix;
int ires;

 if (min > x.bit) min = x.bit;
 BV result(min);
for (i = byte-1, ix = x.byte-1, ires = result.byte-1; 
   ires>=0; i--, ix--, ires--) 
   result.bv[ires] = bv[i] & x.bv[ix];
 return result;
}
BV BV:: operator|(BV & x)
{
int max = bit; 
int i;
int ix;
int ires;

 if (max < x.bit) max = x.bit;
 BV result(max);
for (i = byte-1, ix = x.byte-1, ires = result.byte-1; 
   ires >= 0; i--, ix--, ires--) 
   result.bv[ires] = bv[i] | x.bv[ix];
 return result;
}
BV BV:: operator ^(BV& x)
{
int min = bit; 
int i;
int ix;
int ires;

 if (min > x.bit) min = x.bit;
 BV result(min);
for (i = byte-1, ix = x.byte-1, ires = result.byte-1; 
   ires >= 0; i--, ix--, ires--) 
   result.bv[ires] = bv[i] ^ x.bv[ix];
 return result;
}
BV BV:: operator &=(BV& x)
{
int min=bit;
	int i;
	int ix;
	int ires;
	int _byte; 
 if (min>x.bit) min=x.bit;
	_byte=min/8; 
	if (min%8) _byte++;

UC *_bv=new UC [_byte]; 
for (i=byte-1, ix=x.byte-1, ires=_byte-1; 
   ires >= 0; i--, ix--, ires--) 
   _bv[ires] = bv[i] & x.bv[ix];
	delete []bv; 
		byte=_byte; 
		bv=_bv; 
		bit=min;
 return *this;
}
BV BV:: operator |=(BV& x)
{
int max = bit;
	int i = 0;
	int ix = 0;
	int ires = 0;
	int _byte = 0; 
 if (max < x.bit) max = x.bit;
	_byte = max/8; 
	if (max%8) _byte++;

UC *_bv=new UC [_byte]; 
for ( i = byte-1, ix = x.byte-1, ires = _byte-1; 
   ires >= 0; i--, ix--, ires--) 
   _bv[ires] = bv[i] | x.bv[ix];
	delete []bv; 
		byte=_byte; 
		bv=_bv; 
		bit = max;
 return *this;
}
BV BV:: operator ^=(BV& x)
{
	int max = bit;
	int min = 0;
	int i;
	int ix;
	int ires;
	int _byte;
 if (max < x.bit) max = x.bit;
	_byte = max/8; 
	if ( max%8 ) _byte++;
	if ( max == bit) min = x.bit;
	else min = bit;

UC *_bv = new UC [_byte]; 
for (i = byte-1, ix = x.byte-1, ires=_byte-1; 
   i >= 0 && ix >= 0 ; i--, ix--, ires--) 
   _bv[ires] = bv[i] ^ x.bv[ix];

for (; i >= 0; i--,ires--) 
   _bv[ires] = bv[i];
for (; ix >= 0; ix--,ires--) 
   _bv[ires] = x.bv[ix];


	delete []bv; 
		byte = _byte; 
		bv = _bv; 
		bit = max;
 return *this;
}
void BV:: Set_1(int index)//установка в 1 i-того бита
{
int i = byte-1-index/8;
int _bit = index%8;
 UC mask = 1 << _bit;
  bv[i]|=mask; 
}
void BV:: Set_0(int index)
{
int i = byte-1-index/8;
int _bit = index%8;
 UC mask = 1 << _bit;
	bv[i] &= ~mask;
 
}
void BV:: operator ~()
{
	int i = 0;
bv[i] = ~bv[i];
}
void BV:: Set_1(int index, int number)
{
	int i;
  for(i = index; i < index+number; i++)
      Set_1(i);
} 
void BV:: Set_0(int index, int number)
{
	int i;
  for(i = index; i < index+number; i++)
      Set_0(i);
} 
int BV:: operator [](int  index)
{ 
  int i = byte-1-index/8;
  int _bit=index%8;
  UC mask = 1 << _bit;
  if (bv[i] & mask) return 1;
  return 0; 
}
void BV:: operator <<=(int  number)
{
	int j=bit-1;
	int k;

 for ( k = j - number; k >= 0; k--,j--)
   
   if (operator[](k)) Set_1(j);  
   else  Set_0(j); 
for(; j>=0; j--)  Set_0(j); 
}
BV BV:: operator <<(int  number)
{
	int j=bit-1;
	int k;
	BV x(bit, byte);

 for(k=j-number; k>=0; k--,j--)
   if (operator[](k)) x.Set_1(j);  
   else  x.Set_0(j); 
for(; j>=0; j--)  x.Set_0(j);
return x;
}
void BV::operator >>=(int number)
{ 
		int j;
		for ( j = 0; number < bit; j++, number++)
		if (operator[](number)) Set_1(j);  
		else  Set_0(j); 
		for(; j<bit; j++)  Set_0(j); 
}
BV BV:: operator >>(int  number)
{
	int j = 0;
	int k = number;
	BV x(bit, byte);

	for(j; k < bit; k++,j++)
	if (operator[](k)) x.Set_1(j);  
	else  x.Set_0(j); 
	for(; j<bit; j++)  x.Set_0(j); 
	return x;
}


