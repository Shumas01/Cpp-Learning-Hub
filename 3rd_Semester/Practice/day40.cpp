#include<iostream>
using namespace std;

class Engine{
    public: 
        virtual void Display(){
            cout<<"Engine Base Class"<<endl;

        }

};

class Car: public Engine{
    public: 
        virtual void Display (){
            cout<<"Car is calling"<<endl;
        }
};

class Bike: public Car{
    public:
        void Display (){
            cout<<"Bike class is Calling"<<endl;
        }
};

int main ()
{
    // Engine *Eptr;
    Bike B1;
    // Eptr=&B1;
    // // Eptr->Display();
    // Car C1;
    // Eptr=&C1;
    // Eptr->Display();
    Engine E1;
    Car *Cptr;
    Cptr=&B1;
    Cptr->Display();
    // Cptr=&E1; 
}