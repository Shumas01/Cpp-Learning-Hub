
#include <iostream>
#include <cstring> // For strcpy
using namespace std;

class Person {
protected:
    char name[50];
    int age;

public:
    // Default constructor
    Person() {
        cout << "Person constructor called." << endl;
        strcpy(name, "Default Name");
        age = 0;
    }

    // Parameterized constructor (optional for testing)
    Person(const char* name, int age) {
        cout << "Person parameterized constructor called." << endl;
        strcpy(this->name, name);
        this->age = age;
    }

    // Display function
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
public:
    // Default constructor
    Student() {
        cout << "Student constructor called." << endl;
    }
};

class Teacher : public Person {
public:
    // Default constructor
    Teacher() {
        cout << "Teacher constructor called." << endl;
    }
};

class TA : public Student, public Teacher {
public:
    // Default constructor
    TA() {
        cout << "TA constructor called." << endl;
    }

    // Resolve ambiguity when calling Person::display()
    void display() {
        cout << "Calling Person::display from Student base:" << endl;
        Student::display();
        cout << "Calling Person::display from Teacher base:" << endl;
        Teacher::display();
    }
};

int main() {
    // Create an object of TA
    TA ta;

    // Observe the constructor call order
    cout << "\nOrder of constructor calls observed above.\n" << endl;

    // Call base class display() and handle ambiguity
    cout << "Displaying attributes using scope resolution:" << endl;
    ta.display();

    return 0;
}
