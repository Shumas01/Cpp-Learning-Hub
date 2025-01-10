//***************************************************************************************** */
//***************************************************************************************** */
// Simple Example of the Constructor (parametrized constructor)
//***************************************************************************************** */

#include <iostream>
using namespace std;

class Complex
{
    int x, y;

public:
    // Complex(void)                                                               // default constructor as it takes no parameters
    // {
    //     cout<<"Inside the default constructor"<<endl;
    //     x = 10;
    //     y = 20;
    // }
    Complex(int a, int b)                                                       // parametrized constructor takes 2 parameters
    {
        cout<<"Inside the parametrized constructor"<<endl;
        x = a;
        y = b;
    }
    void Display(void)
    {
        cout << "Ur complex number is: " << x << "+" << y << "i" << endl;
    }
};
int main()
{
    cout << "Welcome to the maain boddy" << endl;
    Complex obj1(10,20);
    obj1.Display();
}