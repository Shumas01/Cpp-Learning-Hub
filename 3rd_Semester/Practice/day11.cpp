//***************************************************************************************** */
// Friend Function 
//***************************************************************************************** */

#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    void set(int a1, int b1);
    void print(void);
    friend Complex sum_Complex(Complex obj1, Complex obj2);
};

void Complex::set(int a1, int b1)
{ // part of the class
    cout << "Inside the setter function " << endl;
    a = a1;
    b = b1;
}
void Complex::print(void)
{ // part of the class

    cout << "Complex numbber is: " << a << "+" << b << "i" << endl;
}

// friend function it can access class members
Complex sum_Complex(Complex obj1, Complex obj2)
{
    cout << "Inside the friend function " << endl;
    Complex obj3;
    obj3.set((obj1.a + obj2.a), (obj1.b + obj2.b));
    return obj3;
}

int main()
{
    cout << "Now Inside the main function..." << endl;
    Complex obj1, obj2, sum;
    int x, y;
    cout << "-------------------------------------------------------" << endl;
    cout << "Enter first andd 2nd value for 1st Complex numbers: ";
    cin >> x >> y;
    obj1.set(x, y);
    obj1.print();
    cout << "Enter first andd 2nd value for 2nd Complex numbers: ";
    cin >> x >> y;
    obj2.set(x, y);
    obj2.print();
    cout << "-------------------------------------------------------" << endl;

    sum = sum_Complex(obj1, obj2);
    obj1.print();
    obj2.print();
    sum.print();
}
//***************************************************************************************** */
