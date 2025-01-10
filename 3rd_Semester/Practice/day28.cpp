// Create a Student class that maintains basic information about students, including their enrolled courses and grades. 
// Implement various functionalities for managing students, courses, and grades.
// ~~Features to Implement:
// 	•	Student Attributes:
// 	•	Add attributes to the Student class to store:
// 	•	Student Name
// 	•	Roll Number
// 	•	Age
// 	•	Address
// 	•	A list of enrolled courses (using array)
// 	•	A list of corresponding grades (numbers)
// 	•~~Course Management:
// 	•	Allow students to enroll in new courses and assign grades to those courses.
// 	•	Implement methods to add and remove courses from a student's record.
// 	•~~GPA Calculation:
// 	•	Implement a method to calculate and return the Grade Point Average (GPA) based on the courses and grades a student has.
// 	•~~Input Validation:
// 	•	Add error handling to ensure that grades are within a valid range (e.g., 0 to 100) and that courses can only be added if they haven't already been enrolled in.
// 	•~~Display Student Information:
// 	•	Create a method to display student details, including their courses and grades in a formatted manner.
// 	•~~File Handling ():
// 	•	Introduce functionality to save the student data to a file and read from it, allowing users to retain information between runs.
// 	•~~User Menu:
// 	•	Create a simple text-based menu system that allows users to perform various actions (e.g., add student, view student details, enroll in a course, calculate GPA).

// Additional Considerations:
// 	•	Input Handling: Ensure user inputs are valid, especially for grades and roll numbers.
// 	•	File Handling: Consider adding file handling functions to save and load student data.
// 	•	Documentation: Encourage students to write comments and document their code for better understanding.
// File Handling Features:
// 	•	Saving Student Data to a File:
// 	•	Save student details, including their name, roll number, age, address, courses, and grades, into a file when the program exits.
// 	•	Loading Student Data from a File:
// 	•	Load student details from the file when the program starts, so previously added data is available even after restarting the program.



#include<iostream>
#include<fstream>
using namespace std;

const int Max_course = 6;                                       // max courses a student can enroll
void copyString(char* destination, const char* source);         // Coping  string to destination string
int compareString(const char* str1, const char* str2);          // in this comparing two strings and returns 1 if they are equal,if not 0

class Student
{
private:
    char name[25];                                               // Student's name
    int rollNo;                                               // Student's roll number
    int age;                                                          // Student's age
    char address[50];                                               // Student's address
    char courses[Max_course][30];                                    // Array of course names
    int grades[Max_course];                             // Array of numbers "i used grades name variable" it actually numbers corresponding to the courses
    int courseCount;                                     // Number of courses the student is enrolled in

public:
    Student() : rollNo(0), age(0), courseCount(0) {}


    void setInfo(const char* StudentName, int studentRoll, int studentAge, const char* studentAddress);
    void enroll(const char* courseName, int grade);
    void remove(const char* courseName);
    double calculateGPA();
    void display();
    void saveToFile() const;
    void loadFromFile();
};
                                    //Above is the class and below is the main body function
                //---------------------------------------------------------------------------------------------------------------------

int main()
{
    cout << "VS Code is working!" << endl;
    Student obj1;
    int choice;
    
   
    while (1)
    {
        cout<<"_____________________________________________________________________________"<<endl;
        cout << "Displaying Menu..!" << endl;
        cout << "Press 1 to Set Student Info" << endl;
        cout << "Press 2 to Enroll in course" << endl;
        cout << "Press 3 to Remove the course" << endl;
        cout << "Press 4 to Display Student Information" << endl;
        cout << "Press 5 to Save into File" << endl;
        cout << "Press 6 to Load from the File" << endl;
        cout << "Press 7 to Exit" << endl;
        cout << "...";
        cin >> choice;

        // Handling menu choices
        if (choice == 1)
        {
            char name[25], address[50];
            int rollNo, age;
            cout << "Enter Student Name: ";
            cin.ignore();
            cin.getline(name, 25);
            cout << "Enter Student Roll No: ";
            cin >> rollNo;
            cout << "Enter student age: ";
            cin >> age;
            cout << "Enter Student Home address: ";
            cin.ignore();
            cin.getline(address, 50);
            obj1.setInfo(name, rollNo, age, address);
        }
        else if (choice == 2)
        {
            char course[30];
            int grade;
            cout << "Enter course NAME: ";
            cin.ignore();
            cin.getline(course, 30);
            cout << "Enter Grade: ";
            cin >> grade;
            obj1.enroll(course, grade);
        }
        else if (choice == 3)
        {
            char course[30];
            cout << "Enter the Course Name to remove: ";
            cin.ignore();
            cin.getline(course, 30);
            obj1.remove(course);
        }
        else if (choice == 4)
        {
            obj1.display();
        }
        else if (choice == 5)
        {
            obj1.saveToFile();
        }
        else if (choice == 6)
        {
            obj1.loadFromFile();
        }
        else if (choice == 7)
        {
            break;  // Exit the program
        }
    }
    cout<<"Code Written by Shumas Mazhar"<<endl;
    cout<<"_____________________________________________________________________________"<<endl;
    
}

                                //Above is the main function and below these are the class functions
                //---------------------------------------------------------------------------------------------------------------------

        
    void Student::setInfo(const char* StudentName, int studentRoll, int studentAge, const char* studentAddress)
    {
      copyString(name, StudentName);
         rollNo = studentRoll;
        age = studentAge;
        copyString(address, studentAddress);
    }

    void Student::enroll(const char* courseName, int grade)
    {
        if (grade < 0 || grade > 100)
        {
            cout << "Error: Numbers must be between 0 and 100." << endl;
            return;
        }

        if (courseCount >= Max_course)
        {
            cout << "You cannot enroll in more courses. Limit exceeded!" << endl;
            return;
        }

        for (int i = 0; i < courseCount; i++)
        {
            if (compareString(courses[i], courseName) == 1)
            {
                cout << "You are already enrolled in this course." << endl;
                return;
            }
        }

        copyString(courses[courseCount], courseName);
        grades[courseCount] = grade;
        courseCount++;
        cout << "Successfully enrolled in " << courseName << " with grade " << grade << "." << endl;
    }

    void Student::remove(const char* courseName)         // Removeing the course 
    {
        for (int i = 0; i < courseCount; i++)
        {
            if (compareString(courses[i], courseName) == 1)
            {
                for (int j = i; j < courseCount - 1; j++)
                {
                    copyString(courses[j], courses[j + 1]);
                    grades[j] = grades[j + 1];
                }
                courseCount--;
                cout << "Course Removed Successfully!" << endl;
                return;
            }
        }
        cout << "Course Not Found!" << endl;
    }

    double Student::calculateGPA()                    // Calculates and givesss the GPA of the student
    {
        if (courseCount == 0)
        {
            cout << "No courses enrolled!" << endl;
            return 0;
        }
        double sum = 0;
        for (int i = 0; i < courseCount; i++)
        {
            sum += grades[i];
        }
        return sum / courseCount;
    }

    void Student::display()          // Displaying student information
    {
        cout << "~Displaying Student Information~" << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student Roll No: " << rollNo << endl;
        cout << "Student Age: " << age << endl;
        cout << "Student Address: " << address << endl;

        cout << "~Courses and Grades~" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            cout << courses[i] << " : " << grades[i] << endl;
        }
        cout << "GPA: " << calculateGPA() << endl;
    }

    void Student::saveToFile() const                   // Saveing to a file
    {
        ofstream file("Students.txt", ios::app);
        if (file.is_open())
        {
            file << name << " , " << rollNo << " , " << age << " , " << address << " , " << courseCount << " , " << endl;
            for (int i = 0; i < courseCount; i++)
            {
                file << courses[i] << " , " << grades[i] << " , ";
            }
            file.close();
            cout << "Data saved to file..." << endl;
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }

    void Student::loadFromFile()                  // Loadin data from file
    {
        ifstream file("Students.txt");
        if (file.is_open())
        {
            file.getline(name, 25, ',');        // Reading g name
            file >> rollNo;                     
            file.ignore();                       // usedd this to clearr newline
            file >> age;                       
            file.ignore();                    // usedd this to clearr newline
            file.getline(address, 50, ',');     
            file >> courseCount;                
            file.ignore();                     

            for (int i = 0; i < courseCount; i++)
            {
                file.getline(courses[i], 30, ','); 
                file >> grades[i];                 
                file.ignore();                      // usedd this to clearr newline after grade
            }

            file.close();
            cout << "Data successfully loaded from file!" << endl;
        }
        else
        {
            cout << "Unable to open file!" << endl;
        }
    }
                            //Writing this line to differentiate between class functions 
                //---------------------------------------------------------------------------------------------------------------------
    void copyString(char* destination, const char* source)
    {
        int i = 0;
        while (source[i] != '\0') {
            destination[i] = source[i];
            i++;
        }
        destination[i] = '\0';
    }

    int compareString(const char* str1, const char* str2)
    {
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0')
        {
            if (str1[i] != str2[i])
            {
                return 0;
            }
            i++;
        }
        return (str1[i] == '\0' && str2[i] == '\0') ? 1 : 0;
    }
                //---------------------------------------------------------------------------------------------------------------------
