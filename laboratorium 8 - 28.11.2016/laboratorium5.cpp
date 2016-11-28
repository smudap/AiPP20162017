#include <iostream>
using namespace std;

// Zadanie 5.4

int wyznaczMode(int* tablica, int rozmiarTablicy) {
	int zliczenia[20] = {};
	int moda = 0;
	int maxi = 0;
	for (int i = 0; i < rozmiarTablicy; i++) {
		zliczenia[tablica[i]]++;
	}
	for (int i = 0; i < 20; i++) {
		if (zliczenia[i] > maxi) {
			maxi = zliczenia[i];
			moda = i;
		}
	}
	return moda;
}

// Zadanie 5.6

void sortowanieKubelkowe(int* tablica, int rozmiarTablicy, int maxWartosc) {
	int* zliczenia = new int[maxWartosc];
	int k = 0;
	for (int i = 0; i < maxWartosc; i++) {
		zliczenia[i] = 0;
	}
	for (int i = 0; i < rozmiarTablicy; i++) {
		zliczenia[tablica[i]-1]++;
	}
	for (int i = 0; i < maxWartosc; i++) {
		for (int j = 0; j < zliczenia[i]; j++) {
			tablica[k++] = i + 1;
		}
	}
	delete[] zliczenia;
}

void wypiszTablice(int* t, int n) {
	for (int i = 0; i<n; i++)
		cout << t[i] << " ";
	cout << endl;
}

// Zadanie Przygotowawcze 2014 4A

int* zwrocKolejnyWiersz(int* tablica, int rozmiarTablicy) {
	int* nowa = new int[rozmiarTablicy + 1];
	nowa[0] = tablica[rozmiarTablicy - 1];
	for (int j = 1; j <= rozmiarTablicy; j++) {
		nowa[j] = nowa[j - 1] + tablica[j - 1];
	}
	return nowa;
}

int* wypiszWybranyWierszTrojkataBella(int pierwszyElement, int wybranyWiersz) {
	int* tablica = new int[wybranyWiersz];
	tablica[0] = pierwszyElement;
	int* pomocnicza = new int[wybranyWiersz];
	for (int i = 1; i < wybranyWiersz; i++)
	{
		pomocnicza = tablica;
		tablica = zwrocKolejnyWiersz(pomocnicza, i);
	}
	delete[] pomocnicza;
	return tablica;
}

// Zadanie 5.17

double wyznaczWariancje(double* tablica, int n) {
	double zwyklaSuma = 0, sumaKwadratow = 0;
	for (int i = 0; i < n; i++) {
		zwyklaSuma += tablica[i];
		sumaKwadratow += (tablica[i] * tablica[i]);
	}
	return ((sumaKwadratow - 2 * zwyklaSuma*zwyklaSuma / n + zwyklaSuma*zwyklaSuma / n) / (n - 1));
}

int main() {

	//// Zadanie 5.4

	//int n;
	//cout << "Podaj rozmiar tablicy:" << endl;
	//cin >> n;
	//if (n <= 0) {
	//	cout << "Bledne dane." << endl;
	//	system("pause");
	//	return 1;
	//}

	//int *tablica = new int[n];
	//cout << "Wypisz " << n << " elementow tablicy od 0 do 19:" << endl;
	//for (int i = 0; i < n; i++) {
	//	cin >> tablica[i];
	//	if (tablica[i] < 0 || tablica[i] > 19) {
	//		cout << "Bledne dane." << endl;
	//		system("pause");
	//		return 1;
	//	}
	//}

	//cout << "Moda: " << wyznaczMode(tablica, n) << endl;
	//delete[] tablica;

	//// Zadanie 5.6

	//int n;
	//int k;
	//cout << "Podaj rozmiar tablicy:" << endl;
	//cin >> n;
	//cout << "Podaj maksymalna wartosc w tablicy:" << endl;
	//cin >> k;
	//if (n <= 0 || k <= 0) {
	//	cout << "Bledne dane." << endl;
	//	system("pause");
	//	return 1;
	//}

	//int *tablica = new int[n];
	//cout << "Wypisz " << n << " elementow tablicy od 1 do " << k << ":" << endl;
	//for (int i = 0; i < n; i++) {
	//	cin >> tablica[i];
	//	if (tablica[i] < 1 || tablica[i] > k) {
	//		cout << "Bledne dane." << endl;
	//		system("pause");
	//		return 1;
	//	}
	//}

	//cout << "Nieposortowana tablica: " << endl;
	//wypiszTablice(tablica, n);
	//cout << "Posortowana tablica: " << endl;
	//sortowanieKubelkowe(tablica, n, k);
	//wypiszTablice(tablica, n);
	//delete[] tablica;

	//// Zadanie Przygotowawcze 2014 4A

	//int pierwszy, wiersz;
	//cout << "Podaj pierwszy element w trojkacie Bella:" << endl;
	//cin >> pierwszy;
	//cout << "Podaj interesujacy Cie wiersz trojkata Bella:" << endl;
	//cin >> wiersz;
	//if (wiersz <= 0 || pierwszy <= 0) {
	//	cout << "Bledne dane." << endl;
	//	system("pause");
	//	return 1;
	//}

	//int* wierszTrojkataBella = wypiszWybranyWierszTrojkataBella(pierwszy, wiersz);
	//cout << wiersz << " wiersz trojkata Bella o pierwszym elemencie rownym " << pierwszy << ":" << endl;
	//wypiszTablice(wierszTrojkataBella, wiersz);

	//// Zadanie 5.17

	//int n;
	//cout << "Podaj rozmiar tablicy:" << endl;
	//cin >> n;
	//if (n <= 0) {
	//	cout << "Bledne dane." << endl;
	//	system("pause");
	//	return 1;
	//}

	//double *tablica = new double[n];
	//cout << "Wypisz " << n << " elementow, dla ktorych wyznaczona zostanie wariancja:" << endl;
	//for (int i = 0; i < n; i++) {
	//	cin >> tablica[i];
	//}

	//cout << "Wariancja tych elementow wynosi: " << endl << wyznaczWariancje(tablica, n) << endl;
	//delete[] tablica;

	system("pause");
	return 0;
}