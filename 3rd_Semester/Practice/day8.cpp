//***************************************************************************************** */
// Passing objects as function Arguments
//***************************************************************************************** */
#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    void setData(int a1, int a2)
    {
        a = a1;
        b = a2;
    }
    int getData()
    {

        return a;
        return b;
    }
    void setDataBySUm(Complex obj1, Complex obj2)
    {
        a = obj1.a + obj2.a;
        b = obj1.b + obj2.b;
    }
    void Print(void)
    {
        cout << "Your Complex Number is: " << a << "+" << b << "i" << endl;
    }
};
int main()
{

    Complex obj1, obj2, obj3;
    obj1.setData(2, 4);
    // obj1.getData();
    obj1.Print();

    obj2.setData(3, 4);
    obj2.getData();
    obj2.Print();
    cout << "Doing sum of two complex numbers" << endl;
    obj3.setDataBySUm(obj1, obj2);
    obj3.Print();
}
//***************************************************************************************** */
