#include<iostream>
#include<string>
using namespace std;
     //------------------------------------------------------------------------------------------
class Rectangle 
{
private:
    double length;
    double width;

public:
    void setValues();
    void Display();
    double calculateArea();
};
     //------------------------------------------------------------------------------------------

    void Rectangle::setValues()
    {
        cout<<"Enter Length: ";
        cin>>length;
        cout<<"Enter Width: ";
        cin>>width; 
    }
    void Rectangle::Display()
    {
        cout<<"Length: "<<length;
        cout<<endl;
        cout<<"Width: "<<width;
        cout<<endl;
    }
      double Rectangle::calculateArea()
    {
        double area=0;
        area=length*width;
        cout<<"Area of the rectangle is: "<<area;
        cout<<endl;
        return area;
    }
      //------------------------------------------------------------------------------------------

int main()
{
    Rectangle obj;
    obj.setValues();
    obj.Display();
    obj.calculateArea();
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Program Finished!!"<<endl;
}





        // BELOW one is the easiest way to do
/*
#include<iostream>
#include<string>
using namespace std;

     //------------------------------------------------------------------------------------------

class Rectangle 
{
private:
    double length;
    double width;

public:
    void setValues()
    {
        cout<<"Enter Length of the Rectangle: ";
        cin>>length;
        cout<<"Enter width of the Rectangle: ";
        cin>>width;
    }
    void Display()
    {
        cout<<"Length: "<<length;
        cout<<endl;
        cout<<"Width: "<<width;
        cout<<endl;
    }
    double calculateArea()
    {
        double area;
        area=length*width;
        cout<<"Area of the Rectangle is: "<<area;
        return area;
    }
};

     //------------------------------------------------------------------------------------------

int main()
{
    Rectangle r1;
    r1.setValues();
    r1.Display();
    r1.calculateArea();

}
     //------------------------------------------------------------------------------------------

*/
