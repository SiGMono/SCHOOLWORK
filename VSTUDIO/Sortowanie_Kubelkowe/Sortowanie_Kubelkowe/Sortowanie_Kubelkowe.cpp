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
