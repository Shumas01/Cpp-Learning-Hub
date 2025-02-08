

//---------------------------------------------------------------------------------------------------------------------

// Name: Muhammad Shumas Mazhar
// Registration: l1f23bscs1097
// Lab 15 OOPS
// Task 4

//---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    char *Name;
    int EmpId;
    float salary;

public:
    Employee()
    {
        EmpId = 0;
        salary = 0.0;
        Name = new char[1];
        strcpy(Name, "");
    }
    Employee(int id, float sal, const char *N)
    {
        EmpId = id;
        salary = sal;

        Name = new char[strlen(N) + 1];
        strcpy(Name, N);
    }

    void Display() const
    {
        cout << "Employee Details: " << endl;
        cout << "Name: " << Name << endl;
        cout << "ID: " << EmpId << endl;
        cout << "Salary: " << salary << endl;
    }
    ~Employee()
    {
        delete[] Name;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class Department
{
    char *DepName;
    int EmpCount;
    Employee **Emp;
    int CurrentEmp;

public:
    Department()
    {
        EmpCount = 0;
        DepName = new char[1];
        strcpy(DepName, "");
        Emp = nullptr;
    }
    Department(int Count, const char *Name)
    {
        EmpCount = Count;
        CurrentEmp=0;
        DepName = new char[strlen(Name) + 1];
        strcpy(DepName, Name);

        Emp = new Employee *[EmpCount];
    }

    void addEmployee(const Employee &emp)
    {
        if (CurrentEmp < EmpCount)
        {
            Emp[CurrentEmp] = new Employee(emp);
            CurrentEmp++;
        }
        else
        {
            cout << "Department is full, cannot add more employees." << endl;
        }
    }
    void Display() const
    {
        cout << "Department Details:\n"
             << "Name: " << DepName << "\n"
             << "Current Employees: " << CurrentEmp << "\n"
             << "Employee List:" << endl;
        for (int i = 0; i < CurrentEmp; ++i)
        {
            Emp[i]->Display();
            cout << endl;
        }
    }

    ~Department()
    {
        for (int i = 0; i < CurrentEmp; ++i)
        {
            delete Emp[i];
        }
        delete[] Emp;
        delete[] DepName;
    }
};

//---------------------------------------------------------------------------------------------------------------------

int main()
{
    Employee e1(101, 5000.0, "John Doe");
    Employee e2(102, 6000.0, "Jane Smith");
    Employee e3(103, 4500.0, "Bob Johnson");

    Department dept(5, "Software Development");
    dept.addEmployee(e1);
    dept.addEmployee(e2);
    dept.addEmployee(e3);

    cout << "Department Information:" << endl;
    dept.Display();

    cout << "Displaying Employee Details Independently:" << endl;
    e1.Display();
    e2.Display();
    e3.Display();

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------
