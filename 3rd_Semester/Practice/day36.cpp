//***************************************************************************************** */
// Inheritance classes
//***************************************************************************************** */
#include<iostream>
using namespace std;

class TwoDimension{
public:
    int height,width;

    void setData(int h,int w){
        cout<<"Inside the setter function"<<endl;
        height=h;
        width=w;

    }
    int getDataH(){
        return height;

    }
        int getDataW(){
        return width;
        
    }
    void Display()
    {
        cout<<"Height is: "<<height<<endl;
                cout<<"Width is: "<<width<<endl;
    }
};

class Triangle: public TwoDimension{
    public:
    void Area(){
        int return1;
        return1=height*width/2;
        cout<<"Area is: "<<return1;
    }
};

int main (){
    Triangle obj1;
    obj1.height=20;
    obj1.width=40;
    obj1.setData(20,40);
    obj1.Display();
    obj1.Area();
}
