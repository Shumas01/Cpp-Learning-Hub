#include <iostream>
using namespace std;

class binary
{
private:
    string s;

public:
    void read_Data(void);
    void check_binary(void);
    void ones_compliment(void);
    void display();
};

int main()
{
    binary obj1;
    obj1.read_Data();
    obj1.check_binary();
    obj1.display();
    obj1.ones_compliment();
    cout << "After taking compliment: " << endl;
    obj1.display();
    return 0;
}

void binary::read_Data(void)
{
    cout << "Enter binary number: ";
    cin >> s;
}
void binary::check_binary(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "incorrect binary" << endl;
            exit(0);
        }
    }
}
void binary::ones_compliment(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else if (s.at(i) == '1')
        {
            s.at(i) = '0';
        }
    }
}
void binary::display()
{
    cout << "Displaying binary numbers" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}
//***************************************************************************************** */
