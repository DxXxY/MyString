#include "MyString.h"
#include <iostream>
#include "binary_str.h"

using namespace std;
int main()
{
	setlocale(0, "ru");
	MyString p;
	MyString p1;
	binary_str p2="01010";
	binary_str p21 = p2;
	p2 = "01111";
	cin >> p;
	p1 = "Hello, Im ";
	cout << (p1 + p);
	cout << endl << p21<<endl;
	cout << (p1 == p) << (p1 != p);
	p1 += p;
	cout << endl<<p2+p21;

}