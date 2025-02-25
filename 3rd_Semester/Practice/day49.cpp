
#include<iostream>
using namespace std;

template <class T>
class Find{
    T *arr;
    int size;

    public:

        Find(int s){
            size=s;
            arr=new T[size];

        }
        void Display(){
            for(int i=0;i<size;i++){
                cout<<arr[i];
            }

        }


};
int main (){

    Find <int> f(3);
    f.Display();
}