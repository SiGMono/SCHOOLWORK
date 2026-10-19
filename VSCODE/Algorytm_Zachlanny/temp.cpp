#include <iostream>

using namespace std;

int main(){
    //  Wartości banknotów i monet PLN wraz z groszami zwiększone o x100 aby nie korzystać z wartości zmiennoprzecinkowych
    int nominaly[12] = {50000,20000,10000,5000,2000,1000,500,200,100,50,20,10};
    
    //  Ten licznik[] istnieje aby zliczaj wszystkie banknoty i monety które zostały wydane
    int licznik[12] = {0};

    //  Zmienna reszta która działa jako aktualny stan reszty do wydania
    //  i aktualnyNominal który oznajmia aktualny nominał w tabeli nominaly.
    int reszta, aktualnyNominal = 0;

    //  Pobieranie reszty (w tym wypadku wpisana ręcznie)
    cout << "Reszta: " << endl;
    cin >> reszta;

    //  Wypisywanie reszty poprzez algorytm zachłanny np. 1220 -> 720 (1 = 500) -> 220 (2 = 500) -> 120 (2 = 500, 1 = 100) -> 20 (2 = 500, 2= 100) -> 10 (2 = 500, 2= 100, 1 = 10) -> (2 = 500, 2= 100, 2 = 10)
    while(reszta > 0){
        if(reszta >= nominaly[aktualnyNominal]){
            cout << nominaly[aktualnyNominal];
            reszta -= nominaly[aktualnyNominal];
        }else{
            aktualnyNominal++;
        }
    }

    cout << "Reszta wydana." << endl;

    return 0;
}