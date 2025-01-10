//***************************************************************************************** */
//***************************************************************************************** */
// same example as in day21.cpp just did it for practice
//***************************************************************************************** */

#include<iostream>
using namespace std;

class Sum;

class Complex{                                                              // class Complex
    private: 
    int data1,data2;
    public:
    Complex(int val1=20,int val2=10){                                       // parametrized constructor
        data1=val1;
        data2=val2;

    }
    void print(void){                                                       // display function
        cout<<"ur complex number is: "<<data1<<"+"<<data2<<"i"<<endl; 
    }
    friend class Sum;
};
class Sum{                                                                  // friend class Sum
    public:
    Complex sum_Cal(Complex & obj1,Complex &obj2){                          // for calculating the sum
        int realSum=obj1.data1+obj2.data1;
        int imgSum=obj1.data2+obj2.data2;
        return Complex(realSum,imgSum);
    }

};
int main ()                                                                 // main body 
{

    cout<<"hello "<<endl;
    Complex obj1,obj2(10,3),res;
    obj1.print();
    obj2.print();

    Sum obj3;                                                               // obj3 is the object of Sum class
    res=obj3.sum_Cal(obj1,obj2);                                            // res is the object of Complex class as it stores 
                                                                            // the sum of two complex numbers
    res.print();                                                            
}