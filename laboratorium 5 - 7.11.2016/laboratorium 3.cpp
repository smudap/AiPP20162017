#include <iostream>
#include <cmath>
using namespace std;

int zamien(int d, int e){
	int temp = e;
	e = d;
	d = temp;
	return d;
}

int zamienReferencja(int& d, int e){
	int temp = e;
	e = d;
	d = temp;
	return d;
}

int dodaj(int a, int b, int c){
	return 2 * a + b + c;
}

struct rozwiazanieUkladu{
	double x, y;
};

double wyznacznik(double a, double b, double c, double d){
	return a * d - b * c;
}

rozwiazanieUkladu rozwiazUklad(double a, double b, double c, double d, double e, double f){
	rozwiazanieUkladu rozwiazanie;
	double W = wyznacznik(a, b, d, e);
	if (W == 0){
		cout << "Uklad jest sprzeczny lub nieoznaczony." << endl;
		rozwiazanie = { NAN, NAN };
	} 
	double Wx = wyznacznik(c, b, f, e);
	double Wy = wyznacznik(a, c, d, f);
	rozwiazanie = {Wx / W, Wy / W};
	return rozwiazanie;
}
struct prostokat{
	double x_min, x_max, y_min, y_max;
};

void wypisanieProstokatu(prostokat p){
	cout << "[" << p.x_min << ", " << p.x_max << "] x [" << p.y_min << ", " << p.y_max << "]" << endl;
}

bool sprawdzenieWarunkowZawierania(double a, double b, double c){
	if (a < b && b < c){
		return true;
	} else {
		return false;
	}
}

bool sprawdzeniePrzeciecia(prostokat p1, prostokat p2){
	return (sprawdzenieWarunkowZawierania(p2.x_min, p1.x_min, p2.x_max) ||
		sprawdzenieWarunkowZawierania(p2.x_min, p1.x_max, p2.x_max) ||
		sprawdzenieWarunkowZawierania(p1.x_min, p2.x_min, p1.x_max) ||
		sprawdzenieWarunkowZawierania(p1.x_min, p2.x_max, p1.x_max)) &&
		(sprawdzenieWarunkowZawierania(p2.y_min, p1.y_min, p2.y_max) ||
			sprawdzenieWarunkowZawierania(p2.y_min, p1.y_max, p2.y_max) ||
			sprawdzenieWarunkowZawierania(p1.y_min, p2.y_min, p1.y_max) ||
			sprawdzenieWarunkowZawierania(p1.y_min, p2.y_max, p1.y_max));
}

void wypisanieCzyPrzeciete(bool czyPrzeciete){
	if (czyPrzeciete) {
		cout << "Tak, przecinaja sie." << endl;
	}
	else {
		cout << "Nie, nie przecinaja sie." << endl;
	}
}

int main() {

	//int a = 2, b = 3, c = 4;
	//
	//// Przekazywanie argumentów przez kopiowanie i referencje
	//cout << zamien(a, b) << endl;
	//cout << "a = " << a << endl;
	//cout << zamienReferencja(a, b) << endl;
	//cout << "Referencja: a = " << a << endl;

	//// Kolejnoœæ argumentów ma znaczenie
	//cout << dodaj(a, b, c) << endl;
	//cout << dodaj(b, c, a) << endl;

	//// Zadanie 4.11
	//int a = 1, b = 1, c = 2, d = 2, e = 1, f = 3;
	//rozwiazanieUkladu rozwiazanie = rozwiazUklad(a, b, c, d, e, f);
	//cout << "Uklad dla: a = " << a << ", b = " << b << ", c = " << c;
	//cout << ", d = " << d << ", e = " << e << ", f = " << f << endl;
	//cout << "Rozwiazanie: x = " << rozwiazanie.x << ", y = " << rozwiazanie.y << endl;

	//a = 1, b = 1, c = 4, d = 1, e = 0, f = -2;
	//rozwiazanie = rozwiazUklad(a, b, c, d, e, f);
	//cout << "Uklad dla: a = " << a << ", b = " << b << ", c = " << c;
	//cout << ", d = " << d << ", e = " << e << ", f = " << f << endl;
	//cout << "Rozwiazanie: x = " << rozwiazanie.x << ", y = " << rozwiazanie.y << endl;

	//a = 1, b = 1, c = 4, d = 1, e = 1, f = 2;
	//cout << "Uklad dla: a = " << a << ", b = " << b << ", c = " << c;
	//cout << ", d = " << d << ", e = " << e << ", f = " << f << endl;
	//rozwiazanie = rozwiazUklad(a, b, c, d, e, f);

	// Zadanie 4.12
	prostokat p1 = {0, 2, 0, 2};
	prostokat p2 = {1, 3, 1, 3};
	prostokat p3 = {0, 1, 0, 1};
	prostokat p4 = {1, 2, 1, 2};
	cout << "Prostokat p1 = ";
	wypisanieProstokatu(p1);
	cout << "Prostokat p2 = ";
	wypisanieProstokatu(p2);
	cout << "Prostokat p3 = ";
	wypisanieProstokatu(p3);
	cout << "Prostokat p4 = ";
	wypisanieProstokatu(p4);

	cout << "Czy prostokaty p1 i p2 sie przecinaja?" << endl;
	wypisanieCzyPrzeciete(sprawdzeniePrzeciecia(p1, p2));
	cout << "Czy prostokaty p1 i p3 sie przecinaja?" << endl;
	wypisanieCzyPrzeciete(sprawdzeniePrzeciecia(p1, p3));	
	cout << "Czy prostokaty p1 i p4 sie przecinaja?" << endl;
	wypisanieCzyPrzeciete(sprawdzeniePrzeciecia(p1, p4));
	cout << "Czy prostokaty p2 i p3 sie przecinaja?" << endl;
	wypisanieCzyPrzeciete(sprawdzeniePrzeciecia(p2, p3));
	cout << "Czy prostokaty p2 i p4 sie przecinaja?" << endl;
	wypisanieCzyPrzeciete(sprawdzeniePrzeciecia(p2, p4));
	cout << "Czy prostokaty p3 i p4 sie przecinaja?" << endl;
	wypisanieCzyPrzeciete(sprawdzeniePrzeciecia(p3, p4));
		
	system("pause");
	return 0;
}
