#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <iostream>
using namespace std;
class Person  { 
	  friend class Faculty;
      protected:
      char *fio, *adr; int g_r;
      public:
    Person() // КОНСТРУКТОР ПО УМОЛЧАНИЮ
     { 
		fio = new char[1]; 
		adr = new char[1];
		fio[0] = 0; 
		adr[0] = 0;
		g_r = 0;
     }
	Person(char *f, char *a, int gr)
	{ 
		fio = new char[ strlen(f) +1 ];
		strcpy(fio, f);
		adr = new char[ strlen(a) + 1];
		strcpy(adr, a);
		g_r = gr;
    }
	~Person()
	{
		delete [] fio;
		delete [] adr;
	}
	Person( Person &p ) 
	{ 
		fio = new char[ strlen(p.fio) + 1];
		adr = new char[ strlen(p.adr) + 1];
		strcpy(fio, p.fio);
	    strcpy(adr, p.adr);
		g_r = p.g_r;
	}
	Person & operator = (Person &p)
	{
		if (this != &p)
		{
		delete [] fio;
		delete [] adr;
		fio=new char [strlen(p.fio) + 1];
		adr=new char [strlen(p.adr) + 1];
		strcpy (fio, p.fio);
		strcpy (adr, p.adr);
		g_r=p.g_r;
		}
		return *this;
	}
	virtual void ln ()
	{
		char _fio[80], _adr[80];
		int _g_r;
		cout << "Enter FIO: " << endl;
		gets (_fio);
		cout << "Enter adres: " << endl;
		gets (_adr);
		cout << "Enter number of group: " << endl;
		cin >> _g_r;
		Person _new (_fio, _adr, _g_r);
		*this=_new;
	}
	virtual void Show ()
	{
		cout<<"\n Фио: "<<fio;
		cout<<"   Адрес: "<<adr;
		cout<< " Год рождения: "<<g_r;
    }
};
class Student : public Person 
{
	friend class Faculty;
	protected:
	int grup, kurs; char *spec;
	public:
	Student()                // конструктор по умолч.
	{ 
		grup = kurs = 0;
		spec = new char[1];
		spec[0] = 0;
	}
	Student(char *f, char *adr, int g, int gr, int kr, char *sp): Person(f, adr, g)
    { 
		grup=gr;
		kurs=kr;
		spec = new char[ strlen(sp) + 1];
		strcpy(spec, sp);
	}
	Student( Student &s): Person(s) 
    { 
		kurs = s.kurs;
	   grup = s.grup;
	   spec = new char[ strlen(s.spec) + 1];
	   strcpy(spec, s.spec);
	}
	~Student()
	{ 
		delete []spec;
	}
	Student & operator = (Student &s)
	{ 
		if( this != &s)
	    { 
			Person :: operator = (s);
			delete [] spec;  
			spec = new char [ strlen(s.spec) + 1];
			strcpy(spec, s.spec);
			grup = s.grup;    
			kurs = s.kurs;
	    }
		return *this;
	 }
	virtual void ln()
	{
		cout<<"\nВвод данных о студенте";
		Person :: ln();      
		char buf[80];    // fflush(stdin);
		cout<<"\n Специальность: "; 
		gets(buf);
		delete []spec; 
		spec = new char[ strlen(buf) + 1];
		strcpy(spec, buf);
		cout<<"\nкурс:"; 
		cin>>kurs;
		cout<<"\nгруппа: "; 
		cin>>grup;
	 }
	friend istream & operator >>( istream &r, Student &s)
	{ 
		s.ln();  
		return r; 
	}
	virtual void Show()
	{ 
		Person :: Show();
		cout<<"\n курс - "<<kurs<<" группа - "<<grup;
		cout<<" специальность - "<<spec;
	}
	int Get_g()
    { return grup; } 
    int Get_k()
    { return kurs; }
  }; 

class Teacher : public Person
    { 
		friend class Faculty;
        char *kafedra, *prof;
        public:
		Teacher ()
		{
			kafedra=new char [1];
			prof=new char [1];
			kafedra[0]=0;
			prof[0]=0;
		}
		Teacher (char *f, char *a, int _g_r, char *kaf, char *pr): Person (f, a, _g_r)
		{  
			kafedra=new char [strlen(kaf)+1];
			prof=new char [strlen(pr)+1];
			strcpy(kafedra, kaf);
			strcpy (prof, pr);
		}
		Teacher (Teacher & t): Person (t)
		{
			kafedra=new char [strlen(kaf)+1];
			prof=new char [strlen(pr)+1];
			strcpy(kafedra, kaf);
			strcpy (prof, pr);
		}






void main ()
{
}
