//***************************************************************************************** */
//***************************************************************************************** */
// Simple Example of the Constructors with default arguments
//***************************************************************************************** */

#include <iostream>
using namespace std;

class Data
{
private:
    int x, y, z;

public:
    Data(int a, int b, int c = 90)
    {
        x = a;
        y = b;
        z = c;
    }
    void Display(void)
    {
        cout << "the value of Data 1 and Data 2 and Data 3 is: " << x << " , " << y << " and " << z << endl;
    }
};
int main()
{

    Data obj1(10, 20, 30);
    obj1.Display();
}