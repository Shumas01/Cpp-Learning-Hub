// In Inheritance Class all the members must bbe Public
// Syntax for the Inheritance class: 
// Class Name : access modifier and then the classs name u want for the Inherit

#include <iostream>
using namespace std;

class TwoDshape
{
public:
    int width;
    int height;

    void setData()
    {
        cout << "Enter the height of the triangle: ";
        cin >> height;
        cout << "Enter the width of the triangle: ";
        cin >> width;
    }
    int getDataH()
    {
        return height;
    }
    int getDataW()
    {
        return width;
    }
    void showDimensions()
    {
        cout << "Height of the Triangle: " << height;
        cout << endl
             << "Width of the Triangle: " << width << endl;
    }
};

class Triangle : public TwoDshape
{
public:
    char arr[10];
    void Area()
    {
        int return1;
        return1 = height * width / 2;
        cout << return1;
        // return height*width/2;
    }
    void showStyle()
    {
        cout << arr;
    }
};

int main()
{

    Triangle T1;
    T1.setData();
    T1.getDataH();
    T1.getDataW();
    T1.showDimensions();
    cout << "Area: ";
    T1.Area();
    cout << endl;
    strcpy(T1.arr, "Equilateral");
    T1.showStyle();
}