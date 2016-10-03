// KOD DO POPRAWY
//
//#include <iosrteam>
//
//
///* podany plik zrodlowy zawiera bledy. postaraj sie je naprawic. :-) */
//
//
//int main()
//{
//	int rokakt;
//	int rokur
//
//		cout << "jaki mamy rok? " << rokakt;
//	cin >> rokakt;
//
//	cout << "podaj teraz swoj rok urodzenia: " << rokakt
//		cin >> rokur;
//
//	cout << "zatem masz " << (rokur - rokakt) << lat.;
//
//	return 0;
//}

// POPRAWIONY KOD

#include <iostream>
using namespace std;

int main()
{
	int rokakt;
	int rokur;

	cout << "Jaki mamy rok?" << endl;
	cin >> rokakt;

	cout << "Podaj teraz swoj rok urodzenia:" << endl;
	cin >> rokur;

	cout << "Zatem masz " << (rokakt - rokur) << " lat." << endl;

	system("pause");
	return(0);
}