//***************************************************************************************** */
//***************************************************************************************** */
// Making of Complex class
// making sum of two comlex numbers
// also the example of constructor with default arguments
//***************************************************************************************** */
#include <iostream>
using namespace std;

class Sum_calculate;

class Complex
{
    int x, y;

public:
    Complex(int a, int b = 40)
    {
        x = a;
        y = b;
    }
    void Print(void)
    {
        cout << "Ur complex Number is: " << x << "+" << y << "i" << endl;
    }
    friend class Sum_calculate;
};

// class Sum_calculate{
//     public:
//     int sum_complex1(Complex obj1,Complex obj2){
//         return obj1.x+obj2.x;
//     }
//     int sum_complex2(Complex obj1,Complex obj2){
//         return obj1.y+obj2.y;
//     }
// };

class Sum_calculate
{
public:
    Complex sumCal(Complex &obj1, Complex &obj2)
    {
        int realPart = obj1.x + obj2.x;
        int imgPart = obj1.y + obj2.y;
        return Complex(realPart, imgPart);
    }
};
int main()
{

    cout << "Hello" << endl;
    Complex obj1(4);
    obj1.Print();
    Complex obj2(9, 7);
    obj2.Print();
    Sum_calculate obj3;
    // int res1=obj3.sum_complex1(obj1,obj2);
    // int res2=obj3.sum_complex2(obj1,obj2);
    // cout<<"Sum of Complex numbers is: "<<res1<<"+"<<res2<<"i"<<endl;
    Complex objRes = obj3.sumCal(obj1, obj2);
    objRes.Print();
    cout << "       Code by Shumas MAzhar" << endl;
}






// //***************************************************************************************** */
// //***************************************************************************************** */

// //***************************************************************************************** */
// //***************************************************************************************** */
// // Friend Class
// //***************************************************************************************** */

// #include <iostream>
// using namespace std;

// class Complex;
// class Calculate;

// class Complex
// {

// private:
//     int a, b;

// public:
//     void set(int a1, int b1)
//     {
//         a = a1;
//         b = b1;
//     }

//     void print(void)
//     {
//         cout << "The complex number is: " << a << "+" << b << "i" << endl;
//     }
//     friend class Calculate;
// };
// class Calculate
// {
// public:
//     // int add(int a1,int b1){
//     //     return a1+b1;

//     // }
//     int sum_Complex(Complex obj1, Complex obj2)
//     {

//         return obj1.a + obj2.a;
//     }
//     int sum_ComplexComp(Complex obj1, Complex obj2)
//     {
//         return obj1.b + obj2.b;
//     }
// };
// int main()
// {
//     cout << "Hello Sum of Complex Numbers: " << endl;

//     Complex obj1, obj2;
//     obj1.set(4, 8);
//     obj1.print();
//     obj2.set(8, 9);
//     obj2.print();
//     Calculate obj3, obj4;
//     int res = obj3.sum_Complex(obj1, obj2);
//     int res1 = obj4.sum_ComplexComp(obj1, obj2);
//     cout << "Sum of Complex number is: " << res << "+" << res1 << "i" << endl;
// }
// //***************************************************************************************** */

// //***************************************************************************************** */
// //***************************************************************************************** */
// //***************************************************************************************** */

// #include<iostream>
// using namespace std;
// class Sum;
// class Complex{
// private:
//     int data1,data2;
// public:
//     Complex(void){
//         data1=0;
//         data2=0;
//     }
//     Complex(int x,int y=20){
//         data1=x;
//         data2=y;

//     }
//     void Display(void){
//         cout<<"Ur complex number is: "<<data1<<"+"<<data2<<"i"<<endl;
//     }
//     friend class Sum;

// };
// class Sum {
// public:
//     // Function to calculate the sum of two complex numbers
//     Complex calculate_sum(const Complex& obj1, const Complex& obj2) {
//         int realSum = obj1.data1 + obj2.data1;
//         int imagSum = obj1.data2 + obj2.data2;
//         return Complex(realSum, imagSum);
//     }
// };
// // void print(void){
// //     cout<<"After sum the values of the Complex number is: "<<calculate_sum1<<"+"<<calculate_sum2<<"i"<<endl;
// // }

// int main ()
// {
//     cout<<"Wlecome to the main body "<<endl;
//     Complex obj1;
//     obj1.Display();
//     Complex obj2(30,10);
//     obj2.Display();
//     // Sum obj3;
//     // int res1=obj3.calculate_sum1(obj1,obj2);
//     // int res2=obj3.calculate_sum2(obj1,obj2);

//   Sum obj3;
//     Complex result = obj3.calculate_sum(obj1, obj2);
// result.Display();
// }
