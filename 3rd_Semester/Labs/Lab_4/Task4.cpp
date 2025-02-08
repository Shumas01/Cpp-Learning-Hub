//---------------------------------------------------------------------------------------------------------------------

// Name: Muhammad Shumas Mazhar
// Registration: l1f23bscs1097
// Lab 14 OOPS
// Task 4

//---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    char *studentName;
    int studentID;

public:
    Student()
    {
        studentName = nullptr;
        studentID = 0;
    }

    Student(const char *name, int id)
    {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
        studentID = id;
    }

    Student(const Student &other)
    {
        studentName = new char[strlen(other.studentName) + 1];
        strcpy(studentName, other.studentName);
        studentID = other.studentID;
    }

    Student &operator=(const Student &other)
    {
        if (this != &other)
        {
            delete[] studentName;
            studentName = new char[strlen(other.studentName) + 1];
            strcpy(studentName, other.studentName);
            studentID = other.studentID;
        }
        return *this;
    }

    ~Student()
    {
        delete[] studentName;
    }

    void display() const
    {
        cout << "Student Name: " << studentName << endl;
        cout << "Student ID: " << studentID << endl;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class Course
{
private:
    char *courseName;
    int maxStudents;
    Student *students;
    int studentCount;

public:
    Course()
    {
        courseName = nullptr;
        maxStudents = 0;
        students = nullptr;
        studentCount = 0;
    }

    Course(const char *cName, int max)
    {
        courseName = new char[strlen(cName) + 1];
        strcpy(courseName, cName);
        maxStudents = max;
        students = new Student[maxStudents];
        studentCount = 0;
    }

    ~Course()
    {
        delete[] courseName;
        delete[] students;
    }

    void addStudent(const Student &student)
    {
        if (studentCount < maxStudents)
        {
            students[studentCount] = student;
            studentCount++;
        }
        else
        {
            cout << "Course is full. Cannot add more students." << endl;
        }
    }

    void display() const
    {
        cout << "Course Name: " << courseName << endl;
        cout << "Max Students: " << maxStudents << endl;
        cout << "Enrolled Students:" << endl;
        for (int i = 0; i < studentCount; i++)
        {
            students[i].display();
            cout << endl;
        }
    }
};

//---------------------------------------------------------------------------------------------------------------------

int main()
{
    Course course("Computer Science", 3);

    Student student1("John", 101);
    Student student2("Alex", 102);
    Student student3("Sarah", 103);

    course.addStudent(student1);
    course.addStudent(student2);
    course.addStudent(student3);

    course.display();

    cout << endl;

    student1.display();
    student2.display();
    student3.display();

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------
