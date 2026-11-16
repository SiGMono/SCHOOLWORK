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
| Numer laboratorium | 4 |
| Temat laboratorium | Implementacja algorytmiczna struktur grafu.  Problemy NP zupełne. |
| Data realizacji | 16.11.2026 |
| Data oddania | +7d |
| Język / technologia | CPP |
| Środowisko / narzędzie | VSC |

## ![Piktogram treść zadania](https://img.icons8.com/color/48/task.png) Treść zadania

Krótki opis zadania:

Implementacja algorytmiczna struktur grafu. Problemy NP zupełne.
Napisz program, który rozwiązuje wybrane problemy NP zupełne - problem plecakowy. 
Program powinien umożliwiać wczytywanie danych z terminala lub GUI.

## ![Piktogram wymagania funkcjonalne](https://img.icons8.com/color/48/checklist.png) Wymagania funkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WF-01 | Program implementuje algorytm plecakowy | Wysoki |
| WF-02 | Program obsługuje wczytywanie liczb z klawiatury | Wysoki |
| WF-03 | Program wypisuje zawartość plecaka. | Wysoki |
| WF-04 | Program działa możliwie jak najszybciej. | Średni |

## ![Piktogram wymagania niefunkcjonalne](https://img.icons8.com/color/48/inspection.png) Wymagania niefunkcjonalne

| ID | Opis wymagania | Poziom |
| --- | --- | --- |
| WN-01 | Program kompiluje się bez błędów i ostrzeżeń kompilatora. | Wysoki |
| WN-02 | Kod źródłowy jest czytelny i odpowiednio skomentowany. | Wysoki |
| WN-03 | Implementacja jest zgodna z algorytmem plecakowym. | Średni |
| WN-04 | Program obsługuje różne przypadki brzegowe (np. pusty plecak, plecak z jednym przedmiotem) | Średni |

## ![Piktogram realizacja zadania](https://img.icons8.com/color/48/workflow.png) Realizacja zadania

Opis implementacji:

CPP
```cpp
    #include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Checks whether a string contains only digits (for example, "123" but not "12a").
// This is used to validate numeric user input before converting it to int.
bool is_digits(string& str)
{
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

// Represents one object available for the backpack.
// Each item has a label, a profit/value, and a weight/capacity cost.
struct Item{
    string name;
    int value, weight;
    
    Item(string name, int value, int weight){
        this->name = name;
        this->value = value;
        this->weight = weight;
    }
};

// A predefined collection of items that can be loaded instantly by the user.
// This simulates a ready-made inventory for testing the backpack logic.
vector<Item> staticItems = {
    Item("Gold necklace", 8500, 1),
    Item("Silver necklace", 900, 1),
    Item("Diamond ring", 12000, 1),
    Item("Ruby ring", 7600, 1),
    Item("Emerald ring", 8100, 1),
    Item("Sapphire ring", 6900, 1),
    Item("Pearl earrings", 2400, 1),
    Item("Diamond earrings", 9800, 1),
    Item("Gold bracelet", 5200, 1),
    Item("Silver bracelet", 650, 1),
    Item("Platinum watch", 14500, 1),
    Item("Luxury watch", 11000, 1),
    Item("Antique pocket watch", 4300, 1),
    Item("Gold coin", 2200, 1),
    Item("Silver coin collection", 1800, 2),
    Item("Rare stamp album", 3600, 2),
    Item("Vintage comic book", 1200, 1),
    Item("First edition novel", 2700, 1),
    Item("Signed first edition", 6400, 2),
    Item("Antique map", 3900, 2),
    Item("Oil painting", 18000, 8),
    Item("Watercolor painting", 4200, 2),
    Item("Bronze sculpture", 5700, 6),
    Item("Marble statuette", 3100, 5),
    Item("Porcelain vase", 2600, 3),
    Item("Antique clock", 4800, 7),
    Item("Crystal chandelier", 9200, 12),
    Item("Vintage camera", 1900, 2),
    Item("Professional camera", 4200, 2),
    Item("Camera lens", 1600, 1),
    Item("Cinema camera", 9800, 5),
    Item("Laptop computer", 2100, 2),
    Item("Gaming laptop", 3200, 3),
    Item("Tablet computer", 900, 1),
    Item("Smartphone", 1100, 1),
    Item("Satellite phone", 1800, 1),
    Item("4K television", 2400, 9),
    Item("OLED television", 3900, 12),
    Item("Home theater projector", 2800, 4),
    Item("Stereo amplifier", 1300, 6),
    Item("Studio headphones", 450, 1),
    Item("Wireless earbuds", 220, 1),
    Item("Professional microphone", 700, 2),
    Item("Electric guitar", 1400, 4),
    Item("Vintage electric guitar", 5200, 5),
    Item("Acoustic guitar", 800, 3),
    Item("Grand piano", 24000, 280),
    Item("Digital piano", 1700, 15),
    Item("Violin", 2300, 1),
    Item("Antique violin", 12500, 1),
    Item("Cello", 4900, 4),
    Item("Trumpet", 850, 2),
    Item("Saxophone", 1900, 3),
    Item("Flute", 600, 1),
    Item("Drum kit", 1600, 25),
    Item("DJ controller", 1100, 5),
    Item("Vinyl record collection", 2800, 18),
    Item("Rare vinyl album", 950, 1),
    Item("Concert grand harp", 14500, 40),
    Item("Vintage radio", 1300, 6),
    Item("Diamond tiara", 32000, 2),
    Item("Gold crown", 27000, 4),
    Item("Silver serving set", 2100, 8),
    Item("Gold cutlery set", 6800, 5),
    Item("Antique tea set", 3400, 4),
    Item("Crystal glass set", 900, 3),
    Item("Handmade Persian rug", 5600, 20),
    Item("Antique tapestry", 7300, 15),
    Item("Designer handbag", 2400, 2),
    Item("Leather travel trunk", 1800, 8),
    Item("Luxury fountain pen", 1300, 1),
    Item("Gold fountain pen", 2900, 1),
    Item("Mechanical wristwatch", 6700, 1),
    Item("Diamond brooch", 8800, 1),
    Item("Opal pendant", 3500, 1),
    Item("Amber necklace", 1700, 1),
    Item("Jade figurine", 4100, 2),
    Item("Carved ivory replica", 1200, 1),
    Item("Meteorite fragment", 2200, 1),
    Item("Rare gemstone specimen", 5400, 2),
    Item("Raw diamond", 19500, 1),
    Item("Uncut emerald", 8600, 1),
    Item("Uncut ruby", 7900, 1),
    Item("Blue sapphire", 9200, 1),
    Item("Natural pearl", 1800, 1),
    Item("Gold bullion bar", 64000, 1000),
    Item("Silver bullion bar", 1500, 1000),
    Item("Platinum bullion bar", 32000, 1000),
    Item("Rare coin", 7800, 1),
    Item("Ancient coin collection", 14500, 3),
    Item("Commemorative medal", 650, 1),
    Item("Signed sports jersey", 2100, 1),
    Item("Championship trophy", 3600, 5),
    Item("Vintage baseball card", 4700, 1),
    Item("Rare trading card", 3900, 1),
    Item("Autographed basketball", 900, 1),
    Item("World Cup football", 750, 1),
    Item("Racing bicycle", 2800, 9),
    Item("Carbon road bike", 4300, 8),
    Item("Mountain bike", 1600, 14),
    Item("Electric bicycle", 2400, 24),
    Item("Professional telescope", 2500, 7),
    Item("Astronomy binoculars", 700, 2),
    Item("Night vision scope", 1300, 2),
    Item("Surveying equipment", 1900, 5),
    Item("Drone camera", 1200, 2),
    Item("Professional drone", 3600, 5),
    Item("Remote-control model aircraft", 850, 3),
    Item("Vintage model train set", 2200, 8),
    Item("Antique chess set", 3400, 4),
    Item("Hand-carved chess set", 1900, 3),
    Item("Rare board game", 1100, 2),
    Item("Collector action figure", 650, 1),
    Item("Vintage doll collection", 1800, 5),
    Item("Porcelain doll", 900, 2),
    Item("Limited-edition sculpture", 4800, 7),
    Item("Signed lithograph", 1600, 2),
    Item("Rare photographic print", 2100, 1),
    Item("Antique silver mirror", 2700, 6),
    Item("Decorative gold bowl", 5900, 3),
    Item("Hand-painted ceramic bowl", 750, 2),
    Item("Antique samovar", 2300, 5),
    Item("Vintage perfume bottle", 1400, 1),
    Item("Luxury perfume collection", 900, 2),
    Item("Rare whiskey bottle", 1800, 2),
    Item("Vintage wine bottle", 1300, 2),
    Item("Aged wine collection", 7600, 24),
    Item("Champagne collection", 2400, 12),
    Item("Rare tea collection", 650, 3),
    Item("Antique spice chest", 1700, 7),
    Item("Fine leather briefcase", 1200, 2),
    Item("Designer suitcase", 1500, 4),
    Item("Luxury silk scarf", 500, 1),
    Item("Cashmere coat", 1100, 2),
    Item("Vintage fur coat", 2800, 4),
    Item("Diamond cufflinks", 6400, 1),
    Item("Gold cufflinks", 1900, 1),
    Item("Platinum tie pin", 1700, 1),
    Item("Antique pocket compass", 950, 1),
    Item("Brass sextant", 1600, 3),
    Item("Nautical spyglass", 800, 2),
    Item("Antique globe", 2100, 9),
    Item("Handmade Persian carpet", 8200, 30),
    Item("Rare antique book", 5500, 2),
    Item("Signed manuscript", 14500, 1),
    Item("Historic document", 9900, 1),
    Item("Antique religious icon", 3700, 2),
    Item("Gold-leaf religious icon", 6100, 3),
    Item("Ancient pottery vessel", 2600, 4),
    Item("Archaeological artifact replica", 850, 2),
    Item("Fossilized ammonite", 1200, 3),
    Item("Dinosaur fossil replica", 3100, 12),
    Item("Large quartz geode", 700, 8),
    Item("Rare mineral collection", 2400, 5),
    Item("Gold-handled walking cane", 1800, 2),
    Item("Antique riding saddle", 2200, 9),
    Item("Custom leather saddle", 1600, 8),
    Item("Vintage pocket calculator", 450, 1),
    Item("Mechanical typewriter", 900, 12),
    Item("Antique printing press", 4200, 80),
    Item("Industrial sewing machine", 1100, 18),
    Item("Vintage sewing machine", 750, 14),
    Item("Professional 3D printer", 2600, 22),
    Item("Laser engraving machine", 3900, 18),
    Item("Portable generator", 1700, 30),
    Item("Solar power station", 1300, 12),
    Item("High-end graphics card", 1500, 2),
    Item("Computer workstation", 3400, 18),
    Item("Server rack", 5200, 45),
    Item("Network storage array", 2200, 12),
    Item("Vintage arcade cabinet", 2800, 90),
    Item("Pinball machine", 4500, 110),
    Item("Foosball table", 900, 75),
    Item("Pool cue collection", 1300, 4),
    Item("Antique billiard table", 6200, 300),
    Item("Professional camera tripod", 350, 2),
    Item("Broadcast television camera", 7800, 14),
    Item("Film projector", 1200, 9),
    Item("Vintage movie poster", 850, 1),
    Item("Signed film memorabilia", 3900, 2),
    Item("Antique military uniform", 1800, 3),
    Item("Historic ceremonial armor", 9400, 25),
    Item("Decorative knight helmet", 1600, 4),
    Item("Antique shield", 2100, 8),
    Item("Collector pocketknife", 750, 1),
    Item("Hand-forged chef knife", 400, 1),
    Item("Damascus steel sword replica", 1900, 3),
    Item("Antique samurai sword replica", 2700, 4),
    Item("Custom hunting bow", 850, 2),
    Item("Handcrafted longbow", 1200, 3),
    Item("Professional fishing rod", 600, 1),
    Item("Vintage fishing reel", 950, 1),
    Item("Rare fly-fishing collection", 1500, 3),
    Item("Scuba diving equipment", 1900, 20),
    Item("Professional climbing gear", 1300, 12),
    Item("Expedition camping set", 900, 18),
    Item("High-end road bicycle wheelset", 2400, 3),
    Item("Carbon fiber kayak", 1800, 20),
    Item("Vintage surfboard", 1100, 8),
    Item("Antique ship model", 2300, 7),
    Item("Handcrafted ship-in-a-bottle", 700, 1),
    Item("Rare porcelain tea bowl", 2100, 1),
    Item("Antique lacquer box", 1800, 2),
    Item("Handmade jade seal", 4600, 1),
    Item("Gold-plated ceremonial mask", 7200, 5),
    Item("Traditional handwoven rug", 1900, 12),
    Item("Antique bronze incense burner", 2500, 4),
    Item("Rare limited-edition watch", 18500, 1),
    Item("Luxury diamond necklace", 26500, 2),
    Item("Platinum wedding band", 2200, 1),
    Item("Vintage designer sunglasses", 600, 1),
    Item("Signed limited-edition print", 3200, 2),
    Item("Antique writing desk", 3700, 55),
    Item("Hand-carved wooden cabinet", 2900, 40),
    Item("Vintage leather armchair", 1400, 28),
    Item("Antique dining chair", 650, 9),
    Item("Designer lounge chair", 1900, 22),
    Item("Handmade glass sculpture", 2300, 5),
    Item("Murano glass vase", 3100, 3),
    Item("Rare crystal decanter", 1250, 2),
    Item("Antique gold-inlaid box", 5800, 2),
    Item("Vintage silver cigarette case", 800, 1),
    Item("Collector fountain pen set", 2400, 2),
    Item("Antique calligraphy set", 1600, 1),
    Item("Rare botanical illustration", 2700, 1),
    Item("Signed sports memorabilia", 1750, 2),
    Item("Vintage racing helmet", 1400, 2),
    Item("Antique fireman's helmet", 950, 2),
    Item("Collector pocket radio", 500, 1),
    Item("Vintage handheld game console", 700, 1),
    Item("Limited-edition game console", 1100, 4),
    Item("Rare computer memory kit", 600, 1),
    Item("Professional audio mixer", 1800, 8),
    Item("Studio monitor speakers", 1200, 14),
    Item("Portable shortwave receiver", 650, 2),
    Item("Antique brass telescope", 1700, 5),
    Item("Rare meteorite specimen", 8400, 2),
    Item("Collector gemstone necklace", 5100, 1),
    Item("Gold pocket watch", 7400, 1),
    Item("Antique jeweled hair comb", 2600, 1),
    Item("Signed classic guitar", 8900, 4),
    Item("Vintage concert accordion", 1300, 7),
    Item("Handmade grand piano bench", 500, 8),
    Item("Antique silver candlesticks", 1350, 3),
    Item("Rare collector's edition book", 3300, 2)
};

// Sorts items by efficiency, measured as value per unit of weight.
// This is a greedy ordering used by the program; it does not guarantee an exact optimal solution
// for all knapsack variants, but it is suitable for the simple inventory-style task displayed here.
struct sortingFunctor{
    bool operator()(const Item& x, const Item& y) const
    {
        return (x.value / x.weight) < (y.value / y.weight); 
    }
};

// Main program entry point.
// The application lets the user either add a custom item, use a predefined item list,
// and then choose the maximum weight of a backpack to fill.
int main(){
    // The current working inventory of items for this run.
    vector<Item> items;

    // Menu loop: user chooses how to populate the item list.
    do{
        cout << "1 - Add item" <<endl;
        cout << "2 - Use static table of 200 objects" <<endl;
        cout << "3 - Calculate optimal backpack" <<endl;
        string choice = "MTY";
        cin >> choice;
        if(choice == "1"){
            while(true){
                string name, value, weight;
                cout << "Name: ";
                cin >> name;
                cout << "Value: ";
                cin >> value;
                cout << "Weight: ";
                cin >> weight;
                if(is_digits(value) == true && is_digits(weight) == true){
                    // Create and store a valid item only when both values are numeric.
                    Item thisItem(name, stoi(value), stoi(weight));
                    items.push_back(thisItem);
                    break;
                }else{
                    cout << "Bad input, please try again." <<endl;
                }
            }
        }else if(choice == "2"){
            // Replace the current list with the predefined catalog.
            items = staticItems;
            break;
        }else if(choice == "3"){
            // Proceed to the backpack calculation using the current inventory.
            break;
        }else{
            cout << "Bad input, try again." <<endl;
        }
    }while(true);

    // Order the items from weakest to strongest value-per-weight ratio.
    // This makes the following greedy fill logic easier to reason about.
    sort(items.begin(), items.end(), sortingFunctor());

    cout << "Maximum bag weight: ";
    string bagWeight;
    while(true){
        cin >> bagWeight;
        if(is_digits(bagWeight)){
            int bagWeightInt = stoi(bagWeight);
            int begginingPoint; // The index where the greedy fill process should begin.
            // This optimization attempts to skip unnecessary work by starting near the best-fit portion of the sorted list.
            // For small inventories, the performance gain is minor, but with thousands of items it can reduce the number of checks.
            do{
                int mid = 0;
                if(items[mid].weight > bagWeightInt){
                    break;
                }else{
                    begginingPoint = mid;
                }
                if(items.size()%2 == 0){
                    mid = (items.size() - mid) / 2 + 1;
                }else{
                    mid = (items.size() - mid) / 2;
                }     
            }while(true);

            // Fill the backpack greedily with items that fit in the remaining capacity.
            // Each selected item is counted as many times as possible until the remaining capacity is too small.
            for(int i = begginingPoint; i < items.size(); i++){
                int count = 0;
                while(items[i].weight < bagWeightInt){
                    bagWeightInt -= items[i].weight;
                    count++;
                }
                if(count > 0){
                    cout << count << " of " << items[i].name <<endl;
                    count = 0;
                }
            }
            break;
        }else{
            cout << "Bad input, please try again." <<endl;
        }
    }

    return 0;
}
```

## ![Piktogram samoocena](https://img.icons8.com/color/48/test-passed.png) Samoocena studenta

| Kryterium | Tak / Nie | Uwagi |
| --- | --- | --- |
| Program implementuje algorytm plecakowy | Tak |  |
| Program poprawnie rozwiązuje problem plecakowy | Tak |  |
| Program wypisuje zawartość plecaka | Tak |  |
| Program jest zgodny z optymalizacją algorytmu plecakowego | Tak |  |
| Program obsługuje wczytywanie danych do rozwiązania problemu plecakowego | Tak |  |
| Kod jest czytelny i odpowiednio sformatowany | Tak |  |

## Przesłanie pliku do oceny:

[![Upload ZIP](https://img.shields.io/badge/Upload-AISD_KowalskiJan_Lab4.zip-2ea44f?logo=icloud&logoColor=white)](https://upload2.pelo.com.pl) [zawartość, uzupełniony TEN plik w podfolderze LAB4 z plikami źródłowymi]

## ![Piktogram ocena prowadzącego](https://img.icons8.com/color/48/approval.png) Ocena prowadzącego

ocena: ................................................................

Uwagi prowadzącego:

................................................................................

................................................................................

Podpis prowadzącego: ........................................................