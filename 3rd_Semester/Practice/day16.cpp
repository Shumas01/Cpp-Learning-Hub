//***************************************************************************************** */
//***************************************************************************************** */
// Simple Example of the Constructor (default constructor)
//***************************************************************************************** */

#include <iostream>
using namespace std;

class Complex
{ // complex class def
private:
    int a, b;

public:
    Complex(void)
    { // default constructor
        cout << "Inside the Constructor" << endl;
        a = 10;
        a++;
        b = 20;
    }
    void Display(void)
    { // display function
        cout << "Inside the Display function!!" << endl;
        cout << "Complex Number is: " << a << "+" << b << "i" << endl;
    }
};

int main()
{                 // main body
    Complex obj1; // Constructor called whenever the object is created
    cout << "Inside the main body" << endl;
    obj1.Display();
}

//  Constrcutors are automatically called (invoked) whenever an object is created
//  Constructors should be declared in the public section
//  Constructors dont return values as they dont have any return types
//  COnstructors have default arguments