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
    Test(T inputarr[], int s)
    {
        size = s;
        arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = inputarr[i];
        }
    }
    void sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i; j++)
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
    void Display() const
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
int main()
{

    int no[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float noos[5] = {2.3, 4.5, 6.2, 5.6, 7.8};
    char arr[3] = {'a', 'b', 'c'};

    Test<int> T1(no, 9);
    Test<float> T2(noos, 5);
    Test<char> T3(arr, 4);

    T1.Display();
    T1.sort();
    cout << "After Sorting: ";
    T1.Display();
    cout << endl;
    T2.Display();
    T2.sort();
    cout << "After Sorting: ";
    T2.Display();
    cout << endl;
    T3.Display();
    T3.sort();
    cout << "After Sorting: ";
    T3.Display();
}