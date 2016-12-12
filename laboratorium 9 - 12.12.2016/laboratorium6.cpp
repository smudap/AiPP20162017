#include <iostream>
using namespace std;
#include "skarby.h"

// Funkcja zwraca pusty skarbiec o losowych wspó³rzêdnych.
Skarbiec wylosujSkarbiec()
{
	Skarbiec s;
	s.x = (1.0*rand() / RAND_MAX) * 100;
	s.y = (1.0*rand() / RAND_MAX) * 100;
	s.zloto = 0;
	return s;
}

// Wypisanie wszystkich informacji o skarbcu, na który pokazuje podany wskaŸnik.
void wypiszSkarbiec(Skarbiec* s)
{
	int p = cout.precision();
	cout.precision(5);
	setlocale(LC_ALL, "");
	cout << "Wspó³rzêdne:\tx=" << s->x << "\ty=" << s->y << endl;
	cout << "Z³oto: \t" << s->zloto << endl;
	cout.precision(p);
}

// Wypisanie wszystkich informacji o podanym rozbojniku.
void wypiszRozbojnika(Rozbojnik r)
{
	cout << "Posiadane z³oto:" << r.zloto << endl;
	cout << "Skarbiec:" << endl;
	wypiszSkarbiec(r.skarbiec);
}

// Schowanie lupu przez rozbojnika
void schowajLupy(Rozbojnik* r) {
	int posiadaneZloto = r->zloto;
	if (posiadaneZloto > 10) {
		int przenoszoneZloto = posiadaneZloto - 10;
		r->skarbiec->zloto += przenoszoneZloto;
		r->zloto = 10;
	}
}

// Przeniesienie skarbca przez rozbojnika
void przeniesSkarbiec(Rozbojnik* r) {
	int zloto = r->skarbiec->zloto;
	r->skarbiec->zloto = 0;
	r->skarbiec = new Skarbiec;
	*(r->skarbiec) = wylosujSkarbiec();
	r->skarbiec->zloto = zloto;
}

int main() {
	// 1)
	Skarbiec skarbiec = wylosujSkarbiec();
	Rozbojnik Karl, Bob;
	Karl = { 100, &skarbiec };
	Bob = { 100, &skarbiec };
	cout << "Przed schowaniem lupow" << endl;
	cout << "Rozbojnik Karl:" << endl;
	wypiszRozbojnika(Karl);
	cout << "Rozbojnik Bob:" << endl;
	wypiszRozbojnika(Bob);

	// 2)
	schowajLupy(&Karl);
	schowajLupy(&Bob);
	cout << endl << "Po schowaniu lupow" << endl;
	cout << "Rozbojnik Karl:" << endl;
	wypiszRozbojnika(Karl);
	cout << "Rozbojnik Bob:" << endl;
	wypiszRozbojnika(Bob);

	// 3)
	przeniesSkarbiec(&Karl);
	cout << endl << "Po przeniesieniu skarbca przez Karla" << endl;
	cout << "Rozbojnik Karl:" << endl;
	wypiszRozbojnika(Karl);
	cout << "Rozbojnik Bob:" << endl;
	wypiszRozbojnika(Bob);

	// 4)
	int n = 40;
	Rozbojnik* rozbojnicy = new Rozbojnik[n];
	int zloto;
	int caleZloto = 0;
	for (int i = 0; i < n;i++) {
		zloto = rand() % 21;
		rozbojnicy[i].zloto = zloto;
		rozbojnicy[i].skarbiec = &skarbiec;
		caleZloto += zloto;
	}
	cout << endl << "Zloto rozbojnikow w sumie: " << caleZloto << endl;

	// 5)
	caleZloto = 0;
	for (int i = 0;i < n;i++) {
		schowajLupy(&rozbojnicy[i]);
		caleZloto += rozbojnicy[i].zloto;
	}
	cout << endl << "Zloto rozbojnikow w sumie (po schowaniu lupow): " << caleZloto << endl;
	wypiszSkarbiec(&skarbiec);

	system("pause");
	return(0);
}