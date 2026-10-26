#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Student{
    private: 
        string name;
        int age;
    public:
        Student(string name, int age){
            this->name = name;
            this->age = age;
        }
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        
};