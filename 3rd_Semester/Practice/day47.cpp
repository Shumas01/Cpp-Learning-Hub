// University Course Enrollment System (Composition & Aggregation)
// Classes:
// Course (Base Class)

// courseID (int) – Unique identifier.
// courseName (char*) – Name of the course.
// Constructor, displayCourse() function.

// Student class
// studentID (int) – Unique ID for student.
// name (char*) – Name of student.
// courses[] – Array of Course pointers.
// courseCount – Number of courses enrolled.
// Functions:
// enrollCourse(): Adds a course to the student's list.
// displayStudentCourses(): Shows enrolled courses.
// checkDuplicateCourses(): Identifies if a student is enrolled in a course multiple times and prints the most repeated course.

#include <iostream>
#include <cstring>
using namespace std;

class Course
{
    int courseID;
    char *courseName;

public:
    Course(const char *name, int id)
    {
        courseID = id;
        courseName = new char[strlen(name) + 1];
        strcpy(courseName, name);
    }
    void Display()
    {
        cout << "Course ID: " << courseID << endl;
        cout << "Course Name: " << courseName << endl;
    }
    ~Course()
    {
        delete[] courseName;
    }
};

// Student class
// studentID (int) – Unique ID for student.
// name (char*) – Name of student.
// courses[] – Array of Course pointers.
// courseCount – Number of courses enrolled.
// Functions:
// enrollCourse(): Adds a course to the student's list.
// displayStudentCourses(): Shows enrolled courses.
// checkDuplicateCourses(): Identifies if a student is enrolled in a course multiple times and prints the most repeated course.

class Student
{
    int studentID;
    char *name;
    Course *course[10];
    int courseCount;

public:
    Student(const char* namee,int id,int count){

        studentID=id;
        courseCount=count;
        name=new char [strlen(namee)+1];
        strcpy(name,namee);
    }
    void enrollCourse(const char*namee,int id){
        if(courseCount<10){
            course[courseCount]=new Course(namee,id);
            courseCount++;

        }
        else{
            cout<<"No more course can be added.!"<<endl;
        }


    }

    void DisplayCourses(){

        if(courseCount==0){
            cout<<"No course added"<<endl;

        }
        else {
            for(int i=0;i<courseCount;i++){
                course[i]->Display();
            }
            
        }
    }
};
