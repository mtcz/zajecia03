#include <iostream>
#include <string>
#include <fstream>
//ifstream plikOdczyt; -> tylko odczyt
//ofstream plikZapisz; -> tylko zapis
//ifstream plik		   -> dowolnosc
//plikOdczyt.open("C:\\plik.txt");
//plikOdczyt.good(); --> true - plik otwarty, false - plik nie uda³o sie otworzyæ
//getline(plikOdczyt, zmienna)
//plikOdczyt.close();
using namespace std;
struct czlowiek{
	string imie;
	string nazwisko;
	bool dostepny;
	czlowiek *nastepny;

};
czlowiek *pierwszy = nullptr;
czlowiek *ostatni = nullptr;

void dodaj_czlowieka()
{
	string imie, nazwisko;
	cout << "\nPodaj Imie: ";
	cin >> imie;
	cout << "\nPodaj Nazwisko: ";
	cin >> nazwisko;

	czlowiek *t = new czlowiek;
	t->imie = imie;
	t->nazwisko = nazwisko;
	t->dostepny = 1;
	t->nastepny = nullptr;

	if (pierwszy == nullptr)
	{
		pierwszy = t;
		ostatni = t;
	}
	else
	{
		ostatni->nastepny = t;
		ostatni = t;
	}

}
czlowiek *pokazczlowieka = nullptr;
void pokazkolejke()
{
	pokazczlowieka = pierwszy;
	int i = 1;
	if (pokazczlowieka == nullptr)
	{
		cout << "nie ma nikogo w kolejce" << endl;
	}
	else
	{
		while (pokazczlowieka->nastepny != nullptr)
		{
			if (pokazczlowieka->dostepny == 1){
				cout << i << " " << pokazczlowieka->imie << "\t" << pokazczlowieka->nazwisko << "\t" << pokazczlowieka->dostepny << endl;
				i++;
			}
			pokazczlowieka = pokazczlowieka->nastepny;

		}
		if (pokazczlowieka->dostepny == 1){
			cout << i << " " << pokazczlowieka->imie << "\t" << pokazczlowieka->nazwisko << "\t" << pokazczlowieka->dostepny << endl;
		}
		pokazczlowieka = pokazczlowieka->nastepny;
	}
}void zapiszkolejke()
{
	ofstream plikZapis;
	plikZapis.open("C:\\cpp\\plik.txt");

	pokazczlowieka = pierwszy;
	int i = 1;
	if (pokazczlowieka == nullptr)
	{
		cout << "nie ma nikogo w kolejce" << endl;
	}
	else
	{
		while (pokazczlowieka->nastepny != nullptr)
		{
			if (pokazczlowieka->dostepny == 1){
				plikZapis << i << " " << pokazczlowieka->imie << "\t" << pokazczlowieka->nazwisko << "\t" << pokazczlowieka->dostepny << endl;
				i++;
			}
			pokazczlowieka = pokazczlowieka->nastepny;

		}
		if (pokazczlowieka->dostepny == 1){
			plikZapis << i << " " << pokazczlowieka->imie << "\t" << pokazczlowieka->nazwisko << "\t" << pokazczlowieka->dostepny << endl;
		}
		pokazczlowieka = pokazczlowieka->nastepny;
	}
	plikZapis.close();
}
void obecnosc(){
	pokazczlowieka = pierwszy;
	int i = 1;
	if (pokazczlowieka == nullptr)
	{
		cout << "nie ma nikogo w kolejce" << endl;
	}
	else
	{
		while (pokazczlowieka->nastepny != nullptr)
		{
			if (pokazczlowieka->dostepny == 1){
				cout << i << " " << pokazczlowieka->imie << "\t" << pokazczlowieka->nazwisko << "\t" << "obecny?[1,0] " << endl;
				cin >> pokazczlowieka->dostepny;
				i++;
			}
			pokazczlowieka = pokazczlowieka->nastepny;


		}
		if (pokazczlowieka->dostepny == 1){
			cout << i << " " << pokazczlowieka->imie << "\t" << pokazczlowieka->nazwisko << "\t" << "obecny?[1,0] " << endl;
			cin >> pokazczlowieka->dostepny;
		}
		pokazczlowieka = pokazczlowieka->nastepny;

	}
}
void usunpierwszego(){
	czlowiek *p;
	p = pierwszy->nastepny;
	delete pierwszy;
	pierwszy = p;
}
void wczytajkolejke(){

}

int main(){

	int numer = 1;
	while (numer != 0){

		cout << "\n1-Dodaj do kolejki\n2-Pokaz kolejke\n3-Sprawdz obecnosc\n4-Usun pierwszego\nKoniec programu\n5-Zapisz kolejke do pliku\n";
		cin >> numer;
		system("cls");
		switch (numer)
		{
		case 1: {
					dodaj_czlowieka();
					break; }
		case 2: {
					pokazkolejke();
					break; }
		case 3: {
					obecnosc();
					break; }
		case 4: {
					usunpierwszego();
					break; }

		case 5: {
					zapiszkolejke();
					break; }


		}
	}
	cin.get();
	cin.get();
	return 0;
}
