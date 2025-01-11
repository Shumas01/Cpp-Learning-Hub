#include <iostream>
#include <string>
using namespace std;

class ComplexNumber
{
private: 
    double realNo, imaginaryNo;

public: 
    void set();
    void get(double &real, double& imaginary);
    void display();
    
};

void ComplexNumber:: set()
{
    cout<<" Enter the real part value: ";
    cin>>realNo;
    cout<<"Enter the imaginary part value: ";
    cin>>imaginaryNo;
}
void ComplexNumber:: get(double &real, double& imaginary)
{
real = realNo;
imaginary = imaginaryNo;

}
void ComplexNumber::display()
{
    cout<<"Enterr the real part: "<<realNo<<" And the imaginary no : "<<imaginaryNo;

}

void line(){
    for (int i=0;i<45;i++){
        cout<<"-";
    }
    cout<<endl;
}


int main ()
{
    
}