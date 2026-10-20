# Zadanie laboratoryjne

[![Java Documentation](https://img.shields.io/badge/Dokumentacja-Java-ED8B00?logo=java&logoColor=white)](https://docs.oracle.com/en/java/)
[![C++ Documentation](https://img.shields.io/badge/Dokumentacja-C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/w/)
[![Visual Studio](https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?logo=visual-studio&logoColor=white)](https://visualstudio.microsoft.com/)
[![VS Code](https://img.shields.io/badge/IDE-VS%20Code-007ACC?logo=visualstudiocode&logoColor=white)](https://code.visualstudio.com/)
[![CLion](https://img.shields.io/badge/IDE-CLion-000000?logo=jetbrains&logoColor=white)](https://www.jetbrains.com/clion/)
[![IntelliJ IDEA](https://img.shields.io/badge/IDE-IntelliJ%20IDEA-000000?logo=jetbrains&logoColor=white)](https://www.jetbrains.com/idea/)
[![GitHub Markdown](https://img.shields.io/badge/Format-GitHub%20Markdown-181717?logo=github&logoColor=white)](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

**Przedmiot:** _Algorytmy i struktury danych_  

## ![Piktogram dane studenta](https://img.icons8.com/color/48/student-male--v1.png) Dane studenta

| Pole | Wartość |
| --- | --- |
| Imię i nazwisko | Szymon Zeller |
| Numer albumu | 10149 |
| Kierunek / specjalność | Informatyka |
| Rok/Semestr | II |
| Grupa laboratoryjna | grupa 1 |
| Rok akademicki | 2026/2027 |
| Prowadzący | mgr inż. Artur Pelo |

## ![Piktogram informacje o zadaniu](https://img.icons8.com/color/48/info--v1.png) Informacje o zadaniu

| Pole | Wartość |
| --- | --- |
| Numer laboratorium | 1 |
| Temat laboratorium | Algorytmy i struktury danych |
| Data realizacji | 19.10.2026 |
| Data oddania | +7d |
| Język / technologia | CPP |
| Środowisko / narzędzie | VSC |

## ![Piktogram tresc zadania](https://img.icons8.com/color/48/task.png) Treść zadania

Krótki opis zadania:

Tworzenie programów realizujących znane algorytmy.<br>
Algorytmy zachłanne: Rozwiązywanie problemów optymalizacyjnych z podejściem lokalnie optymalnym - problem wydawania reszty.

## ![Piktogram wymagania funkcjonalne](https://img.icons8.com/color/48/checklist.png) Wymagania funkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WF-01 | Program implementuje algorytm wydawania reszty. | Wysoki |
| WF-02 | Program obsługuje wczytywanie tablicy danych. | Wysoki |
| WF-03 | Program wypisuje zawartość tablicy po przetworzeniu. | Wysoki |
| WF-04 | Program oblicza resztę metodą zachłanną. | Wysoki |

## ![Piktogram wymagania niefunkcjonalne](https://img.icons8.com/color/48/inspection.png) Wymagania niefunkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WN-01 | Program kompiluje się bez błędów i ostrzeżeń kompilatora. | Wysoki |
| WN-02 | Kod źródłowy jest czytelny i odpowiednio skomentowany. | Wysoki |
| WN-03 | Implementacja jest zgodna z algorytmem zachłannym (greedy). | Średni |
| WN-04 | Program obsługuje różne przypadki brzegowe (pusta tablica, tablica z jednym elementem). | Średni |

## ![Piktogram realizacja zadania](https://img.icons8.com/color/48/workflow.png) Realizacja zadania

Opis implementacji:

CPP
```cpp
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
    //  Sprawdzanie czy nie ma wartosci zbyt duzych
    if(resztazlotyS.length() > 9){
        cout << "Wprowadzona wartosc jest zbyt duza, zamykanie programu...";
        return 0;
    }
    //  Sprawdzanie czy wartość jest pusta
    if(resztazlotyS.empty()){
        cout << "Wprowadzona wartosc jest pusta, zamykanie programu...";
        return 0;
    }
    //  Konwersja string do int
    resztazloty = stoi(resztazlotyS);

    //  Pobieranie reszty groszy
    cout << "Reszta groszy:" <<endl;
    cin >> resztagroszS;
    //  Sprawdzanie czy nie ma wartosci nienymerycznych
    if(!is_digits(resztagroszS)){
        cout << "Wykryto wartosc nienumeryczna, zamykanie programu...";
        return 0;
    }
    if(resztagroszS.length() > 2){
        cout << "Wprowadzona wartosc jest zbyt duza, zamykanie programu...";
        return 0;
    }
    if(resztagroszS.empty()){
        cout << "Wprowadzona wartosc jest pusta, zamykanie programu...";
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
    while(reszta > 0){
        if(reszta >= nominaly[aktualnyNominal]){
            licznik[aktualnyNominal]++;
            reszta -= nominaly[aktualnyNominal];
        }else{
            aktualnyNominal++;
        }
    }

    //  Cout dla oddzielenia w cmd/terminal
    cout<<endl;

    //  Wyświetlanie rozdzielonej reszty
    for(int i = 0; i < 15; i++){
        if(licznik[i] != 0){
            if(i < 9){
                cout << "Zloty: " << nominaly[i] / 100 << " Ilosc: " << licznik[i] <<endl;
            }else{
                cout << "Grosz: " << nominaly[i] << " Ilosc: " << licznik[i] <<endl;
            }
        }
    }

    cout << "\nReszta wydana." << endl;

    return 0;
}
```

## ![Piktogram samoocena](https://img.icons8.com/color/48/test-passed.png) Samoocena studenta

| Kryterium | Tak / Nie | Uwagi |
| --- | --- | --- |
| Program implementuje algorytm zachłanny | Tak |  |
| Program poprawnie dobiera (nominały) elementy | Tak |  |
| Program wypisuje wynik | Tak |  |
| Program  wykonuje się poprawnie | Tak |  |
| Program obsługuje wczytywanie danych | Tak |  |
| Kod jest czytelny i odpowiednio sformatowany | Tak |  |

## Przesłanie pliku do oceny:

[![Upload ZIP](https://img.shields.io/badge/Upload-AISD_KowalskiJan_Lab1.zip-2ea44f?logo=icloud&logoColor=white)](https://upload2.pelo.com.pl) [zawartość, uzupełniony TEN plik w poderze LAB1 z plikami źródłowymi]

## ![Piktogram ocena prowadzacego](https://img.icons8.com/color/48/approval.png) Ocena prowadzącego

ocena: ................................................................

Uwagi prowadzącego:

................................................................................

................................................................................

Podpis prowadzącego: ........................................................