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

class StudentsQueue{
    private:
        vector<Student> queue;
    public:
        void enqueue(Student student){
            queue.push_back(student);
        }
        Student dequeue(){
            if(queue.empty()){
                throw runtime_error("Queue is empty");
            }
            Student student = queue.front();
            queue.erase(queue.begin());
            return student;
        }
        bool isEmpty(){
            return queue.empty();
        }
};