#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Znajomy {
    int id;
    string imie, nazwisko, nrtelefonu, email, adres;
};

vector <Znajomy> znajomi;

int idOstatniegoAdresata()
{
    int ostatnieId;
    if (znajomi.size() > 0)
    {
        int i = znajomi.size();
        ostatnieId = znajomi[i].id;
    }
    else
        ostatnieId = 0;
    return ostatnieId;
}

void zapiszDoPliku ()
{

    fstream plik;
    plik.open ("ksiazka_adresowa.txt", ios::out|ios::trunc);
    if (plik.good()) {
        for (int i = 0; i < znajomi.size(); i++)
        {
        plik << znajomi[i].id << "|";
        plik << znajomi[i].imie << "|";
        plik << znajomi[i].nazwisko << "|";
        plik << znajomi[i].nrtelefonu << "|";
        plik << znajomi[i].email << "|";
        plik << znajomi[i].adres << "|" << endl;
        }
        plik.close();
}
    }

int dodajkontakt (int iloscZnajomych) {
    Znajomy pomoc;
    cout << "Podaj imie: ";
    cin >> pomoc.imie;
    cout << "Podaj nazwisko: ";
    cin >> pomoc.nazwisko;
    cout << "Podaj nr telefonu: ";
    cin >> pomoc.nrtelefonu;
    cout << "Podaj email: ";
    cin >> pomoc.email;
    cout << "Podaj swoj adres zamieszkania: ";
    cin >> pomoc.adres;

    pomoc.id = idOstatniegoAdresata()+1;

    znajomi.push_back(pomoc);

    fstream plik;
    plik.open ("ksiazka_adresowa.txt", ios::out|ios::app);
    if (plik.good()) {
        plik << pomoc.id << "|";
        plik << pomoc.imie << "|";
        plik << pomoc.nazwisko << "|";
        plik << pomoc.nrtelefonu << "|";
        plik << pomoc.email << "|";
        plik << pomoc.adres << "|" << endl;

        plik.close();
        cout << "Dodano kontakt do bazy danych";
        Sleep(1000);
    } else{
        cout << "Nie mozna otworzyc pliku txt";
        Sleep(1000);
    }
    return iloscZnajomych+1;
}

void wyswietlwszystkie () {
    for (int i = 0; i < znajomi.size(); i++) {
        {
            cout << znajomi[i].id << "|";
            cout << znajomi[i].imie << "|";
            cout << znajomi[i].nazwisko << "|";
            cout << znajomi[i].nrtelefonu << "|";
            cout << znajomi[i].email << "|";
            cout << znajomi[i].adres << endl;
        }
    }
    getch();
}

void wczytajosobyzpliku () {
    fstream plik;
    plik.open ("ksiazka_adresowa.txt", ios::in);
    int nrlinii = 1;
    string linia;
    Znajomy pomoc;
    char znak = '|';
    while(getline(plik, linia, znak)) {
        switch(nrlinii) {
        case 1:
            pomoc.id = atoi(linia.c_str());
            break;
        case 2:
            pomoc.imie = linia;
            break;
        case 3:
            pomoc.nazwisko = linia;
            break;
        case 4:
            pomoc.nrtelefonu = linia;
            break;
        case 5:
            pomoc.email = linia;
            break;
        case 6: {
            pomoc.adres = linia;
            nrlinii = 0;
            znajomi.push_back(pomoc);
        }
        break;
        }
        nrlinii++;
    }
    plik.close();
}

void wyszukajpoimieniu () {
    string imieSzukane;
    cout<<"Wpisz imie, ktorego szukasz: ";
    cin>>imieSzukane;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].imie == imieSzukane) {
            cout << znajomi[i].id << endl;
            cout << znajomi[i].imie << endl;
            cout << znajomi[i].nazwisko << endl;
            cout << znajomi[i].nrtelefonu << endl;
            cout << znajomi[i].email << endl;
            cout << znajomi[i].adres << endl;
        }
    }
    getch();
}

void wyszukajponazwisku () {
    string nazwiskoSzukane;
    cout<<"Wpisz nazwisko, ktorego szukasz: ";
    cin>>nazwiskoSzukane;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].nazwisko == nazwiskoSzukane) {
            cout << znajomi[i].id << endl;
            cout << znajomi[i].imie << endl;
            cout << znajomi[i].nazwisko << endl;
            cout << znajomi[i].nrtelefonu << endl;
            cout << znajomi[i].email << endl;
            cout << znajomi[i].adres << endl;
        }
    }
    getch();
}

void edytujImie (int numerId) {
    string noweImie;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].id == numerId) {
            cout << "Podaj nowe imie: ";
            cin >> noweImie;
            znajomi[i].imie = noweImie;
            zapiszDoPliku();
            cout << "Zmieniono imie";
        }
    }Sleep(1000);
}
void edytujNazwisko (int numerId) {
    string noweNazwisko;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].id == numerId) {
            cout << "Podaj nowe nazwisko: ";
            cin >> noweNazwisko;
            znajomi[i].nazwisko = noweNazwisko;
            zapiszDoPliku();
            cout << "Zmieniono nazwisko";
        }

    }Sleep(1000);
}
void edytujNrTelefonu (int numerId) {
    string nowyNrTelefonu;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].id == numerId) {
            cout << "Podaj nowy adres: ";
            cin >> nowyNrTelefonu;
            znajomi[i].nrtelefonu = nowyNrTelefonu;
            zapiszDoPliku();
            cout << "Zmieniono adres";
        }

    }Sleep(1000);
}
void edytujEmail (int numerId) {
    string nowyEmail;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].id == numerId) {
            cout << "Podaj nowy email: ";
            cin >> nowyEmail;
            znajomi[i].email = nowyEmail;
            zapiszDoPliku();
            cout << "Zmieniono email";
        }

    } Sleep(1000);
}
void edytujAdres (int numerId) {
    string nowyAdres;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].id == numerId) {
            cout << "Podaj nowy adres: ";
            cin >> nowyAdres;
            znajomi[i].adres = nowyAdres;
            zapiszDoPliku();
            cout << "Zmieniono adres";
        }

    }Sleep(1000);
}
void usuniecieKontaktu (int numerId) {
    int iloscZnajomych = znajomi.size();
    for (auto itr = znajomi.begin(); itr != znajomi.end(); ++itr) {
        if (itr -> id == numerId) {
            cout << "Czy na pewno chcesz usunac kontakt? Wcisnij t. ";
            char potwierdzenie;
            cin >> potwierdzenie;
            if (potwierdzenie == 't')
            {
                znajomi.erase(itr);
                zapiszDoPliku();
                cout << "Kontakt usuniety.";
                break;
            }
        }
    }
Sleep(1000);
}


int main() {
    char wybor;
    wczytajosobyzpliku();
    int iloscznajomych = znajomi.size();
    int idKontaktu = 0;
    int idUsuniecie;

    while (1) {
        if (idKontaktu == 0) {
            system("cls");
            cout << "1. Dodaj kontakt" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl wszystkie" << endl;
            cout << "5. Edytuj kontakt" << endl;
            cout << "6. Usun kontakt" << endl;
            cout << "9. Koniec pracy" << endl;

            wybor = getch();

            switch (wybor) {
            case '1': {
                iloscznajomych=dodajkontakt(iloscznajomych);

            }
            break;

            case '2': {
                wyszukajpoimieniu();
            }
            break;

            case '3': {
                wyszukajponazwisku();
            }
            break;

            case '4': {
                wyswietlwszystkie();
            }
            break;

            case '5': {
                cout << "Podaj nr id kontaktu do edycji: ";
                cin >> idKontaktu;
            }
            break;

            case '6': {
                cout << "Podaj nr id kontaktu do usuniecia: ";
                cin >> idUsuniecie;
                usuniecieKontaktu (idUsuniecie);
                iloscznajomych = znajomi.size();
            }
            break;

            case '9':
                exit(0);
                break;
            }
        }

        else {
            system("cls");
            cout << "Ktora dana chcesz zmienic: " << endl;
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Nr telefonu" << endl;
            cout << "4. Adres email" << endl;
            cout << "5. Adres zamieszkania" << endl;
            cout << "6. Powrot do menu" << endl;
            wybor = getch();

            switch (wybor) {
            case '1': {
                edytujImie(idKontaktu);
                idKontaktu=0;
            }
            break;
            case '2': {
                edytujNazwisko(idKontaktu);
            }
            break;
            case '3': {
                edytujNrTelefonu(idKontaktu);
            }
            break;
            case '4': {
                edytujEmail(idKontaktu);
            }
            break;
            case '5': {
                edytujAdres(idKontaktu);
            }
            break;
            case '6': {
                idKontaktu=0;
            }
            break;
            }
        }
    }
    return 0;
}
