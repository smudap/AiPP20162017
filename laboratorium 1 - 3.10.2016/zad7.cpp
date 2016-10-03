#include <iostream>
using namespace std;

int main()
{
	double waga;
	int wypity_alkohol;
	int plec;
	double wspolczynnik_dla_plci;
	double promile_we_krwi;

	cout << "Podaj swoja wage w kg:" << endl;
	cin >> waga;
	cout << "Podaj ilosc wypitego czystego alkoholu w gramach:" << endl;
	cin >> wypity_alkohol;
	cout << "Podaj swoja plec (kobieta - 1, mezczyzna - 0):" << endl;
	cin >> plec;

	if (plec == 0)
	{
		wspolczynnik_dla_plci = 0.7;
	}
	else 
	{ 
		wspolczynnik_dla_plci = 0.6;
	}

	promile_we_krwi = wypity_alkohol / (waga * wspolczynnik_dla_plci);
	cout << "Masz " << promile_we_krwi << " promila. ";
	
	if (promile_we_krwi <= 0.2)
	{
		cout << "Jestes trzezwy!" << endl;
	} 
	else if (promile_we_krwi > 0.2 && promile_we_krwi < 5)
	{
		cout << "Jestes niezdolny do prowadzenia pojazdow mechanicznych!" << endl;
	}
	else
	{
		cout << "Jestes w stanie zagrozenia zycia!" << endl;
	}

	system("pause");
	return(0);
}