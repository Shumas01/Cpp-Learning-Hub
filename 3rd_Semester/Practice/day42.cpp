// Base Class: Class
// Attributes:
// 	•	className (char *) – The name of the class.
// 	•	duration (int) – Duration of the class in hours.
// 	•	courseTeacher (char *) – Name of the course teacher.
// Functions:
// 	•	Constructor: Implement a parameterized constructor to initialize className, duration, and courseTeacher.
// 	•	Default Constructor: Implement a default constructor that prints a message like "Class constructor called."
// 	•	displayInfo(): Implement a virtual function that displays class details.

#include <iostream>
#include <cstring>
using namespace std;

class Class
{
    char *charName;
    int duration;
    char *courseTeacher;

public:
    Class()
    {

        duration = 0;
        charName = new char[1];
        strcpy(charName, "");

        courseTeacher = new char[1];
        strcpy(courseTeacher, "");
        cout << "Class constrcutor called..!" << endl;
    }
    Class(const char *name, int dur, const char *Teacher)
    {
        charName = new char[strlen(name) + 1];
        strcpy(charName, name);

        duration = dur;

        courseTeacher = new char[strlen(Teacher) + 1];
        strcpy(courseTeacher, Teacher);
    }
    virtual void Display()
    {
        cout << "Name: " << charName << endl;
        cout << "Duration: " << duration << endl;
        cout << "Teacher: " << courseTeacher << endl;
    }
    ~Class()
    {
        delete[] charName;
        delete[] courseTeacher;
    }
};

// Derived (from Class): OnlineClass
// Attributes:
// 	•	platform (char *) – The platform used for the online class.
// Functions:
// 	•	Constructor: Implement a constructor to initialize className, duration, courseTeacher, platform by calling the base class constructor.
// 	•	Default Constructor: Implement a default constructor that prints a message like "OnlineClass constructor called."
// 	•	display(): Override to include platform.

class OnlineClass : virtual public Class
{

    char *platform;

public:
    OnlineClass()
    {
        cout << "Default COnstrcutor of Online class Called" << endl;

        platform = new char[1];
        strcpy(platform, "");
    }
    OnlineClass(const char *name, int dur, const char *Teacher, const char *Platf) : Class(name, dur, Teacher)
    {
        platform = new char[strlen(Platf) + 1];
        strcpy(platform, Platf);
    }
    void Display()
    {
        Class::Display();
        cout << "Platform is: " << platform << endl;
    }
    ~OnlineClass()
    {
        delete[] platform;
    }
};

// Derived (from Class): PhysicalClass
// Attributes:
// 	•	roomNumber (char *) – The specific room number for the class.
// Functions:
// 	•	Constructor: Implement a constructor to initialize className, duration, courseTeacher, roomNumber, and maxCapacity by calling the base class constructor.
// 	•	Default Constructor: Implement a default constructor that prints a message like "PhysicalClass constructor called."
// 	•	display(): Override to include room number and capacity.
// 	•	isRoomAvailable(int currentStudents): Checks if there’s space in the room for additional students.
// 	•	calculateOvercrowding(int currentStudents): A function that checks if the room is overcrowded and returns:
// 	•	A message indicating whether the room is at capacity, over capacity, or has available space.
// 	•	This should take the current number of students and compare it to maxCapacity.

class PhysicalClass :virtual public Class
{
    char *roomNumber;
    int Capacity;

public:
    PhysicalClass()
    {
        cout << "Physical Class COnstrcutor called" << endl;
        Capacity = 0;

        roomNumber = new char[1];
        strcpy(roomNumber, " ");
    }
    PhysicalClass(const char *name, int dur, const char *Teacher, int cap, const char *room) : Class(name, dur, Teacher)
    {

        Capacity = cap;
        roomNumber = new char[strlen(room) + 1];
        strcpy(roomNumber, room);
    }

    void Display()
    {
        Class::Display();
        cout << "Room Number: " << roomNumber << endl;
        cout << "Max Capacity: " << Capacity << endl;
    }

    bool isRoomAvailable(int currentStudents) const
    {
        return currentStudents < Capacity;
    }

    void CalculateOverCrowding(int currentStudents) const
    {
        if (currentStudents < Capacity)
        {
            cout << "Room is available" << endl;
        }
        else if (currentStudents > Capacity)
        {
            cout << "No Room is Available" << endl;
        }
        else if (currentStudents == Capacity)
        {
            cout << "Room is overCrowded by " << currentStudents - Capacity << " Students" << endl;
        }
    }
    ~PhysicalClass()
    {
        delete[] roomNumber;
    }
};

// Derived (from OnlineClass and PhysicalClass): HybridClass
// Attributes:
// 	•	courseCredits (int) – Number of credits for the course.
// 	•	totalStudents (int) – Current number of students enrolled.
// 	•	maxStudents (int) – Maximum number of students for the hybrid class.
// Functions:
// 	•	Constructor: Implement a constructor to initialize all attributes by calling the constructors of OnlineClass and PhysicalClass.
// 	•	Default Constructor: Implement a default constructor that prints a message like "HybridClass constructor called."
// 	•	display(): Override to combine details from both parents and display all relevant information.
// 	•	addStudent(): The function will add a student, making sure that total students do not exceed the maximum allowed capacity.

class HybridClass :virtual public OnlineClass,virtual public PhysicalClass
{
    int courseCredits;
    int totalStudents;
    int maxStudents;

public:
    HybridClass()
    {
        cout << "Default Hybrdid COnstrcutor Called" << endl;
        courseCredits = 0;
        totalStudents = 0;
        maxStudents = 0;
    }
    HybridClass(const char *name, int dur, const char *Teacher, const char *Platf,
                 int cap, const char *room,
                int credit, int totalStud, int max)
        : OnlineClass(name, dur, Teacher, Platf), 
          PhysicalClass(name, dur, Teacher, cap, room)
    {

        courseCredits=credit;
        totalStudents=0;
        maxStudents=max;
    }
    void Display (){
        OnlineClass::Display();
        PhysicalClass::Display();
        cout<<"Course Creddits: "<<courseCredits<<endl;
        cout<<"total STudents: "<<totalStudents<<endl;
        cout<<"Maximum Students: "<<maxStudents<<endl;

    }
    void AddStudent(){
        if(totalStudents<maxStudents){
            totalStudents++;
            cout<<"Student Added Successfully"<<endl;
        }else if(totalStudents==maxStudents){
            cout<<"Cannot Add more Students"<<endl;
        }
    }
    ~HybridClass(){
        cout<<""<<endl;
    }
};

int main (){

    // HybridClass H1;
    HybridClass H2("Computer Science", 20,"Sibghatullah","University",50,"Zoom",20000,100,200);
    H2.Display();
}

// Main Function:
// 	•	Create an object of the HybridClass using the default constructor.
// 	•	Observe the output to see the order in which constructors are called.
// 	•	Call the display() function on the HybridClass object and check the combined details of the class.
// 	•	Add students to the HybridClass object using addStudent() and check available seats after each addition.
// Instructions for Students:
// 	•	Virtual Inheritance Usage: Understand how virtual inheritance helps in managing shared attributes and resolving ambiguity between derived classes.
// 	•	Constructor Behavior: Observe the order of constructor calls to understand the initialization process in derived classes.
// 	•	Discussion Points: Discuss the implications of using virtual inheritance, including its impact on constructors and destructors, and how it helps manage class hierarchies effectively.
