#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& numbers) {
    for (size_t i = 0; i + 1 < numbers.size(); ++i) {
        bool swapped = false;
        for (size_t j = 0; j + 1 < numbers.size() - i; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    constexpr size_t numberCount = 10000;
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(1, 100000);

    vector<int> numbers;
    numbers.reserve(numberCount);
    for (size_t i = 0; i < numberCount; ++i) {
        numbers.push_back(distribution(generator));
    }

    const auto start = chrono::steady_clock::now();
    bubbleSort(numbers);
    const auto end = chrono::steady_clock::now();

    if (!is_sorted(numbers.begin(), numbers.end())) {
        cerr << "Sorting failed.\n";
        return 1;
    }

    cout << "Sorted " << numbers.size() << " numbers.\n";
    cout << "Sorting time: "
         << chrono::duration<double, milli>(end - start).count()
         << " ms\n";

    return 0;
}