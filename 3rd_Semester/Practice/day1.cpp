#include <iostream>
using namespace std;

class Shumas
{
private:
    int a, b, c;

public:
    int x, y;
    void setData(int a1, int b1, int c1); // setter function to set values
    void getData();                       // getter function to print
};

void Shumas::setData(int a1, int b1, int c1)
{
    cout << "Inside the setter function" << endl;
    a = a1;
    b = b1;
    c = c1;
}
void Shumas::getData()
{
    cout << endl
         << "Inside the getter function!!!" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Value of c: " << c << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;
}

int main()
{
    Shumas obj1, obj2;
    obj1.setData(1, 2, 4);
    obj1.x = 5;
    obj1.y = 6;
    obj1.getData();
    cout << "Now for obj 2" << endl;
    obj2.setData(10, 20, 40);
    obj2.getData();

    return 0;
}
//***************************************************************************************** */
