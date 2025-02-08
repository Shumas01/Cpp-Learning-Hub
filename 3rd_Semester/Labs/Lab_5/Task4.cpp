

//---------------------------------------------------------------------------------------------------------------------

// Name: Muhammad Shumas Mazhar
// Registration: l1f23bscs1097
// Lab 15 OOPS
// Task 1

//---------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <cstring>
using namespace std;

class Class
{
protected:
    char *className;
    int duration;
    char *courseTeacher;

public:
    Class()
    {
        cout << "Calling Class Constructor" << endl;
        className = nullptr;
        courseTeacher = nullptr;
        duration = 0;
    }

    Class(const char *name, int dur, const char *teacher)
    {
        className = new char[strlen(name) + 1];
        strcpy(className, name);
        courseTeacher = new char[strlen(teacher) + 1];
        strcpy(courseTeacher, teacher);
        duration = dur;
    }

    virtual void displayInfo() const
    {
        cout << "Class Name: " << className << endl;
        cout << "Duration: " << duration << " hrs" << endl;
        cout << "Course Teacher: " << courseTeacher << endl;
    }

    virtual ~Class()
    {
        delete[] className;
        delete[] courseTeacher;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class OnlineClass : virtual public Class
{
protected:
    char *platform;

public:
    OnlineClass() : Class()
    {
        cout << "Calling OnliceClass Constructor" << endl;
        platform = nullptr;
    }

    OnlineClass(const char *name, int dur, const char *teacher, const char *plt)
        : Class(name, dur, teacher)
    {
        platform = new char[strlen(plt) + 1];
        strcpy(platform, plt);
    }

    virtual void displayInfo() const override
    {
        Class::displayInfo();
        cout << "Platform: " << platform << endl;
    }

    ~OnlineClass()
    {
        delete[] platform;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class PhysicalClass : virtual public Class
{
protected:
    char *roomNumber;
    int maxCapacity;

public:
    PhysicalClass() : Class()
    {
        cout << "Calling Physical Class Constructor" << endl;
        roomNumber = nullptr;
        maxCapacity = 0;
    }

    PhysicalClass(const char *name, int dur, const char *teacher, const char *room, int capacity)
        : Class(name, dur, teacher)
    {
        roomNumber = new char[strlen(room) + 1];
        strcpy(roomNumber, room);
        maxCapacity = capacity;
    }

    virtual void displayInfo() const override
    {
        Class::displayInfo();
        cout << "Room Number: " << roomNumber << endl;
        cout << "Max Capacity: " << maxCapacity << endl;
    }

    bool isRoomAvailable(int currentStudents) const
    {
        return currentStudents < maxCapacity;
    }

    void calculateOvercrowding(int currentStudents) const
    {
        if (currentStudents < maxCapacity)
        {
            cout << "Available space: " << (maxCapacity - currentStudents) << endl;
        }
        else if (currentStudents == maxCapacity)
        {
            cout << "Room is at full capacity." << endl;
        }
        else
        {
            cout << "Room is overcrowded by " << (currentStudents - maxCapacity) << " students." << endl;
        }
    }

    ~PhysicalClass()
    {
        delete[] roomNumber;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class HybridClass : public OnlineClass, public PhysicalClass
{
private:
    int courseCredits;
    int totalStudents;
    int maxStudents;

public:
    HybridClass() : Class(), OnlineClass(), PhysicalClass()
    {
        cout << "Calling Hybrid Class Constrcutor" << endl;
        courseCredits = 0;
        totalStudents = 0;
        maxStudents = 0;
    }

    HybridClass(const char *name, int dur, const char *teacher, const char *plt,
                const char *room, int capacity, int credits, int maxStd)
        : Class(name, dur, teacher), OnlineClass(name, dur, teacher, plt),
          PhysicalClass(name, dur, teacher, room, capacity)
    {
        courseCredits = credits;
        totalStudents = 0;
        maxStudents = maxStd;
    }

    virtual void displayInfo() const override
    {
        OnlineClass::displayInfo();
        cout << "Room Number: " << roomNumber << endl;
        cout << "Max Capacity: " << maxCapacity << endl;
        cout << "Course Credits: " << courseCredits << endl;
        cout << "Total Students: " << totalStudents << endl;
        cout << "Max Students: " << maxStudents << endl;
    }

    void addStudent()
    {
        if (totalStudents < maxStudents)
        {
            totalStudents++;
            cout << "Student added. Total Students: " << totalStudents << endl;
        }
        else
        {
            cout << "Cannot add student. Class is full." << endl;
        }
    }

    ~HybridClass()
    {
        cout << "HybridClass destructor called." << endl;
    }
};

//---------------------------------------------------------------------------------------------------------------------

int main()
{
    HybridClass hybrid;
    cout<<endl;
    cout << "---- Observing Constructor Output ----" << endl;

    HybridClass advancedCourse( "Data Structures", 3, "Dr. Smith", "Zoom",
                                "Room 101", 50, 4, 90);

    cout<<endl;
    cout << "---- Display HybridClass Details ----" << endl;
    advancedCourse.displayInfo();
    cout<<endl;
    cout << "---- Adding Students ----" << endl;
    for (int i = 0; i < 105; ++i)
    {
        advancedCourse.addStudent();
    }

   
}
//---------------------------------------------------------------------------------------------------------------------


