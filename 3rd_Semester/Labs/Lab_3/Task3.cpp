
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

    // Parameterized constructor
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

class Student : virtual public Person {
public:
    // Default constructor
    Student() {
        cout << "Student constructor called." << endl;
    }

    // Parameterized constructor
    Student(const char* name, int age) : Person(name, age) {
        cout << "Student parameterized constructor called." << endl;
    }
};

class Teacher : virtual public Person {
public:
    // Default constructor
    Teacher() {
        cout << "Teacher constructor called." << endl;
    }

    // Parameterized constructor
    Teacher(const char* name, int age) : Person(name, age) {
        cout << "Teacher parameterized constructor called." << endl;
    }
};

class TA : public Student, public Teacher {
public:
    // Default constructor
    TA() {
        cout << "TA constructor called." << endl;
    }

    // Parameterized constructor
    TA(const char* name, int age) : Person(name, age), Student(name, age), Teacher(name, age) {
        cout << "TA parameterized constructor called." << endl;
    }
};

int main() {
    // Create an object of TA using default constructor
    cout << "Creating TA object using default constructor:" << endl;
    TA ta1;

    // Create an object of TA using parameterized constructor
    cout << "\nCreating TA object using parameterized constructor:" << endl;
    TA ta2("John Doe", 25);

    // Call display() function
    cout << "\nDisplaying attributes of TA object:" << endl;
    ta2.display();

    return 0;
}
