#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int b = 2;
	double c = 5.0;
	double d = 2;
	bool p;

	cout << "a / b = " << a / b << endl; // tutaj dzielenie calkowite (typy int)
	cout << "c / d = " << c / d << endl; // tutaj dzielenie rzeczywiste (typy double)
	cout << "a / d = " << a / d << endl; // promocja typu int na "wyzszy" double (uzgodnienie typow)
	cout << "a % b = " << a % b << endl; // dzielenie modulo

	p = (a == b);
	if (!p)
	{
		cout << "!p = " << !p << endl; // false traktowany jako 0, a true jako 1
	}

	p = (a != b);
	if (p)
	{
		cout << "p = " << p << endl; // false traktowany jako 0, a true jako 1
	}
	
	system("pause");
	return(0);
}