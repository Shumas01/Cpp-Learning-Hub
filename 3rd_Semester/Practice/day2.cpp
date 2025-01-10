// string empty function
// string lenght function
// string clear function
// string at function
// string append function
// string substr function
// string find function
// string erase function

#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    
    string name;
    cout << "Enter ur name: ";
    getline(cin, name);
    int lenght;
    lenght = name.length();
    cout << "Lenght of the name is: " << lenght << endl;

    if (lenght > 20)
    {
        cout << "Your name can't be more than 20 characters" << endl;
    }
    else
    {
        cout << "Welcome!!! " << name;
    }
    return 0;
}
//***************************************************************************************** */
