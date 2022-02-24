#include <iostream>
#include <string>
using namespace std;
//Jegyzetek

//valos vilag elemei objektumok, ezeket mind majd abrazolni.
//az osztaly altalanos fogalom, ezzel definialunk targyakat,
// adunk neki tulajdonsagokat.
//osztalyok tartalmaznak muveleteket, viselkedeseket; ezek
// lesznek a fuggvenyek.
//oroklodes, szulo es gyermekosztalyok.
//polimorfizmus: egy fuggveny tobbfele formatumban is 
// letezhet (class e, print(); class f, print(); print() - e vagy f?).
//a gyermekosztalyok felulirhatjak a szulo tulajdonsagait.
//absztrakt fuggveny: jelentes nelkuli fuggveny, a leszarmazottai
// adnak a fuggvenynek ertelmet.
//absztrakt osztaly: ha van benne absztrakt fuggveny.
//protected: az osztaly es a szarmaztatott osztalyok kozott
// hasznalhato tulajdonsagok
//tisztan virtualis fuggvenyek ures fuggvenyek
//ilyen fuggvenyekkel nem meghivhato az osztaly, absztrakta valik

//Jegyzetek vege

class B1
{
public:
	virtual void vf() { cout << "B1::vf()" << endl; }
	void f() { cout << "B1::f()" << endl; }
	virtual void pvf() = 0; //tisztan virtualis fuggveny
};

class D1 : public B1
{
public:
	void vf() { cout << "D1::vf()" << endl; }
};

class B2
{
public:
	virtual void pvf() = 0;
};

class D2 : public D1
{
public:
	void pvf() { cout << "D2::pvf()" << endl; }
};

class D21 : public B2
{
public:
	string s;
	void pvf() { cout << s << endl; }
};

class D22 : public B2
{
public:
	int n;
	void pvf() { cout << n << endl;}
};

void (B2& bref) 
{
	bref.pvf();
}

int main()
{
	/*B1 b1;
	b1.vf();
	b1.f();
	
	D1 d1;
	d1.vf();
	d1.f();
	
	B1& bref = d1;
	bref.vf();
	bref.f();*/
	
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
	
	D21 d21;
	d21.s = "d21.s";
	d21.pvf();
	
	D22 d22;
	d22.n = 22;
	d22.pvf();
	
	f(d21); f(d22);
}


