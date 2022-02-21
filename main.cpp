#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Znajomy {
    int idAdresata;
    int idUzytkownika;
    string imie, nazwisko, nrtelefonu, email, adres;
};

struct Uzytkownik {
    int id;
    string nazwa, haslo;
};

vector <Uzytkownik> uzytkownicy;
vector <Znajomy> znajomi;

int zliczanieLiniiPliku() {
    int ileLinii = 0;
    string linia;
    char znak = '|';
    ifstream myfile("ksiazka_adresowa.txt");
    if(myfile.is_open()) {
        while(!myfile.eof()) {
            getline(myfile, linia, znak);
            ileLinii++;
        }
        myfile.close();
    return ileLinii;
}
}

int idOstatniegoAdresata() {
    int ostatnieId, pomoc ;
    int i = zliczanieLiniiPliku()-6; //pozycja ostatniego id adresata
    fstream plik;
    plik.open ("ksiazka_adresowa.txt", ios::in);
    if (plik.good()){
    int nrlinii = 1;
    string linia;
    char znak = '|';
    while(getline(plik, linia, znak)) {
        nrlinii++;
        if (nrlinii == i)
        {
            ostatnieId = atoi(linia.c_str());
        }
    }
    }
    plik.close();
    return ostatnieId;
}

void zamianaNazwyPlikow ()
{
    ofstream f1( "ksiazka_adresowa.txt", ios::trunc );
    ifstream f2( "ksiazka_adresowa_temp.txt");
    f1 << f2.rdbuf();
}

void zapiszDoPlikuUzytkownicy () {

    fstream plik;
    plik.open ("uzytkownicy.txt", ios::out|ios::trunc);
    if (plik.good()) {
        for (int i = 0; i < uzytkownicy.size(); i++) {
            plik << uzytkownicy[i].id << "|";
            plik << uzytkownicy[i].nazwa << "|";
            plik << uzytkownicy[i].haslo << "|" << endl;
        }
        plik.close();
    }
}
void usunPlikTymczasowy () {
    if (remove ("ksiazka_adresowa_temp.txt") == 0 )
        cout << "Plik usuniety" << endl;
    else
        cout << "Wystapil blad podczas usuwania pliku" << endl;
}


void zapiszDoPlikuKsiazkaAdresowa () {

    fstream plik1;
    plik1.open ("ksiazka_adresowa.txt", ios::in);
    fstream plik2;
    plik2.open ("ksiazka_adresowa_temp.txt", ios::out|ios::trunc);
    int i = 0;
    int pomocIdAdresata, pomocIdUz, IdAdresata;
    string pomocImie, pomocNazwisko, pomocNrTel, pomocEmail, pomocAdres;
    int nrlinii = 1;
    string linia;
    char znak = '|';
    while(getline(plik1, linia, znak)) {
        switch(nrlinii) {
        case 1:
                pomocIdAdresata = atoi(linia.c_str());
        case 2:
            pomocIdUz = atoi(linia.c_str());
            break;
        case 3:
            pomocImie = linia;
            break;
        case 4:
            pomocNazwisko = linia;
            break;
        case 5:
            pomocNrTel = linia;
            break;
        case 6:
            pomocEmail = linia;
            break;
        case 7:
            {
            pomocAdres = linia;
            IdAdresata = znajomi[i].idAdresata;
            if ((pomocIdAdresata != IdAdresata)||(i > znajomi.size()))
            {
            plik2 << pomocIdAdresata << "|";
            plik2 << pomocIdUz << "|";
            plik2 << pomocImie << "|";
            plik2 << pomocNazwisko << "|";
            plik2 << pomocNrTel << "|";
            plik2 << pomocEmail << "|";
            plik2 << pomocAdres << "|" << endl;
            }
            else if (pomocIdAdresata == IdAdresata)
            {
            plik2 << znajomi[i].idAdresata << "|";
            plik2 << znajomi[i].idUzytkownika << "|";
            plik2 << znajomi[i].imie << "|";
            plik2 << znajomi[i].nazwisko << "|";
            plik2 << znajomi[i].nrtelefonu << "|";
            plik2 << znajomi[i].email << "|";
            plik2 << znajomi[i].adres << "|" << endl;
            i++;
            }
            nrlinii = 0;
            }
        break;
        }
        nrlinii++;
    }
        plik1.close();
        plik2.close();
        zamianaNazwyPlikow();
        usunPlikTymczasowy();
    }

void UsunZPlikuKsiazkaAdresowa (int numerId) {

    fstream plik1;
    plik1.open ("ksiazka_adresowa.txt", ios::in);
    fstream plik2;
    plik2.open ("ksiazka_adresowa_temp.txt", ios::out|ios::trunc);
    int i = 0;
    int pomocIdAdresata, pomocIdUz, IdAdresata;
    string pomocImie, pomocNazwisko, pomocNrTel, pomocEmail, pomocAdres;
    int nrlinii = 1;
    string linia;
    char znak = '|';
    while(getline(plik1, linia, znak)) {
        switch(nrlinii) {
        case 1:
            pomocIdAdresata = atoi(linia.c_str());
        case 2:
            pomocIdUz = atoi(linia.c_str());
            break;
        case 3:
            pomocImie = linia;
            break;
        case 4:
            pomocNazwisko = linia;
            break;
        case 5:
            pomocNrTel = linia;
            break;
        case 6:
            pomocEmail = linia;
            break;
        case 7:
            {
            pomocAdres = linia;
            if ((pomocIdAdresata != numerId)||(i > znajomi.size()))
            {
            plik2 << pomocIdAdresata << "|";
            plik2 << pomocIdUz << "|";
            plik2 << pomocImie << "|";
            plik2 << pomocNazwisko << "|";
            plik2 << pomocNrTel << "|";
            plik2 << pomocEmail << "|";
            plik2 << pomocAdres << "|" << endl;
            }

            nrlinii = 0;
            }
        break;
        }
        nrlinii++;
    }
        plik1.close();
        plik2.close();
        zamianaNazwyPlikow();
        usunPlikTymczasowy();
    }

int rejestracja (int iloscUzytkownikow) {
    Uzytkownik pomoc;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> pomoc.nazwa;
    int i = 0;
    while (i < uzytkownicy.size()) {
        if (uzytkownicy[i].nazwa == pomoc.nazwa) {
            cout << "Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> pomoc.nazwa;
            i = 0;
        } else {
            i++;
        }
    }
    cout << "Podaj haslo: ";
    cin >> pomoc.haslo;
    pomoc.id = iloscUzytkownikow + 1;
    uzytkownicy.push_back(pomoc);
    fstream plik;
    plik.open ("uzytkownicy.txt", ios::out|ios::app);
    if (plik.good()) {
        plik << pomoc.id << "|";
        plik << pomoc.nazwa << "|";
        plik << pomoc.haslo << "|" << endl;

        plik.close();

    } else {
        cout << "Nie mozna otworzyc pliku txt";
        Sleep(1000);
    }
    cout << "Konto zalozone" << endl;
    Sleep(1000);
    return iloscUzytkownikow+1;
}
int logowanie (int iloscUzytkownikow) {
    string nazwa, haslo;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;
    int i = 0;
    while (i < iloscUzytkownikow) {
        if (uzytkownicy[i].nazwa == nazwa) {
            for (int proby = 0; proby < 3; proby++) {
                cout << "Podaj haslo. Pozostalo prob " << 3-proby << " : ";
                cin >> haslo;
                if (uzytkownicy[i].haslo == haslo) {
                    cout << "Zalogowano." << endl;
                    Sleep (1000);
                    return uzytkownicy[i].id;
                }

            }
            cout << "Bledne haslo, poczekaj 3 s." << endl;
            Sleep(3000);
            return 0;

        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl;
    Sleep(1000);
    return 0;
}
int dodajkontakt (int iloscZnajomych, int idZalogowanegoUzytkownika) {
    int ostatnieId = idOstatniegoAdresata();

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

    pomoc.idAdresata = ostatnieId +1;
    pomoc.idUzytkownika = idZalogowanegoUzytkownika;

    znajomi.push_back(pomoc);

    fstream plik;
    plik.open ("ksiazka_adresowa.txt", ios::out|ios::app);
    if (plik.good()) {
        plik << pomoc.idAdresata << "|";
        plik << pomoc.idUzytkownika << "|";
        plik << pomoc.imie << "|";
        plik << pomoc.nazwisko << "|";
        plik << pomoc.nrtelefonu << "|";
        plik << pomoc.email << "|";
        plik << pomoc.adres << "|" << endl;

        plik.close();
        cout << "Dodano kontakt do bazy danych";
        Sleep(1000);
    } else {
        cout << "Nie mozna otworzyc pliku txt";
        Sleep(1000);
    }
    return iloscZnajomych+1;
}

void wyswietlwszystkie (int idZalogowanegoUzytkownika) {
    for (int i = 0; i < znajomi.size(); i++) {
        {
            cout << znajomi[i].idAdresata << "|";
            cout << znajomi[i].idUzytkownika << "|";
            cout << znajomi[i].imie << "|";
            cout << znajomi[i].nazwisko << "|";
            cout << znajomi[i].nrtelefonu << "|";
            cout << znajomi[i].email << "|";
            cout << znajomi[i].adres << endl;
        }
    }
    getch();
}

void wczytajosobyzplikuUzytkownicy () {
    fstream plik;
    plik.open ("uzytkownicy.txt", ios::in);
    int nrlinii = 1;
    string linia;
    Uzytkownik pomoc;
    char znak = '|';
    while(getline(plik, linia, znak)) {
        switch(nrlinii) {
        case 1:
            pomoc.id = atoi(linia.c_str());
            break;
        case 2:
            pomoc.nazwa = linia;
            break;
        case 3:
            pomoc.haslo = linia;
            nrlinii = 0;
            uzytkownicy.push_back(pomoc);

            break;
        }
        nrlinii++;
    }
    plik.close();
}
void wczytajosobyzplikuKsiazkaAdresowa (int idZalogowanegoUzytkownika) {
    fstream plik;
    plik.open ("ksiazka_adresowa.txt", ios::in);
    int nrlinii = 1;
    string linia;
    int pomocIdAdr, pomocIdUz;
    string pomocIm, pomocNaz, pomocTel, pomocEm, pomocAdr;
    Znajomy pomoc;
    char znak = '|';
    while(getline(plik, linia, znak)) {
        switch(nrlinii) {
        case 1:
            pomocIdAdr = atoi(linia.c_str());
            break;
        case 2:
            pomocIdUz = atoi(linia.c_str());
            break;
        case 3:
            pomocIm = linia;
            break;
        case 4:
            pomocNaz = linia;
            break;
        case 5:
            pomocTel = linia;
            break;
        case 6:
            pomocEm = linia;
            break;
        case 7: {
            pomocAdr = linia;
            if (pomocIdUz == idZalogowanegoUzytkownika)
            {
                pomoc.idAdresata = pomocIdAdr;
                pomoc.idUzytkownika = pomocIdUz;
                pomoc.imie = pomocIm;
                pomoc.nazwisko = pomocNaz;
                pomoc.nrtelefonu = pomocTel;
                pomoc.email = pomocEm;
                pomoc.adres = pomocAdr;
                znajomi.push_back(pomoc);
                nrlinii = 0;
            }
            else
            nrlinii = 0;
        }
        break;
        }

        nrlinii++;
    }
    plik.close();
}

void wyszukajpoimieniu (int idZalogowanegoUzytkownika) {
    string imieSzukane;
    cout<<"Wpisz imie, ktorego szukasz: ";
    cin>>imieSzukane;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].imie == imieSzukane) {
            cout << znajomi[i].idAdresata << "|";
            cout << znajomi[i].imie << "|";
            cout << znajomi[i].nazwisko << "|";
            cout << znajomi[i].nrtelefonu << "|";
            cout << znajomi[i].email << "|";
            cout << znajomi[i].adres << endl;
        }
    }
    getch();
}
void wyszukajponazwisku (int idZalogowanegoUzytkownika) {
    string nazwiskoSzukane;
    cout<<"Wpisz nazwisko, ktorego szukasz: ";
    cin>>nazwiskoSzukane;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].nazwisko == nazwiskoSzukane) {
            cout << znajomi[i].idAdresata << "|";
            cout << znajomi[i].imie << "|";
            cout << znajomi[i].nazwisko << "|";
            cout << znajomi[i].nrtelefonu << "|";
            cout << znajomi[i].email << "|";
            cout << znajomi[i].adres << endl;
        }
    }
    getch();
}
void zmianaHasla(int iloscUzytkownikow, int idZalogowanegoUzytkownika) {
    string haslo;
    cout << "Podaj nowe haslo: ";
    cin >> haslo;
    for (int i = 0; i < iloscUzytkownikow; i++) {
        if (uzytkownicy[i].id == idZalogowanegoUzytkownika) {
            uzytkownicy[i].haslo = haslo;
            zapiszDoPlikuUzytkownicy();
            cout << "Haso zostalo zmienione." << endl;
            Sleep(1000);
        }
    }
}
void edytujImie (int numerId, int idZalogowanegoUzytkownika) {
    string noweImie;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].idAdresata == numerId) {
            cout << "Podaj nowe imie: ";
            cin >> noweImie;
            znajomi[i].imie = noweImie;
            zapiszDoPlikuKsiazkaAdresowa();
            cout << "Zmieniono imie";
        }
    }
    Sleep(1000);
}
void edytujNazwisko (int numerId, int idZalogowanegoUzytkownika) {
    string noweNazwisko;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].idAdresata == numerId) {
            cout << "Podaj nowe nazwisko: ";
            cin >> noweNazwisko;
            znajomi[i].nazwisko = noweNazwisko;
            zapiszDoPlikuKsiazkaAdresowa();
            cout << "Zmieniono nazwisko";
        }

    }
    Sleep(1000);
}
void edytujNrTelefonu (int numerId, int idZalogowanegoUzytkownika) {
    string nowyNrTelefonu;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].idAdresata == numerId) {
            cout << "Podaj nowy adres: ";
            cin >> nowyNrTelefonu;
            znajomi[i].nrtelefonu = nowyNrTelefonu;
            zapiszDoPlikuKsiazkaAdresowa();
            cout << "Zmieniono adres";
        }

    }
    Sleep(1000);
}
void edytujEmail (int numerId, int idZalogowanegoUzytkownika) {
    string nowyEmail;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].idAdresata == numerId) {
            cout << "Podaj nowy email: ";
            cin >> nowyEmail;
            znajomi[i].email = nowyEmail;
            zapiszDoPlikuKsiazkaAdresowa();
            cout << "Zmieniono email";
        }

    }
    Sleep(1000);
}
void edytujAdres (int numerId, int idZalogowanegoUzytkownika) {
    string nowyAdres;
    for (int i = 0; i < znajomi.size(); i++) {
        if(znajomi[i].idAdresata == numerId) {
            cout << "Podaj nowy adres: ";
            cin >> nowyAdres;
            znajomi[i].adres = nowyAdres;
            zapiszDoPlikuKsiazkaAdresowa();
            cout << "Zmieniono adres";
        }

    }
    Sleep(1000);
}
void usuniecieKontaktu (int numerId, int idZalogowanegoUzytkownika) {
    int iloscZnajomych = znajomi.size();
    for (auto itr = znajomi.begin(); itr != znajomi.end(); ++itr) {
        if (itr -> idAdresata == numerId) {
            cout << "Czy na pewno chcesz usunac kontakt? Wcisnij t. ";
            char potwierdzenie;
            cin >> potwierdzenie;
            if (potwierdzenie == 't') {
                znajomi.erase(itr);
                UsunZPlikuKsiazkaAdresowa(numerId);
                cout << "Kontakt usuniety.";
                break;
            }
        }
    }
    Sleep(1000);
}

int main() {
    char wybor;


    wczytajosobyzplikuUzytkownicy();
    //tworzeniePlikuTymczasowego();

    int idZalogowanegoUzytkownika = 0;
    int iloscUzytkownikow = uzytkownicy.size();
    int iloscznajomych = znajomi.size();
    int idKontaktu = 0;
    int idUsuniecie;

    while (1) {
        if (idZalogowanegoUzytkownika ==0) {
            system("cls");

            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            wybor = getch();
            if (wybor == '1') {
                iloscUzytkownikow = rejestracja(iloscUzytkownikow);
            } else if (wybor == '2') {

                idZalogowanegoUzytkownika = logowanie(iloscUzytkownikow);
                wczytajosobyzplikuKsiazkaAdresowa(idZalogowanegoUzytkownika);
            } else if (wybor == '9') {
                exit(0);
            }
        } else if ((idKontaktu == 0)&&(idZalogowanegoUzytkownika !=0)) {

            system("cls");

            cout << iloscznajomych<<endl;
            cout << idZalogowanegoUzytkownika<<endl;

            cout << "1. Dodaj kontakt" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl wszystkie" << endl;
            cout << "5. Edytuj kontakt" << endl;
            cout << "6. Usun kontakt" << endl;
            cout << "7. Zmien haslo" << endl;
            cout << "9. Wyloguj sie" << endl;

            wybor = getch();

            switch (wybor) {
            case '1': {
                iloscznajomych=dodajkontakt(iloscznajomych, idZalogowanegoUzytkownika);

            }
            break;

            case '2': {
                wyszukajpoimieniu(idZalogowanegoUzytkownika);
            }
            break;

            case '3': {
                wyszukajponazwisku(idZalogowanegoUzytkownika);
            }
            break;

            case '4': {
                wyswietlwszystkie(idZalogowanegoUzytkownika);
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
                usuniecieKontaktu (idUsuniecie, idZalogowanegoUzytkownika);
                iloscznajomych = znajomi.size();
            }
            break;

            case '7':
                zmianaHasla(iloscUzytkownikow, idZalogowanegoUzytkownika);
                break;

            case '9':
                znajomi.clear();
                idZalogowanegoUzytkownika = 0;

                break;
            }
        }

        else if (idKontaktu != 0) {
            system("cls");
            cout << "Ktora dana chcesz zmienic: " << endl;
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Nr telefonu" << endl;
            cout << "4. Adres email" << endl;
            cout << "5. Adres zamieszkania" << endl;
            cout << "9. Powrot do menu" << endl;
            wybor = getch();

            switch (wybor) {
            case '1': {
                edytujImie(idKontaktu, idZalogowanegoUzytkownika);
            }
            break;
            case '2': {
                edytujNazwisko(idKontaktu, idZalogowanegoUzytkownika);
            }
            break;
            case '3': {
                edytujNrTelefonu(idKontaktu, idZalogowanegoUzytkownika);
            }
            break;
            case '4': {
                edytujEmail(idKontaktu, idZalogowanegoUzytkownika);
            }
            break;
            case '5': {
                edytujAdres(idKontaktu, idZalogowanegoUzytkownika);
            }
            break;
            case '9': {
                idKontaktu=0;
            }
            break;
            }
        }
    }
    return 0;
}
