#include <iostream>
using namespace std;

// Zadanie przygotowawcze 2015 3A

void wypiszTablice(int* t, int n)
{
	for (int i = 0; i<n; i++)
		cout << t[i] << " ";
	cout << endl;
}

int najwiekszaUjemna(int* tablica, int n) {
	int najUjemna = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (tablica[i] > najUjemna && tablica[i] < 0) 
			najUjemna = tablica[i];
	}
	if (najUjemna == INT_MIN) 
		najUjemna = 0;
	return najUjemna;
}

void podniesienie(int* tablica, int n) {
	int najUjemna = -1 * najwiekszaUjemna(tablica, n);
	for (int i = 0; i < n; i++) 
		tablica[i] += najUjemna;
}

int dlugiePodnoszenie(int* tablica, int n) {
	int licznik = 0;
	for (int i = 0; i < n; i++) {
		if (najwiekszaUjemna(tablica, n) < 0) {
			podniesienie(tablica, n);
			licznik++;
		}
	}
	return licznik;
}

int main() {
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
		cin >> tablica[i];
	int pom = najwiekszaUjemna(tablica, n);
	cout << "Wypisana tablica:" << endl;
	wypiszTablice(tablica, n);
	cout << "Najwieksza ujemna liczba w tablicy to " << pom << "." << endl;
	cout << "Po jednokrotnym wykonaniu operacji podniesienia nasza tablica bedzie wygladala tak: " << endl;
	podniesienie(tablica, n);
	wypiszTablice(tablica, n);
	cout << "Po wszystkich mozliwych podniesieniach otrzymamy: " << endl;
	int ileRazy = dlugiePodnoszenie(tablica, n);
	wypiszTablice(tablica, n);
	cout << "do czego potrzebujemy " << ileRazy << " podniesien." << endl;

	system("pause");
	return 0;
}