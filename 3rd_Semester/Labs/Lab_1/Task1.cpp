#include<iostream>
#include<string>
using namespace std;
void average(int a, int b);  
void average(double a, double b); 

int main()
{
int num1,num2;
cout<<"Enter two numbers for intgers avg: "<<endl;
cin>>num1>>num2;
average(num1,num2);
cout<<endl;
cout<<"----------------------------------------------"<<endl;
double double1,double2;
cout<<"Enter two numbers for ddoubles avg: "<<endl;
cin>>double1>>double2;
average(double1,double2);

cout<<endl;
cout<<"----------------------------------------------"<<endl;
}

void average(int a, int b)
{
double avg=(a+b)/2.0;
cout<<"The average of integers" <<a<<" and "<<b<<" is "<<avg<<endl;
}
void average(double a, double b)
{
double avg=(a+b)/2.0;
cout<<"The average of double" <<a<<" and "<<b<<" is "<<avg<<endl;

} 