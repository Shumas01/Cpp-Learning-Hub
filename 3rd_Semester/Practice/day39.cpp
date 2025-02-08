// Question 1: Basic Virtual Function
// Create a base class Animal with a virtual function sound() that prints "Animal makes a sound".
// Derive two classes, Dog and Cat, that override the sound() function to print "Dog barks" and "Cat meows" respectively.
// Write a program to call the sound() function using base class pointers.

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void print()
    {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void print()
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:
    void print()
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    // Animal A1;
    // A1.print();

    Animal *animal;
    Dog D1;
    Cat C1;
    animal = &D1;
    animal->print();
    animal = &C1;
    animal->print();
}
