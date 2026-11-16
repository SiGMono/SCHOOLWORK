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
        return (x.value / x.weight) < (y.value / y.weight); 
    }
};

//  Backpack algorithm with infinite item amounts
int main(){
    vector<Item> items;

    do{
        cout << "1 - Add item" <<endl;
        cout << "2 - Calculate optimal backpack" <<endl;
        string choice = "MTY";
        cin >> choice;
        if(choice == "1"){
            Item thisItem;
            while(true){
                string name, value, weight;
                cout << "Name: ";
                cin >> name;
                cout << "value: ";
                cin >> value;
                cout << "weight: ";
                cin >> weight;

                if(is_digits(value) == true && is_digits(weight) == true){
                    thisItem.name = name;
                    thisItem.value = stoi(value);
                    thisItem.value = stoi(weight);
                    items.push_back(thisItem);
                    break;
                }else{
                    cout << "Bad input, please try again." <<endl;
                }
            }
        }else if(choice == "2"){
            break;
        }else{
            cout << "Bad input, try again." <<endl;
        }
    }
    while(true);

    sort(items.begin(), items.end(), sortingFunctor());

    cout << "Maximum bag weight: ";
    string bagWeight;
    while(true){
        cin >> bagWeight;
        if(is_digits(bagWeight)){
            int bagWeightInt = stoi(bagWeight);
            int begginingPoint; //  A point of beggining for a binary division optimisation
            //  The optimisation of the point at which to begin filling the backpack
            //  In case of small items vector sizes the difference in computing time is negligible but assuming items is going to number in thousands
            //  this piece of code can potencially cut the backpack filling time significantly (this works due to the fact this vector is already sorted)
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

            for(int i = begginingPoint; i < items.size(); i++){
                int count = 0;
                while(items[i].weight < bagWeightInt){
                    bagWeightInt -= items[i].weight;
                    count++;
                }
                cout << count << " of " << items[i].name <<endl;
                count = 0;
            }
            break;
        }else{
            cout << "Bad input, please try again." <<endl;
        }
    }

    return 0;
}