 
//---------------------------------------------------------------------------------------------------------------------
 
 
 //Name: Muhammad Shumas Mazhar
 //Registration: l1f23bscs1097
 //Lab 14 OOPS
 //Task 1

//---------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <cstring>

using namespace std;

class Class {
protected:
    char* className;
    int duration;
    char* courseTeacher;

public:
    Class() {
        cout << "Class constructor called." << endl;
        className = nullptr;
        duration = 0;
        courseTeacher = nullptr;
    }

    Class(const char* name, int dur, const char* teacher) {
        className = new char[strlen(name) + 1];
        strcpy(className, name);
        duration = dur;
        courseTeacher = new char[strlen(teacher) + 1];
        strcpy(courseTeacher, teacher);
    }

    virtual ~Class() {
        delete[] className;
        delete[] courseTeacher;
    }

    virtual void displayInfo() const {
        cout << "Class Name: " << className << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Course Teacher: " << courseTeacher << endl;
    }
};

 //---------------------------------------------------------------------------------------------------------------------

class OnlineClass : virtual public Class {
protected:
    char* platform;

public:
    OnlineClass() {
        cout << "OnlineClass constructor called." << endl;
        platform = nullptr;
    }

    OnlineClass(const char* name, int dur, const char* teacher, const char* plat)
        : Class(name, dur, teacher) {
        platform = new char[strlen(plat) + 1];
        strcpy(platform, plat);
    }

    ~OnlineClass() {
        delete[] platform;
    }

    void displayInfo() const override {
        Class::displayInfo();
        cout << "Platform: " << platform << endl;
    }
};

 //---------------------------------------------------------------------------------------------------------------------

class PhysicalClass : virtual public Class {
protected:
    char* roomNumber;
    int maxCapacity;

public:
    PhysicalClass() {
        cout << "PhysicalClass constructor called." << endl;
        roomNumber = nullptr;
        maxCapacity = 0;
    }

    PhysicalClass(const char* name, int dur, const char* teacher, const char* room, int capacity)
        : Class(name, dur, teacher) {
        roomNumber = new char[strlen(room) + 1];
        strcpy(roomNumber, room);
        maxCapacity = capacity;
    }

    ~PhysicalClass() {
        delete[] roomNumber;
    }

    void displayInfo() const override {
        Class::displayInfo();
        cout << "Room Number: " << roomNumber << endl;
        cout << "Max Capacity: " << maxCapacity << endl;
    }

    bool isRoomAvailable(int currentStudents) const {
        return currentStudents < maxCapacity;
    }

    string calculateOvercrowding(int currentStudents) const {
        if (currentStudents < maxCapacity)
            return "Room has available space.";
        else if (currentStudents == maxCapacity)
            return "Room is at capacity.";
        else
            return "Room is over capacity!";
    }
};

 //---------------------------------------------------------------------------------------------------------------------

class HybridClass : public OnlineClass, public PhysicalClass {
private:
    int courseCredits;
    int totalStudents;
    int maxStudents;

public:
    HybridClass() {
        cout << "HybridClass constructor called." << endl;
        courseCredits = 0;
        totalStudents = 0;
        maxStudents = 0;
    }

    HybridClass(const char* name, int dur, const char* teacher, const char* plat, const char* room, int capacity, int credits, int maxStu)
        : Class(name, dur, teacher), OnlineClass(name, dur, teacher, plat), PhysicalClass(name, dur, teacher, room, capacity) {
        courseCredits = credits;
        totalStudents = 0;
        maxStudents = maxStu;
    }

    void displayInfo() const override {
        OnlineClass::displayInfo();
        PhysicalClass::displayInfo();
        cout << "Course Credits: " << courseCredits << endl;
        cout << "Total Students: " << totalStudents << "/" << maxStudents << endl;
    }

    void addStudent() {
        if (totalStudents < maxStudents) {
            totalStudents++;
            cout << "Student added. Total students: " << totalStudents << "/" << maxStudents << endl;
        } else {
            cout << "Cannot add student. Class is at maximum capacity." << endl;
        }
    }
};

int main() {
    HybridClass hybridClass;

    HybridClass paramHybrid("Programming Fundamentals", 3, "Dr. Smith", "Zoom", "Room 101", 50, 3, 60);

    paramHybrid.displayInfo();

    paramHybrid.addStudent();
    paramHybrid.addStudent();

    cout << paramHybrid.calculateOvercrowding(60) << endl;

    return 0;
}

 //---------------------------------------------------------------------------------------------------------------------
