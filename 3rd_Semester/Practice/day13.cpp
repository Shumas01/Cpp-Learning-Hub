//***************************************************************************************** */
//***************************************************************************************** */
// Friend Class
//***************************************************************************************** */
#include <iostream>
using namespace std;

class Complex;
class sum_Calculate;

class Complex
{
private:
    int a, b;

public:
    void set(int a1, int b1);
    void print(void);
    friend class sum_Calculate;
};

class sum_Calculate
{

public:
    int sum_Complex(Complex obj1, Complex obj2)
    {
        return obj1.a + obj2.a;
    }
    int sum_Complex2(Complex obj1, Complex obj2)
    {
        return obj1.b + obj2.b;
    }
};
void Complex::set(int a1, int b1)
{
    cout << "Inside the setter function";
    cout << endl;
    a = a1;
    b = b1;
}
void Complex::print(void)
{
    cout << "Ur Complex Numbber is : " << a << "+" << b << "i" << endl;
}
int main()
{
    Complex obj1, obj2;
    int x, y;
    cout << "Enter 1st value: " << endl;
    cin >> x >> y;
    obj1.set(x, y);
    obj1.print();
    cout << "Enter values for the 2nd real and imaginary part: " << endl;
    cin >> x >> y;
    obj2.set(x, y);
    // obj2.print();
    sum_Calculate obj3, sum;
    // obj3.sum_Complex(obj1,obj2);
    // obj3.sum_Complex2(obj1,obj2);
    obj1.print();
    obj2.print();
    cout << "SUm of Complex Number is: " << obj3.sum_Complex(obj1, obj2) << "+" << obj3.sum_Complex2(obj1, obj2) << "i" << endl;
}
