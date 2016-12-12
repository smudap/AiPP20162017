#pragma once

struct Skarbiec
{
	double x, y;
	int zloto;
};

struct Rozbojnik
{
	int zloto;
	Skarbiec* skarbiec;
};

// Funkcja zwraca nowy, losowy skarbiec.
Skarbiec wylosujSkarbiec();

// Wypisanie wszystkich informacji o skarbcu, na kt�ry pokazuje podany wska�nik.
void wypiszSkarbiec(Skarbiec* s);

// Wypisanie wszystkich informacji o podanym rozbojniku.
void wypiszRozbojnika(Rozbojnik r);