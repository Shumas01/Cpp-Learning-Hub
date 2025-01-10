// #include <iostream>
// using namespace std;
// // static int count = 0;
// class Num
// {
//     int count;
// public:
//     Num()
//     {
//         count++;
//         cout << "This is where the constructor is called " << count << endl;
//     }
//     ~Num(){
//         cout<<"This is where the destructor is called "<<count<<endl;
//         count--;
//     }
// };
// int main (){

//     Num obj1;
//     Num obj2;
//     {
//         cout<<"Inside the block"<<endl;

//     }
// }

#include <iostream>
using namespace std;

class Test
{
public:
    int x, y;
    Test() : x(0), y(0) {}
    Test(int a, int b) : x(a), y(b) {}
    void Display(void)
    {
        cout << "the number x and y are: " << x << "," << y << endl;
    }
};
int main()
{
    Test obj1;
    obj1.Display();
    Test obj2(4,5);
    obj2.Display();
}