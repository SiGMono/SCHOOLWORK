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

int main(int argc, char const *argv[])
{
    //  Random number generator
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist100000(1, 100000);

    int numbers;
    cout<<"Podaj ilosc liczb do posortowania"<<endl;
    cin>>numbers;

    for(int i = 0; i < numbers; i++){

    }

    return 0;
}
