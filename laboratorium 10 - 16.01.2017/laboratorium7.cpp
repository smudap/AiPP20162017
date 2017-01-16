#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// ZADANIE 5A 2012

// tworzy nowa macierz
double** tworzMacierz(int n, int m)
{
	double** M = new double*[n];
	for (int i = 0; i<n; ++i)
		M[i] = new double[m];
	return M;
}
// wypelnia macierz losowymi wartosciami z przedzialu [0,1]
void wypelnijMacierz(double** A, int n, int m)
{
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j<m; ++j)
			A[i][j] = rand() / (double)RAND_MAX;
	}
}
// kasuje macierz z pamieci
void kasujMacierz(double** A, int n, int m)
{
	for (int i = 0; i<n; ++i)
		delete[] A[i];
	delete[] A;
}

// wypisuje macierz na ekran
void wypiszMacierz(double** A, int n, int m)
{
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j<m; ++j)
			cout << setw(6) << A[i][j];
		cout << endl;
	}
}

double** dodajWiersz(double** A, int n, int m, int i) {
	double** B = tworzMacierz(n + 1, m);
	double srednia = 0;
	int l;
	for (int j = 0; j < m; j++) {
		for (int k = 0; k < n + 1;k++) {
			if (k == i + 1)
				continue;
			l = (k > i + 1) ? k - 1 : k;
			B[k][j] = A[l][j];
			srednia += A[l][j];
		}
		B[i + 1][j] = srednia / n;
		srednia = 0;
	}
	return B;
}

double** usunWiersz(double** A, int n, int m, int i) {
	double** B = tworzMacierz(n - 1, m);
	int l;
	for (int k = 0; k < n - 1; k++) {
		for (int j = 0; j < m; j++) {
			l = (k >= i) ? k + 1 : k;
			B[k][j] = A[l][j];
		}
	}
	return B;
}

int main() {
	//double** macierz = tworzMacierz(4, 5);
	//wypelnijMacierz(macierz, 4, 5);
	//wypiszMacierz(macierz, 4, 5);
	//cout << endl;
	//wypiszMacierz(dodajWiersz(macierz, 4, 5, 2), 5, 5);
	//
	//cout << endl;
	//wypiszMacierz(usunWiersz(macierz, 4, 5, 2), 3, 5);
	//
	//kasujMacierz(macierz, 4, 5);

	srand(time(0));
	int n, m;
	cout << "Podaj liczbe wierszy: ";
	cin >> n;
	cout << "Podaj liczbe kolumn: ";
	cin >> m;

	if (n <= 0 || m <= 0) {
		cout << "Podales zly wymiar macierzy." << endl;
		return 1;
	}

	double** A = tworzMacierz(n, m);
	wypelnijMacierz(A, n, m);
	int x = 1;
	do {
		cout << endl;
		wypiszMacierz(A, n, m);
		cout << endl;
		cout << "Wybor x: ";
		cin >> x;
		if (x > 0) {
			if (x - 1 >= n) {
				cout << "Niepoprawny x." << endl;
				continue;
			}
			A = dodajWiersz(A, n, m, x - 1);
			n++;
		}
		else if (x < 0) {
			if (-x - 1 >= n) {
				cout << "Niepoprawny x." << endl;
				continue;
			}
			A = usunWiersz(A, n, m, -x - 1);
			n--;
		}
		if (n == 0) {
			cout << "Macierz zerowa. Koniec zabawy." << endl;
			break;
		}
	} while (x != 0);

	kasujMacierz(A, n, m);

	system("pause");
	return 0;
}