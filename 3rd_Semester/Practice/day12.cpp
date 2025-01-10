//***************************************************************************************** */
//***************************************************************************************** */
// Friend Class
//***************************************************************************************** */

#include <iostream>
using namespace std;

class Complex;
class Calculate;

class Complex
{

private:
    int a, b;

public:
    void set(int a1, int b1)
    {
        a = a1;
        b = b1;
    }

    void print(void)
    {
        cout << "The complex number is: " << a << "+" << b << "i" << endl;
    }
    friend class Calculate;
};
class Calculate
{
public:
    // int add(int a1,int b1){
    //     return a1+b1;

    // }
    int sum_Complex(Complex obj1, Complex obj2)
    {

        return obj1.a + obj2.a;
    }
    int sum_ComplexComp(Complex obj1, Complex obj2)
    {
        return obj1.b + obj2.b;
    }
};
int main()
{
    cout << "Hello Sum of Complex Numbers: " << endl;

    Complex obj1, obj2;
    obj1.set(4, 8);
    obj1.print();
    obj2.set(8, 9);
    obj2.print();
    Calculate obj3, obj4;
    int res = obj3.sum_Complex(obj1, obj2);
    int res1 = obj4.sum_ComplexComp(obj1, obj2);
    cout << "Sum of Complex number is: " << res << "+" << res1 << "i" << endl;
}
//***************************************************************************************** */
