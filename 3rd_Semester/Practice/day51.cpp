#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Test
{

protected:
    T *arr;
    int size;

public:
    Test(T inputArr[], int sizee)
    {
        size = sizee;
        arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = inputArr[i];
        }
    }

    void sort()
    {

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Test()
    {
        delete[] arr;

    }
};

int main (){

    int arr1[8]={1,2,3,4,5,5,7};
    Test <int> arr(arr1,8);
    arr.sort();
    arr.Display();
}