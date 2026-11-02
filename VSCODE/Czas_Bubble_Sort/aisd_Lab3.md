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
| Rok/Semestr | II/III |
| Grupa laboratoryjna | grupa 1 |
| Rok akademicki | 2026/2027 |
| Prowadzący | mgr inż. Artur Pelo |

## ![Piktogram informacje o zadaniu](https://img.icons8.com/color/48/info--v1.png) Informacje o zadaniu

| Pole | Wartość |
| --- | --- |
| Numer laboratorium | 3 |
| Temat laboratorium | Algorytmy i struktury danych |
| Data realizacji | 2026.11.2 |
| Data oddania | +7d |
| Język / technologia | CPP |
| Środowisko / narzędzie | VSC |

## ![Piktogram treść zadania](https://img.icons8.com/color/48/task.png) Treść zadania

Krótki opis zadania:

Algorytmy sortujące.
Napisz program implementujący sortowanie bąbelkowe (Bubble Sort) z optymalizacją.

## ![Piktogram wymagania funkcjonalne](https://img.icons8.com/color/48/checklist.png) Wymagania funkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WF-01 | Program implementuje algorytm sortowania bąbelkowego (bubble sort) z optymalizacją. | Wysoki |
| WF-02 | Program obsługuje wczytywanie tablicy liczb do posortowania. | Wysoki |
| WF-03 | Program wypisuje posortowaną tablicę na ekran. | Wysoki |
| WF-04 | Program oblicza i wypisuje złożoność obliczeniową (średnią, pesymistyczną, optymistyczną) oraz pamięciową algorytmu. | Wysoki |

## ![Piktogram wymagania niefunkcjonalne](https://img.icons8.com/color/48/inspection.png) Wymagania niefunkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WN-01 | Program kompiluje się bez błędów i ostrzeżeń kompilatora. | Wysoki |
| WN-02 | Kod źródłowy jest czytelny i odpowiednio skomentowany. | Wysoki |
| WN-03 | Implementacja jest zgodna z algorytmem sortowania bąbelkowego (bubble sort) z optymalizacją. | Średni |
| WN-04 | Program obsługuje różne przypadki brzegowe (pusta tablica, tablica z jednym elementem, tablica posortowana/odwrócona). | Średni |

## ![Piktogram realizacja zadania](https://img.icons8.com/color/48/workflow.png) Realizacja zadania

Opis implementacji:

CPP
```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

//  Bubble sort as function
void bubbleSort(vector<int>& v) {
    int n = v.size();

    // Outer loop that corresponds to the number of
    // elements to be sorted
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already
        // in place
        for (int j = 0; j < n - i - 1; j++) {
          
          	// Comparing adjacent elements
            if (v[j] > v[j + 1])
              
              	// Swapping if in the wrong order
                swap(v[j], v[j + 1]);
        }
    }
}

//  Safety checking function
bool is_digits(string& str)
{
    for (char ch : str) {
        if (!isdigit(ch)){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    //  Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist100000(1, 100000);

    //  User chosen amount of numbers to sort with safety
    string numbersString;
    int numbers;
    cout << "Podaj ilosc liczb do posortowania" <<endl;
    cin>>numbersString;
    if(!is_digits(numbersString)){cout<<"Bad input"; return 0;}else{
        numbers = stoi(numbersString);
    }

    //  Check for autoinput or user input
    cout << "Wpisane recznie czy losowe liczby? (R/L)" <<endl;
    string handholding;
    while(true){
        cin>>handholding;
        if(handholding == "R" || handholding == "L"){
            break;
        }
    }

    //  Vector array for numbers
    vector<int> numbersArray;

    //  User input numbers
    if(handholding == "R"){
        string userinput;
        for(int i = 0; i < numbers; i++){
            cout << "Numer " << i+1 << ":";
            cin>>userinput;
            if(is_digits(userinput)){
                numbersArray.push_back(stoi(userinput));
            }
        }
    }else if(handholding == "L"){
        //  Autogenerated numbers
        for(int i = 0; i < numbers; i++){
            numbersArray.push_back(dist100000(rng));
        }
    }
    
/*
    //  Display unsorted data
    cout << "Unsorted: " <<endl;
    for(auto v : numbersArray){
        cout << v << endl;
    }
*/

    //  Starting time for sorting algorithm
    auto start = chrono::high_resolution_clock::now();

    //  Call to sort function
    bubbleSort(numbersArray);

    //  Ending time for sorting algorithm
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    //  Display sorted data
    cout << "Sorted: " <<endl;
    for(auto v : numbersArray){
        cout << v << endl;
    }
    
    cout << "Algorytm sortowania babelkowego zajal: " << ms << " milisekund."<<endl;
    cout << "Zlozonosc obliczleniowa optymistyczna to O(n)." << endl;
    cout << "Zlozonosc obliczleniowa srednia to O((n^2)/2)." << endl;
    cout << "Zlozonosc obliczleniowa pesymistyczna to O((n^2)/2)." << endl;
    cout << "Zlozonosc pamieciowa to O(1)" << endl;

    return 0;
}


```

## ![Piktogram samoocena](https://img.icons8.com/color/48/test-passed.png) Samoocena studenta

| Kryterium | Tak / Nie | Uwagi |
| --- | --- | --- |
| Program implementuje algorytm sortowania bąbelkowego (bubble sort) z optymalizacją | Tak |  |
| Program poprawnie sortuje tablicę liczb | Tak |  |
| Program wypisuje złożoność obliczeniową (średnią, pesymistyczną, optymistyczną) | Tak |  |
| Program jest zgodny z optymalizacją algorytmu sortowania bąbelkowego | Tak |  |
| Program obsługuje wczytywanie danych do posortowania | Tak |  |
| Kod jest czytelny i odpowiednio sformatowany | Tak |  |

## Przesłanie pliku do oceny:

[![Upload ZIP](https://img.shields.io/badge/Upload-AISD_KowalskiJan_Lab0.zip-2ea44f?logo=icloud&logoColor=white)](https://upload2.pelo.com.pl) [zawartość, uzupełniony TEN plik w poderze LAB3 z plikami źródłowymi]

## ![Piktogram ocena prowadzącego](https://img.icons8.com/color/48/approval.png) Ocena prowadzącego

ocena: ................................................................

Uwagi prowadzącego:

................................................................................

................................................................................

Podpis prowadzącego: ........................................................