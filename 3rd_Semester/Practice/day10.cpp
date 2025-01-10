//***************************************************************************************** */
// Doing sum without friend Functions
//***************************************************************************************** */
#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    void setData(int a1, int b1)
    {
        a = a1;
        b = b1;
    }
    int getData(void)
    {
        return a;
        return b;
    }
    void display(Complex obj1, Complex obj2)
    {
        a = obj1.a + obj2.a;
        b = obj1.b + obj2.b;
    }
    void print(void){
        cout<<"YYour complex numbber is: "<<a<<"+"<<b<<"i"<<endl;
    }

};
int main ()
{
    cout<<"SSum of complex numbbers: "<<endl;
    Complex obj1,obj2,obj3;
    obj1.setData(9,6);
    obj1.getData();
    obj1.print();

    obj2.setData(5,7);
    obj2.getData();
    obj2.print();
    obj3.display(obj1,obj2);
    obj3.print();
}
//***************************************************************************************** */
