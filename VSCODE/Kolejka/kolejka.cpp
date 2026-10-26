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
        string getJSON(){
            string json = "[";
            for(int i = 0; i < queue.size(); i++){
                json += "{";
                json += "\"name\":\"" + queue[i].getName() + "\",";
                json += "\"age\":" + to_string(queue[i].getAge());
                json += "}";
                if(i != queue.size() - 1){
                    json += ",";
                }
            }
            json += "]";
            return json;
        }
};

int main(){
    StudentsQueue queue;
    queue.enqueue(Student("John", 20));
    queue.enqueue(Student("Jane", 22));
    queue.enqueue(Student("Bob", 19));

    cout << "Queue in JSON format: " << queue.getJSON() << endl;

    while(!queue.isEmpty()){
        Student student = queue.dequeue();
        cout << "Dequeued student: " << student.getName() << ", Age: " << student.getAge() << endl;
    }

    return 0;
}