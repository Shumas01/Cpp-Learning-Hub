#include<iostream>
#include<string>
using namespace std;

double area(int length);                     // for the circle
double area(int base,int height);            // for the triangle
double area(float radius);                     // for the circle
void line();

int main()
{
     //------------------------------------------------------------------------------------------
line();
int circleSides=0;
cout<<"Enter sides for circle: ";
cin>>circleSides;
cout<<"Area of the circle with sides "<<circleSides<<" is "<<area(circleSides);
cout<<endl;
line();
    //------------------------------------------------------------------------------------------
int triangleBase=0, triangleHeight=0;
cout<<"Enter Base of the triangle: ";
cin>>triangleBase;
cout<<"Enter Height of the trianle: ";
cin>>triangleHeight;
cout<<"Area of the triangle with    Base" <<triangleBase<<" and Height "<<triangleHeight<<" is:  "<<area(triangleBase,triangleHeight);
cout<<endl;
line();
    //------------------------------------------------------------------------------------------
float radius=0.0;
cout<<"Enter the radius of the circle: ";
cin>>radius;
cout<<"Area of the circle with a radius of "<<radius<<" is: "<<area(radius);
cout<<endl;
line();
     //------------------------------------------------------------------------------------------
}

void line()
{
    for(int i=0;i<45;i++){
        cout<<"-";
    }
    cout<<endl;
}
double area(int length)
{
return length*length;
}
double area(int base, int height)
{
return 0.5*base*height;

}
double area(float radius)
{
return 3.14*radius*radius;
}