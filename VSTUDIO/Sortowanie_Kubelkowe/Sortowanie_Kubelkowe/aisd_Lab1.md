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
| Numer laboratorium | 0 |
| Temat laboratorium | Algorytmy i struktury danych |
| Data realizacji | 12.10.2026 |
| Data oddania | nd. |
| Język / technologia | CPP |
| Środowisko / narzędzie | VS |

## ![Piktogram tresc zadania](https://img.icons8.com/color/48/task.png) Treść zadania

Krótki opis zadania:

Napisz program realizujący algorytm sortowania kubełkowego. Podaj przykład zastosowania w praktyce, oraz złożoność obliczeniową średnią, pesymistyczną i optymisstyczną oraz złożonośc pamięciową.

## ![Piktogram wymagania funkcjonalne](https://img.icons8.com/color/48/checklist.png) Wymagania funkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WF-01 | Program implementuje algorytm sortowania kubełkowego (bucket sort). | Wysoki |
| WF-02 | Program obsługuje wczytywanie tablicy liczb do posortowania. | Wysoki |
| WF-03 | Program wypisuje posortowaną tablicę na ekran. | Wysoki |
| WF-04 | Program oblicza i wypisuje złożoność obliczeniową (średnią, pesymistyczną, optymistyczną) oraz pamięciową algorytmu. | Wysoki |

## ![Piktogram wymagania niefunkcjonalne](https://img.icons8.com/color/48/inspection.png) Wymagania niefunkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WN-01 | Program kompiluje się bez błędów i ostrzeżeń kompilatora. | Wysoki |
| WN-02 | Kod źródłowy jest czytelny i odpowiednio skomentowany. | Wysoki |
| WN-03 | Implementacja jest zgodna z algorytmem sortowania kubełkowego (bucket sort). | Średni |
| WN-04 | Program obsługuje różne przypadki brzegowe (pusta tablica, tablica z jednym elementem, tablica posortowana/odwrócona). | Średni |

## ![Piktogram realizacja zadania](https://img.icons8.com/color/48/workflow.png) Realizacja zadania

Opis implementacji:

CPP
```cpp
	#include <iostream>

using namespace std;

int main()
{
    int tab[10];

	// Wczytywanie liczb od użytkownika
	for (int i = 0; i < 10; i++)
	{
		cout << "Podaj liczbe: ";
		cin >> tab[i];
	}

	// Sortowanie kubelkowe
	int sort[101];
	for (int i = 0; i < 101; i++)
	{
		sort[i] = 0;
	}

	// Zliczanie wystąpień każdej liczby
	for (int i = 0; i < 10; i++)
	{
		sort[tab[i]]++;
	}

	// Wyświetlanie posortowanych liczb
	for (int i = 0; i < 101; i++)
	{
		if (sort[i] > 0)
		{
			for (int j = 0; j < sort[i]; j++)
			{
				cout << i << " ";
			}
		}
	}
}

```

## ![Piktogram samoocena](https://img.icons8.com/color/48/test-passed.png) Samoocena studenta

| Kryterium | Tak / Nie | Uwagi |
| --- | --- | --- |
| Program implementuje algorytm sortowania kubełkowego | Tak |  |
| Program poprawnie sortuje tablicę liczb | Tak |  |
| Program wypisuje złożoność obliczeniową (średnią, pesymistyczną, optymistyczną) | Tak |  |
| Program wypisuje złożoność pamięciową algorytmu | Tak |  |
| Program obsługuje wczytywanie danych do posortowania | Tak |  |
| Kod jest czytelny i odpowiednio sformatowany | Tak |  |

## Przesłanie pliku do oceny:

[![Upload ZIP](https://img.shields.io/badge/Upload-AISD_KowalskiJan_Lab0.zip-2ea44f?logo=icloud&logoColor=white)](https://upload2.pelo.com.pl) [zawartość, uzupełniony TEN plik oraz podfolder LAB0 z plikami źródłowymi]

## ![Piktogram ocena prowadzacego](https://img.icons8.com/color/48/approval.png) Ocena prowadzącego

ocena: ................................................................

Uwagi prowadzącego:

................................................................................

................................................................................

Podpis prowadzącego: ........................................................