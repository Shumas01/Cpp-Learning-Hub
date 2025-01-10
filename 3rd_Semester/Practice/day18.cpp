//***************************************************************************************** */
//***************************************************************************************** */
// Simple Example of the Constructor (parametrized constructor)
//***************************************************************************************** */

#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b)                                                         // parametrized constructor 
    {
        x = a;
        y = b;
    }
    void Display(void)
    {
        cout << "Ur point is: (" << x << "," << y << ")" << endl;
    }
};
int main()
{

    cout << "hello" << endl;
    Point obj1(4, 7);
    obj1.Display();
    cout << endl;
    Point obj2(6, 8);
    obj2.Display();
}

//  parametrized constrcutor invoked when the object is created
//  as it takes 2 parameters so we need to give to values while invoking parametrized constrcutor