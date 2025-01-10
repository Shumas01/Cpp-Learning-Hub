// This one is the example of Inheritance classes
// in inheritance class all the members must be public

#include <iostream>
using namespace std;

class TwoD_shape
{
    // protected:
private: // using a parent class as private is not a good approach
    int width;
    int height;
public:
    TwoD_shape(int w,int h)
    {
        cout << "Constructing TwoD__shape object " << endl;
    }
    void showDimensions()
    {
        cout << "Height: " << height << endl;
        cout << "width: " << width << endl;
    }
    // public:
    // void set_w(int w)
    // {
    //     width = w;
    // }
    // void set_h(int h)
    // {
    //     height = h;
    // }
    // int get_w()
    // {
    //     return width;
    // }
};

class Triangle : public TwoD_shape
{
public:
    char arr[10];

    // Triangle()
    // {
    //     cout << "Constructing Triangle object" << endl;

    // }

    // void area() // calculate or display
    // {
    //     cout << "Area: " << endl;
    //     int return1 = height * width / 2;
    //     cout << return1 << endl;
    // }

    // Triangle() :TwoD_shape(30,40)
    // {}
    Triangle (int w,int h): TwoD_shape(w,h){}
    void showStyle()
    {
        cout << arr;
    }
    void setType(const char t[])
    {
        strcpy(arr, t);
    }
    // void set(int W, int H)
    // {
    //     set_w(W);
    //     set_h(H);
    // }
    // void Display()
    // {
    //     showDimensions();
    // }

};

int main()
{
    // Triangle T1;
    
    // T1.height = 10;
    // T1.width = 20;
    // T1.showDimensions();
    // T1.set_w(20);
    // T1.get_w();
    // T1.set(20, 10);
    TwoD_shape D1(30,40);
    Triangle t1(30,40) ;

    // T1.Display();
    // T1.area();
//     T1.setType("Isosceles"); // warning: string lateral to char *
//     T1.showStyle();
}