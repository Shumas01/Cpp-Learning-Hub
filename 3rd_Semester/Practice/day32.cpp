// This one is the example of Inheritance classes 
// in inheritance class all the members must be public


#include <iostream>
using namespace std;

class TwoD_shape
{
public:
    int width;
    int height;

    void showDimensions()
    {
        cout << "Height: " << height << endl;
        cout << "width: " << width << endl;
    }
};

class Triangle : public TwoD_shape
{
public:
    char arr[10];
    void area() // calculate or display
    {
        cout<<"Area: "<<endl;
        int return1 = height * width / 2;
        cout << return1 << endl;
    }
    void showStyle()
    {
        cout << arr;
    }
};

int main()
{
    Triangle T1;
    T1.height = 10;
    T1.width = 20;
    T1.showDimensions();
    T1.area();
    strcpy(T1.arr, "isosceles");
    T1.showStyle();
}