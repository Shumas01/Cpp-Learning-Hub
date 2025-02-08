#include<iostream>
using namespace std;

class Base1
{
    public:
    void print()
    {
        cout<<"Printing Base1"<<endl;
    }
};
class Base2:public Base1
{
    public:
    void print()
    {
        cout<<"Printing Base 2"<<endl;

    }
};
class Base3:public Base2
{
    public:
    void print()
    {
        cout<<"Printing Base 3"<<endl;
    }
};
int main ()
{
    Base1 obj1;
    
}