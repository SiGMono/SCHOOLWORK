#include <iostream>

using namespace std;

//  Funkcja do sprawdzania czy wprowadzane wartości są numeryczne
bool is_digits(string& str)
{
    for (char ch : str) {
        if (!isdigit(ch)){
            return false;
        }
    }
    return true;
}

int main(){
    //  Wartości banknotów i monet PLN wraz z groszami zwiększone o x100 aby nie korzystać z wartości zmiennoprzecinkowych
    int nominaly[15] = {50000,20000,10000,5000,2000,1000,500,200,100,50,20,10,5,2,1};
    
    //  Ten licznik[] istnieje aby zliczaj wszystkie banknoty i monety które zostały wydane
    int licznik[15] = {0};

    //  Zmienna reszta która działa jako aktualny stan reszty do wydania
    //  i aktualnyNominal który oznajmia aktualny nominał w tabeli nominaly.
    int reszta, resztazloty, resztagrosz, aktualnyNominal = 0;

    string resztazlotyS, resztagroszS;

    //  Pobieranie reszty złotych (w tym wypadku wpisana ręcznie)
    cout << "Reszta zlotych: " << endl;
    cin >> resztazlotyS;
    //  Sprawdzanie czy nie ma wartosci nienymerycznych
    if(!is_digits(resztazlotyS)){
        cout << "Wykryto wartosc nienumeryczna, zamykanie programu...";
        return 0;
    }
    //  Konwersja string do int
    resztazloty = stoi(resztazlotyS);

    //  Pobieranie reszty groszy
    cout << "Reszta groszy:" <<endl;
    cin >> resztagroszS;
    //  Sprawdzanie czy nie ma wartosci nienymerycznych
    if(!is_digits(resztazlotyS)){
        cout << "Wykryto wartosc nienumeryczna, zamykanie programu...";
        return 0;
    }
    //  Konwersja string do int
    resztagrosz = stoi(resztagroszS);

    //  Zabezpieczenia przed wartosciami ujemnymi i zerowymi
    if(resztazloty < 0 || resztagrosz < 0){
        cout << "Zadna z wartosci nie moze byc ujemna.";
        return 0;
    }
    if(resztazloty == 0 && resztagrosz == 0){
        cout << "Conajmniej jedna z dwoch wartosci musi byc niezerowa.";
        return 0;
    }

    //  Grosze zajmują dwie ostatnie pozycje w int reszta
    reszta = resztazloty*100 + resztagrosz;

    //  Wypisywanie reszty poprzez algorytm zachłanny np. 1220 -> 720 (1 = 500) -> 220 (2 = 500) -> 120 (2 = 500, 1 = 100) -> 20 (2 = 500, 2= 100) -> 10 (2 = 500, 2= 100, 1 = 10) -> (2 = 500, 2= 100, 2 = 10)
    //  Ta pętla jest while true zamykana poprzez porówanie if(reszta <= 0) istnieje w taki sposób ze względu na wypisywanie ostatniej wartości i ilości groszów. 
    while(true){
        if(reszta >= nominaly[aktualnyNominal]){
            licznik[aktualnyNominal]++;
            reszta -= nominaly[aktualnyNominal];
        }else{
            //  To porównanie istnieje aby nie pokazywać wartości pieniężnych, które nie są do wydania (0 do wydania)
            if(licznik[aktualnyNominal] != 0){
                //  Porównanie do wyodrębniania złotówek od groszy bez potrzeby tworzenia osobnej pętli dla groszy
                if(aktualnyNominal < 9){
                    cout << "Zloty: " << nominaly[aktualnyNominal] / 100 << " Ilosc: " << licznik[aktualnyNominal] <<endl;
                }else{
                    cout << "Grosz: " << nominaly[aktualnyNominal] << " Ilosc: " << licznik[aktualnyNominal] <<endl;
                }
            }
            aktualnyNominal++;
        }
        //  Porownanie zakończeniowe
        if(reszta <= 0){break;}
    }

    cout << "Reszta wydana." << endl;

    return 0;
}