//***************************************************************************************** */
//***************************************************************************************** */
// Swapping of the values using Friend function
//***************************************************************************************** */

#include <iostream>
using namespace std;
class B;                                                                //forward declaration
class A                                                                 // class A 
{   
private:
    int val1;

public:
    void set(int num)                                                   // setter function
    {
        val1 = num;
    }

    void display(void)                                                  // displaying one value
    {
        cout << "Value 1: " << val1 << endl;
    }
    friend void swap(A &, B &);                                         // friend function
};
class B                                                                 // class B
{
private:
    int val2;

public:
    void set(int num)                                                   // setter function
    {
        val2 = num;
    }
    void display(void)                                                  // displaying value 2
    {
        cout << "Value 2: " << val2 << endl;
    }
    friend void swap(A &, B &);                                         // friend function declaration 
};

void swap(A &obj1, B &obj2)                                             // swap function
{
    int temp;
    temp = obj1.val1;
    obj1.val1 = obj2.val2;
    obj2.val2 = temp;
}
int main()                                                              // main body
{
    cout << "insidie the main function :" << endl;
    A obj1;                                                             // class A objects
    obj1.set(4);
    obj1.display();
    B obj2;                                                             // class B objects
    obj2.set(12);
    obj2.display();
    swap(obj1, obj2);                                                   // swapping of the values here
    cout << "Values after swapping: " << endl;
    obj1.display();
    obj2.display();
}