#include <iostream>
#include<string>
using namespace std;
class Employee
{
private:
    int id[100];
    char name;
    int counter;

public:
    void initialCounter() { counter = 0; }
    void setdata(void);
    void getData(void);
    void display(void);
};
void Employee::setdata(void)
{
    cout << "Enter the employee id: ";
    cin >> id[counter];
    cout << "Enter employee name: ";
    // getline(cin,name);
    counter++;
}

int main()
{
    Employee person1;
    person1.setdata();
    return 0;
}
//***************************************************************************************** */
