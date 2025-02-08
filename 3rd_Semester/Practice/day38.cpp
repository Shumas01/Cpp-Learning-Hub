#include<iostream>
using namespace std;

class Animal
{
    public:
    void Display()
    {
        cout<<"Animal class Displaying"<<endl;
    }

};

class Cat: public Animal
{
public:
    void Display()
    {
        cout<<"Cat is Displaying"<<endl;

    }

};

class Dog: public Animal
{
public:
    void Display()
    {
        cout<<"Dog is Displaying"<<endl;
    }

};
int main ()
{
    Animal *Aptr;
    Cat C1;
    Aptr =&C1;
    Aptr->Display();
}