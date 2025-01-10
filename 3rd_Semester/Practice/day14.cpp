//***************************************************************************************** */
//***************************************************************************************** */
// Simple Example of the Friend FUNCTION
//***************************************************************************************** */

#include <iostream>
using namespace std;

class B;
class A
{
private:
    int data;

public:
    void set(int value)
    {
        data = value;
    }
    friend void add(A, B);
};
class B
{
private:
    int num;

public:
    void set(int value)
    {
        num = value;
    }
    friend void add(A, B);
};
void add(A obj1, B obj2)
{
    cout << "SUm of A and B objects are: " << obj1.data + obj2.num;
}

int main()
{
    A obj1;
    int x;
    cout << "Enter a value for the 1st Object: ";
    cin >> x;
    obj1.set(x);
    cout << "Enter a value for the 2ndd Object: ";
    cin >> x;
    B obj2;
    obj2.set(x);
    add(obj1, obj2);
}