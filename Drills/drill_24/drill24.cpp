#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
//egy int valtozo, ami egy hibaszamot tartalmaz
#include <cerrno>
//matrix headerfile-jai
#include "headers/Matrix.h"
#include "headers/MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try {
	
	//adattipusok meretei
	
	cout << "sizeof:\n" ;
	cout << "char\t" << sizeof(char) << '\n';
	cout << "short\t" << sizeof(short) << '\n';
	cout << "int\t" << sizeof(int) << '\n';
	cout << "long\t" << sizeof(long) << '\n';
	cout << "float\t" << sizeof(float) << '\n';
	cout << "double\t" << sizeof(double) << '\n';
	cout << "int*\t" << sizeof(int*) << '\n';
	cout << "double*\t" << sizeof(double*) << '\n';
	
	//matrix meretei
	
	cout << "Matrix sizes:\n";
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);
	cout << "1D int, 10 elem\t\t" << sizeof(a) << '\n';
	cout << "1D int, 100 elem\t\t" << sizeof(b) << '\n';
	cout << "1D double, 10 elem\t\t" << sizeof(c) << '\n';
	cout << "2D int, 10x10 elem\t\t" << sizeof(d) << '\n';
	cout << "3D int 10x10x10 elem\t\t" << sizeof(e) << '\n';
	
	cout << "Number of elements:\n";
	cout << "a: " << a.size() << '\n';
	cout << "b: " << b.size() << '\n';
	cout << "c: " << c.size() << '\n';
	cout << "d: " << d.size() << '\n';
	cout << "e: " << e.size() << '\n';
	
	//matrix adatfeldolgozas
	
	int i;
	cout << "\nEnter ints: ";
	while(cin >> i)
	{
		errno = 0;
		double d = sqrt(i);
		if(errno == EDOM) cout << "no square root\n";
		else cout << "sqrt(" << i << ") = "<< d << '\n';
	}
	
	
	cin.clear();
	cin.ignore();
	
	/*cout << "\nEnter 10 floats: ";
	Matrix<double> m(10);
	double d2;
	for(int i=0; i<m.size(); i++)
	{
		cin >> d2;
		if(!cin) throw runtime_error("Error while reading from cin!");
		m[i] = d2;
	}
	
	cout << "Matrix: \n" << m << '\n';*/
	
	//szorzotable keszites
	
	int n1, n2;
	cout << "\nEnter the size of multiplication table:";
	cin >> n1 >> n2;
	Matrix<int, 2> m2(n1, n2);
	/*for(int i=0; i<n1; i++)
	{
		for(int j=0; j<n2; j++)
		{
			m2[i][j]=(i+1)*(j+1);
			cout << setw(5) << m2[i][j];
		}
		cout << '\n';
	}*/
	
	for(Index i=0; i < m2.dim1(); i++)
	{
		for(Index j=0; j < m2.dim2(); j++)
		{
			m2(i, j) = (i+1)*(j+1);
			cout << setw(5) << m2(i, j);
		}
		cout << '\n';
	}
	
	Matrix<complex<double>> m4(10);
	cout << "\nEnter 10 complex values (re,im):";
	complex<double> comp;
	for(int i=0; i < 10; i++)
	{
		cin >> comp;
		if(!cin) throw runtime_error("Problem reading complex numbers");
		m4[i] = comp;
	}
	complex<double> sum;
	for(Index i=0; i < m4.dim1(); i++)
	{
		sum += m4[i];
	}
	cout << "sum: " << sum << '\n';
	
	//cout << m2 <<'\n';
	
	//8. feladat
	
	Matrix<int, 2> m(2,3);
	cout << "Enter 6 values:";
	for(Index i=0; i<m.dim1(); i++)
	{
		for(Index j=0; j<m.dim2(); j++)
		{
			cin >> m(i, j);
		}
	}
	for(Index i=0; i<m.dim1(); i++)
	{
		for(Index j=0; j<m.dim2(); j++)
		{
			cout << m(i, j) << '\t';
		}
		cout << '\n';
	}

} catch(exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "unknown\n";
	return 2;
}
