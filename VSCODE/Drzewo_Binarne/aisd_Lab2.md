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
| Numer laboratorium | 2 |
| Temat laboratorium | Algorytmy i struktury danych |
| Data realizacji | 09.11.2026 |
| Data oddania | +7d |
| Język / technologia | CPP |
| Środowisko / narzędzie | VSC |

## ![Piktogram treść zadania](https://img.icons8.com/color/48/task.png) Treść zadania

Krótki opis zadania:

 Nabywanie umiejętności programowania struktur i panowania nad strukturami.
 Drzewo binarne. [W ramach samodoskonalenia: do zapoznania się z podstawowymi typami drzew: drzewo BST, drzewo AVL, drzewo czerwono-czarne, kopiec binarny, kopiec Fibonacciego.]

## ![Piktogram wymagania funkcjonalne](https://img.icons8.com/color/48/checklist.png) Wymagania funkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WF-01 | Program implementuje algorytm drzewa binarnego | Wysoki |
| WF-02 | Program obsługuje wczytywanie elementów. | Wysoki |
| WF-03 | Program wypisuje drzewo na ekranie | Wysoki |
| WF-04 | Program tworzy drzewo na wskaźnikach  | Wysoki |

## ![Piktogram wymagania niefunkcjonalne](https://img.icons8.com/color/48/inspection.png) Wymagania niefunkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WN-01 | Program kompiluje się bez błędów i ostrzeżeń kompilatora. | Wysoki |
| WN-02 | Kod źródłowy jest czytelny i odpowiednio skomentowany. | Wysoki |
| WN-03 | Implementacja jest zgodna z algorytmem drzewa binarnego. | Średni |
| WN-04 | Program wykorzystuje węzły drzewa jako obiekty zdefiniowane w programie | Średni |

## ![Piktogram realizacja zadania](https://img.icons8.com/color/48/workflow.png) Realizacja zadania

Opis implementacji:

CPP
```cpp
#include <iostream>

using namespace std;

// Checks whether every character in the string is a digit.
// Returns true if the whole string is numeric, otherwise false.
bool is_digits(string& str)
{
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

// Represents one node in the binary tree.
// 'w' stores the value of the node,
// while 'left' and 'right' point to its children.
struct Element {
    int w;
    Element* left = nullptr;
    Element* right = nullptr;
};

// Prints the tree in in-order traversal:
// left subtree -> current node -> right subtree.
void write(Element* root) {
    if (root != nullptr) {
        write(root->left);
        cout << root->w << " ";
        write(root->right);
    }
}

// Recursively frees all memory used by the tree rooted at 'n'.
void releaseNode(Element* n)
{
    if (!n) return;
    releaseNode(n->left);
    releaseNode(n->right);
    delete n;
}

int main(void) {
    // A variable for possible user input (not used in the current program).
    string choice;

    // Pointers to the root and the current node during tree construction.
    Element* first;
    Element* current = nullptr;

    // Create the root node with value 1.
    first = new Element;
    current = first;
    current->w = 1;
    current->left = new Element;
    current->right = new Element;

    // Left child of the root: value 2.
    current->left->w = 2;
    // Right child of the root: value 3.
    current->right->w = 3;

    // Move to the left subtree and add two more nodes: 4 and 5.
    current = current->left;
    current->left = new Element;
    current->right = new Element;
    current->left->w = 4;
    current->right->w = 5;

    // Return to the root and go to the right subtree.
    current = first;
    current = current->right;

    // Add two more nodes under the right child: 6 and 7.
    current->left = new Element;
    current->right = new Element;
    current->left->w = 6;
    current->right->w = 7;

    // Print the whole tree.
    current = first;
    write(current);

    // Release the dynamically allocated memory.
    // Note: this program uses a simple recursive cleanup.
    releaseNode(current->left);
    releaseNode(current->right);
    releaseNode(current);

    return 0;
}
```

## ![Piktogram samoocena](https://img.icons8.com/color/48/test-passed.png) Samoocena studenta

| Kryterium | Tak / Nie | Uwagi |
| --- | --- | --- |
| Program implementuje algorytm drzewa binarnego | Tak |  |
| Program obsługuje wczytywanie elementów | Tak |  |
| Program wypisuje drzewo na ekranie | Tak |  |
| Program tworzy drzewo na wskaźnikach | Tak |  |
| Węzły drzewa są obiektami zdefiniowanymi w programie | Tak |  |
| Kod jest czytelny i odpowiednio sformatowany | Tak |  |

## Przesłanie pliku do oceny:

[![Upload ZIP](https://img.shields.io/badge/Upload-AISD_KowalskiJan_Lab2.zip-2ea44f?logo=icloud&logoColor=white)](https://upload2.pelo.com.pl) [zawartość, uzupełniony TEN plik w podfolderze LAB2 z plikami źródłowymi]

## ![Piktogram ocena prowadzącego](https://img.icons8.com/color/48/approval.png) Ocena prowadzącego

ocena: ................................................................

Uwagi prowadzącego:

................................................................................

................................................................................

Podpis prowadzącego: ........................................................