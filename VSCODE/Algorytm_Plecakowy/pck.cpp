#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_digits(string& str)
{
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

struct Item{
    string name;
    int value, weight;
};

struct sortingFunctor{
    bool operator()(const Item& x, const Item& y) const
    {
        return x.value / x.weight < y.value / y.weight; 
    }
};

//  Backpack algorithm with infinite item amounts
int main(){
    vector<Item> items;

    do{
        cout << "1 - Add item \n 2 - Calculate optimal backpack" <<endl;
        string choice = "MTY";
        cin >> choice;
        if(is_digits(choice) && choice.compare("1")){
            Item thisItem;
            while(true){
                string name, value, weight;
                cout << "Name: ";
                cin >> name;
                cout << "value: ";
                cin >> value;
                cout << "weight: ";
                cin >> weight;

                if(is_digits(value) && is_digits(weight)){
                    thisItem.name = name;
                    thisItem.value = stoi(value);
                    thisItem.value = stoi(weight);
                    items.push_back(thisItem);
                    break;
                }else{
                    cout << "Bad input, please try again." <<endl;
                }
            }
        }else if(is_digits(choice) && choice.compare("2")){
            break;
        }else{
            cout << "Bad input, try again." <<endl;
        }
    }
    while(true);

    sort(items.begin(), items.end(), sortingFunctor());

    return 0;
}