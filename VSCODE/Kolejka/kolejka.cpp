#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// Stores the name and age of one student.
class Student{
    private: 
        string name;
        int age;
    public:
        // Initializes a student with the supplied name and age.
        Student(string name, int age){
            this->name = name;
            this->age = age;
        }

        // Returns the student's name.
        string getName(){
            return name;
        }

        // Returns the student's age.
        int getAge(){
            return age;
        }  
};

// A first-in, first-out queue of students.
class StudentsQueue{
    private:
        vector<Student> queue;
    public:
        // Adds a student to the back of the queue.
        void enqueue(Student student){
            queue.push_back(student);
        }

        // Removes and returns the student at the front of the queue.
        // Throws a runtime_error if the queue has no students.
        Student dequeue(){
            if(queue.empty()){
                throw runtime_error("Queue is empty");
            }
            Student student = queue.front();
            queue.erase(queue.begin());
            return student;
        }

        // Reports whether the queue contains no students.
        bool isEmpty(){
            return queue.empty();
        }

        // Serializes the students currently in the queue as a JSON array.
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

// Demonstrates adding students, printing the queue as JSON, and dequeuing them.
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