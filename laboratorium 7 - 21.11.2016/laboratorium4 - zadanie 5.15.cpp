#include<iostream>
using namespace std;

 // Zadanie 5.15

int main()
{
	

	bool czy_znaleziona = false;
	int x;
	int n;
	cout << "Podaj rozmiar tablicy:" << endl;
	cin >> n;
	if (n <= 0) {
		cout << "Bledne dane." << endl;
		system("pause");
		return 1;
	}
		
	int *tablica = new int[n];
	cout << "Wypisz " << n <<" elementow tablicy:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> tablica[i];
		if (i > 0 && tablica[i] < tablica[i - 1])
		{
			cout << "Bledne dane." << endl;
			system("pause");
			return 1;
		}
	}
	cout << "Podaj liczbe, ktorej szukasz:" << endl;
	cin >> x;
	int poczatkowy_kraniec = 0, koncowy_kraniec = n;
	int srodek;
	while (poczatkowy_kraniec <= koncowy_kraniec)
	{
		srodek = (poczatkowy_kraniec + koncowy_kraniec) / 2;
		if (x == tablica[srodek])
		{
			cout << "X znajduje sie w tablicy na miejscu o indeksie " << srodek << "." << endl;
			czy_znaleziona = true;
			break;
		}
		else if (x < tablica[srodek])
		{
			koncowy_kraniec = srodek - 1;
		}
		else
		{
			poczatkowy_kraniec = srodek + 1;
		}
	}
	if (!czy_znaleziona)
	{
		cout << "Nie znaleziono szukanej liczby." << endl;
	}
	system("pause");
	return 0;
}