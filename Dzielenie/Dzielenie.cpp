// Dzielenie.cpp : Defines the entry point for the console application.
//
//	dzielenie liczba ca³kowitych do 'n' miejsc po przecinku
// zapis do pliku
// znajdowanie miejsca powtórzeñ liczby

#include "stdafx.h"
#include <iostream>
#include <fstream>

void podzielLiczbe();
void podzielLiczbeUtnij(); 
using namespace std;
int a, b, n;

int main()
{
	do {

		system("cls");
		cout << "Witaj. Podziel liczbe do n miejsc po przecinku." << endl;
		cout << "n = 0 - wyjœcie z programu." << endl;
		cout << "Podaj a: ";
		cin >> a;
		do {
			cout << "Podaj b: ";
			cin >> b;
		} while (b == 0);
		cout << "Podaj ile miejsc po przecinku: ";
		cin >> n;

//		podzielLiczbe();
		podzielLiczbeUtnij();
		getchar();
		getchar();
	} while (n != 0);
	return 0;
}

// funkcja dzieli liczby i znajduje miejsce powtórzenia
void podzielLiczbeUtnij()
{
	if (n == 0)
		return;

	int aktualne[6], poczatek[6];
	bool zacznij = false;		// zacznij == true && ile_cyfr=5 to 
	int ile_powtorzen = 0;
	int ile, temp; // zmienne do obliczen
	int ktora_cyfra = -1;  // która z rzêdu cyfra jest zapisywana do tablicy, -1 bo chcê omin¹æ pierwsz¹ cyfrê (¿eby nie by³o 0 na pocz¹teku np. 02112) 
	ofstream plik;

	plik.open("wynik_dzielenia.txt");			// plik do zapisu wyniku dzielenia
	cout << "(" << n << " miejsc po przecinku)" << endl << a << " / " << b << " =" << endl;
	plik << "(" << n << " miejsc po przecinku)" << endl << a << " / " << b << " =" << endl;

	for (int i = 0; i < n + 1; i++) {

		ile = a / b;			// dzielenie bez reszty (bo inty), zaokr¹glone w dó³
		a = a - (ile * b);		// 'a' to jest to teraz reszta z dzielenia
		a = a * 10;				// przesuwamy przecinek o 1 miejsce

		cout << ile;
		plik << ile;
		if (i == 0 && a != 0) {		// zapisz/wypisz przecinek po pierwszym dzieleniu
			cout << ",";
			plik << ",";
		}

		if (a == 0)		// je¿eli nie ma reszty, to znaczy ¿e koniec
			break;

		if (zacznij == true) {				// przesuniêcie aktualnego ci¹gu
			aktualne[1] = aktualne[2];
			aktualne[2] = aktualne[3];
			aktualne[3] = aktualne[4];
			aktualne[4] = aktualne[5];
			aktualne[5] = ile;
		}


		if (zacznij == true)
		{
			ile_powtorzen = 0;
//			for (int j = 1; j <= 5; j++) 
//				cout << poczatek[j];
			for (int j = 1; j <= 5; j++) {		// sprawdŸ iloœæ powtórzeñ
				if (poczatek[j] == aktualne[j])
					ile_powtorzen++;
			}
		}

		if (a > b && i > 0 && zacznij == false)	// powtarzaj dopoki nie zapiszesz pierwszych 5 cyfr
		{
			ktora_cyfra++;
			if (ktora_cyfra > 0)
			{
				poczatek[ktora_cyfra] = ile;
				aktualne[ktora_cyfra] = ile;
			}
			if (ktora_cyfra == 5)		// je¿eli jest 5 cyfr to zacznij sprawdzaæ
				zacznij = true;
		}

		if (ile_powtorzen == 5) {		// wszystkie cyfry (5) siê powtarzaj¹, wiec zakoncz
			cout << endl << "zaczyna sie powtarzac na pozycji: " << i-5 << endl;
			plik << endl << "zaczyna sie powtarzac na pozycji: " << i-5 << endl;
			getchar();
			break;
		}

	}

	plik.close();
	if (ile_powtorzen != 5)
		cout << endl << "Nie wystapily powtorzenia" << endl;
}


// funkcja dzieli liczby, ale nie podaje kiedy zaczynaj¹ siê powtarzaæ
void podzielLiczbe()
{
	if (n == 0)
		return;

	int ile, temp;
	ofstream plik;

	plik.open("wynik_dzielenia.txt");			// plik do zapisu wyniku dzielenia
	cout << "(" << n <<" miejsc po przecinku)"<<endl << a << " / " << b << " =" << endl;
	plik << "(" << n <<" miejsc po przecinku)"<<endl << a << " / " << b << " =" << endl;

	for (int i = 0; i < n+1; i++) {

		ile = a / b;			// dzielenie bez reszty (bo inty), zaokr¹glone w dó³
		a = a - (ile * b);		// 'a' to jest to teraz reszta z dzielenia
		a = a * 10;				// przesuwamy o przecinek o 1 miejsce

//		cout << a << endl;
		cout << ile;
		plik << ile;
		if (i == 0 && a!=0 ) {		// zapisz/wypisz przecinek po pierwszym dzieleniu
			cout << ",";
			plik << ",";
		}

		if (a == 0)		// je¿eli nie ma reszty, to znaczy ¿e koniec
			break;

	}

	plik.close();
}
