//***************************************************************************************** */
// Stattic functionss
//***************************************************************************************** */

#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    static int count;

public:
    void setData(void);
    void getData(void);
    static void getCount(void);
};

void Employee::setData(void)
{
    cout << endl;
    cout << "Enter the id of the eemployee:";
    cin >> id;
    count++;
}
void Employee::getData(void)
{

    cout << "The id of the Employee is: " << id << " and the count is: " << count << endl;
}
void Employee::getCount(void)
{
    cout << "The count value is: " << count << endl;
}
int Employee::count;
int main()
{
    Employee obj1;
    obj1.setData();
    obj1.getData();
    Employee::getCount();
    Employee obj2, obj3;
    obj2.setData();
    obj2.getData();
    Employee::getCount();
    obj3.setData();
    obj3.getData();
    Employee::getCount();
}
//***************************************************************************************** */
