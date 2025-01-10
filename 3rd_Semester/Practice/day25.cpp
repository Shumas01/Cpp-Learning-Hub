// Example 1: Copy Constructor for a Basic Class
// Problem Statement: Create a class Point with two data members x and y.
// Write a copy constructor that copies the values from one Point object to another.

#include <iostream>
using namespace std;

class Number
{
    int x, y;

public:
    Number()
    {
        x = 0;
        y = 0;
    }
    Number(int num1, int num2)
    {
        x = num1;
        y = num2;
    }
    Number(const Number &obj)
    {
        cout << "Copy constructor calling" << endl;
        x = obj.x;
        y = obj.y;
    }
    void Display()
    {
        cout << "Ur number x and y is: (" << x << "," << y <<")"<< endl;
    }
};
int main()
{
    Number obj1;
    obj1.Display();
    Number obj2(4, 7);
    obj2.Display();
    Number obj3(obj2);
    obj3.Display();
}