// Create an abstract base class Shape with a pure virtual function area().
// Derive two classes Circle and Rectangle. Implement the area() function for both classes
// and calculate the area of a circle and a rectangle.

#include <iostream>
using namespace std;

class Shape
{
protected:
    int area;

public:
    virtual void print() {}
};

class Circle : public Shape
{

public:
    int area;
    void print()
    {
        cout << "Area of the circle is: " << area << endl;
    }
};

class Rectangle : public Shape
{
public:
    int area;
    void print()
    {
        cout << "Area of the Rectangle is: " << area << endl;
    }
};

int main()
{
    Shape *ptr[2];

    Circle C1;
    C1.area = 10;
    Rectangle R1;
    R1.area = 20;
    ptr[0] = &C1;
    ptr[1] = &R1;
    ptr[0]->print();
    ptr[1]->print();
    // delete[] ptr;
}
