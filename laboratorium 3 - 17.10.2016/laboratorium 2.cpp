#include <iostream>;
using namespace std;

int main()
{
	//Zadanie - zagnie¿d¿one pêtle

	int liczba_pilkarzy, liczba_karnych, liczba_strzelonych_przez_jednego = 0;
	int liczba_strzelonych_przez_wszystkich = 0;
	double szansa_strzelenia;
	bool czy_strzelili_cztery_karne = false;

	cout << "Podaj liczbe pilkarzy:" << endl;
	cin >> liczba_pilkarzy;
	cout << "Podaj liczbe rzutow karnych:" << endl;
	cin >> liczba_karnych;

	srand(11);
	
	for (int i = 0; i < liczba_pilkarzy && !czy_strzelili_cztery_karne; i++)
	{
		for (int j = 0; j < liczba_karnych && !czy_strzelili_cztery_karne; j++)
		{
			szansa_strzelenia = (double)rand() / RAND_MAX;

			if (szansa_strzelenia >= 0.7)
			{
				cout << "Zawodnik nr " << i + 1 << " strzelil rzut karny nr " << j + 1 << "!" << endl;
				liczba_strzelonych_przez_jednego++;
				liczba_strzelonych_przez_wszystkich++;
			}
			if (liczba_strzelonych_przez_wszystkich == 4)
			{
				czy_strzelili_cztery_karne = true;
				cout << "Zostaly wykorzystane 4 karne! Fajrant!" << endl;
			}

			if (liczba_strzelonych_przez_jednego == 2)
			{
				liczba_strzelonych_przez_jednego = 0;
				break;
			}
		}
	
	}


	/*
	//Zadanie 3 - przygotowawcze 2

	int liczba;
	int suma = 0;
	int ile_liczb = 0;

	cin >> liczba;
	while (liczba >= 0)
	{
		suma += liczba;
		ile_liczb += 1;
		cin >> liczba;
	}
	if (ile_liczb == 0)
		cout << "Nie ma liczb nieujemnych." << endl;
	else
		cout << "Srednia arytmetyczna liczb nieujemnych wynosi: " << suma / ile_liczb	<< endl;*/


	/*//Zadanie 2 - przygotowawcze 2
	int liczba;
	int suma = 0;

	cin >> liczba;
	while (liczba >= 0)
	{
		suma += liczba;
		cin >> liczba;
	}
	cout << "Suma liczb nieujemnych wynosi: " << suma << endl;*/

	system("pause");
	return (0);
}