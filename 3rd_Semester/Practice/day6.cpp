//***************************************************************************************** */
// Stattic data memebrs
//***************************************************************************************** */

#include <iostream>
using namespace std;

class Employee
{
    int id;
    static int count;  

public:
    void setData(void);
    void getData(void);
};
void Employee::setData(void)
{

    cout << "Enter the id of the Employee: ";
    cin >> id;
    count++;
}
void Employee::getData(void)
{
    cout << "The id of the employee is: " << id << " " << "And this is Employee Number: " << count << endl;
}

int Employee::count = 1000;
int main()
{
    Employee person1, person2, person3;
    person1.setData();
    person1.getData();
    person2.setData();
    person2.getData();
    person3.setData();
    person3.getData();
    return 0;
}
//***************************************************************************************** */
