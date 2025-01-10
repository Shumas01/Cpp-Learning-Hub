//***************************************************************************************** */
// Array of Objects
//***************************************************************************************** */
#include <iostream>
using namespace std;

class Employee
{

private:
    int id;
    int salary;

public:
    void setData(void)
    {
        salary = 12200;
        cout << "Enter the id of the Employee: ";
        cin >> id;
        cout << "The salary of the EMployee is: " << salary << endl;
    }
    void getData(void)
    {
        cout << "THe id of this Employee is :" << id << endl;
        cout << "The salary of the Employee isL " << salary << endl;
        cout << endl;
    }
};
int main()
{
    cout << "~~Employyee Manangement~~" << endl;
    Employee obj[4];
    for (int i = 0; i < 4; i++)
    {
        obj[i].setData();
        obj[i].getData();
    }
    cout << endl
         << "Endl endl endl" << endl;
    obj[3].getData();
}
//***************************************************************************************** */
