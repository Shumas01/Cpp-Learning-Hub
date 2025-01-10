//***************************************************************************************** */
//***************************************************************************************** */
// Simple Example of the Constructor Overloading
//***************************************************************************************** */

#include <iostream>
using namespace std;

class Complex
{
    int x, y;

public:
    Complex(void)                                           // default constructor
    {
        x = 0;
        y = 0;
    }
    Complex(int a, int b)                                   // parametrized constructor 
    {
        x = a;
        y = b;
    }
    Complex(int a)                                          // parametrized constrcutor
    {
        x = a;
        y = 0;
    }
    void Display(void)
    {
        cout << "Ur complex number is: " << x << "+" << y << "i" << endl;
    }
};

int main()
{
    Complex obj1;
    obj1.Display();
    Complex obj2(4, 6);
    obj2.Display();
    Complex obj3(20);
    obj3.Display();
    return 0;
}