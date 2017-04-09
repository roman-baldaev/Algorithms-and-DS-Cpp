#include "BV.h"
#define  UC  unsigned  char
using namespace std;
class BM 
{
	BV  *bm; 
	int  line;
	int column;

	public:

 BM(int _line=1, int _column=1);
 
 BM(BM&);
 ~BM() {delete []bm;}

 BM operator =(BM);
 void copy (BV *, int );


 void  Set_0 (int, int);
 void  Set_1 (int, int);
BV& operator[](int );
void operator|=(BM&);
BM operator|(BM& x);
void operator&=(BM&);
BM operator&(BM&);
BM operator ^(BM& );
void operator ^= (BM&);
void operator~();
BV Konj();
BV Disj();
int WeightOfCol(int);
int WeightBM();
void Input(int, int);
void Output();
};

BM:: BM(int _line, int _column)
{
	line=_line; 
	column = _column;
	bm=new BV [line];

  BV  v(column);
  for(int i=0; i<line; i++)  bm[i]=v;
}
BM:: BM(BM& x)
{
	line = x.line; 
	column = x.column;
  bm=new BV [line];
  for(int i=0; i<line; i++)  bm[i]= x.bm[i];
}
 BM BM:: operator =(BM x)
 {
	 line = x.line; 
	column = x.column;
	delete []bm;
	bm = new BV [line];
	copy (x.bm, line); 
	return *this;
 }
 void BM:: Input(int _line, int _column)
 {
	 line=_line;
	 column = _column;
	 bm = new BV[line];
	 int i;
	 for(i = 0; i < line; i++)
		 bm[i].Input();
 }
 void BM:: Output()
 {
	 for(int i = 0; i < line; i++)
	{	 bm[i].Output();
	 cout << endl;
	 }
 }
 void BM:: copy (BV *_bm, int _line)  
{       
	int i; 
	for(i = 0; i < _line; i++) 
		bm[i]=_bm[i]; 
}

inline void BM:: Set_0(int _line, int _column)
{	int line_ = _line--;
	bm[_line].Set_0(_column);}
inline void BM:: Set_1(int _line, int _column)
{	int line_ = _line--;
	bm[_line].Set_1(_column);}
inline BV& BM:: operator[](int _line)
{if (0<=_line && _line<line) 
    return bm[_line];
throw "error []";}
BV BM:: Konj() //умножение
{BV v(bm[0]); 
 for(int i=1; i<line; i++) v&=bm[i];
 return v;
}
BV BM:: Disj() //'+'
{BV v(bm[0]); 
 for(int i=1; i<line; i++) v|=bm[i];
 return v;
}
void BM:: operator|=(BM& x)
{
	if  (x.line != line) throw "error |=";
for(int i=0; i<line; i++) bm[i]|=x.bm[i];
if (column < x.column) column=x.column;
}
BM BM:: operator|(BM& x)
{ 
	BM help(line, column);	
	
	if  (x.line != line) throw "error |=";
for(int i=0; i<line; i++) help.bm[i]=bm[i]|x.bm[i];
if (column > x.column) help.column=x.column;
return help;
}
void BM:: operator&= (BM& x)
{

		if  (x.line != line) throw "error |=";
	
	
for(int i=0; i<line; i++) bm[i]&=x.bm[i];
if (column < x.column) column=x.column;
}
BM BM:: operator& (BM& x)
{
	BM help(line, column);

	if  (x.line != line) throw "error |=";
for(int i=0; i<line; i++) help.bm[i]=bm[i]&x.bm[i];
if (column > x.column) column=x.column;
return help;
}
BM BM:: operator ^(BM& x)
{
	BM help(line, column);

	if  (x.line != line) throw "error |=";
for(int i=0; i<line; i++) help.bm[i]=bm[i]^x.bm[i];
if (column < x.column) column=x.column;
return help;
}
void BM:: operator ^= (BM& x)
{

	if  (x.line != line) throw "error |=";
for(int i=0; i<line; i++) bm[i]^=x.bm[i];
if (column < x.column) column=x.column;

}
int BM:: WeightOfCol(int number)
{
	int counter = 0;
	int col = column - number;
	for( int i = 0; i < line; i++)
	if(bm[i][col] == 1) counter++;
	return counter;}
int BM:: WeightBM()
{
	int counter_bv = 0;
	int counter = 0;
	 for( int i = 0; i < line; i++)
	 { counter_bv = bm[i].Weght();
	 counter += counter_bv;}
	 return counter;
}

