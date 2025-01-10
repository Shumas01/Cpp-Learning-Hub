//***************************************************************************************** */
//***************************************************************************************** */
// Without copy constructor
//***************************************************************************************** */

// #include <iostream>
// using namespace std;

// class Number
// {
// private:
//     int n;

// public:
//     Number()
//     {
//         n = 0;
//     }
//     Number(int a)
//     {
//         n = a;
//     }
//     void Display(void)
//     {
//         cout << "Ur number is: " << n << endl;
//     }
// };
// int main()
// {

//     Number obj1, obj2(20);
//     obj1.Display();
//     obj2.Display();
// }
// ****************************************************************************************** /
//     With copy constructor
//         ****************************************************************************************** /

#include <iostream>
using namespace std;

class Number
{
    int data1;

public:
    Number()                                                            // default constructor
    {
        cout << "Default constructor calling" << endl;
        data1 = 0;
    }
    Number(int num)                                                     // parametrized constrcutor 
    {
        cout << "inside the parametrized constructor" << endl;
        data1 = num;
    }
    Number(Number &obj)                                                 // copy constructor
    {
        cout << "inside the copy constructor " << endl;
        data1 = obj.data1 + 2;
    }
    void Display(void)                                                  // simple display function
    {
        cout << "Ur number becomes : " << data1 << endl;
    }
};

int main()                                                              // main body
{
    Number obj1, obj2(10);
    obj1.Display();

    // obj2.Display();
    Number obj3(obj2);                                                  // copy constructor invoked
    obj2.Display();
    obj3.Display();
}