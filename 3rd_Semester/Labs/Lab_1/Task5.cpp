#include<iostream>
#include<string>
using namespace std;

//------------------------------------------------------------------------------------------
void average(int a, int b) {
    double avg = (a + b) / 2.0;
    cout << "The average of two integers (" << a << ", " << b << ") is: " << avg << endl;
}
void average(double a, double b) {
    double avg = (a + b) / 2.0;
    cout << "The average of two doubles (" << a << ", " << b << ") is: " << avg << endl;
}

double area(float length) {
    return length * length;
}
double area(int base, int height) {
    return 0.5 * base * height;
}
double area(int radius) {
    return 3.14 * radius * radius;
}

//------------------------------------------------------------------------------------------
class Rectangle {
    private:
        int length;
        int width;
    public:
        void set();
        void display();
        void calculateArea();
};
void Rectangle::set() {
    cout << "Enter Length and Width of the Rectangle: ";
    cin >> length >> width;
}
void Rectangle::display() {
    cout << "Length: " << length << " & Width: " << width << endl;
}
void Rectangle::calculateArea() {
    cout << "Area of the Rectangle is: " << length * width << endl;
}

//------------------------------------------------------------------------------------------
class Student {
    private:
        string name, id, degree, grade;
        float gpa, percentage;
        double totalMarks, obtainedMarks;
    public:
        void set();
        void assignGrade();
        void display();
};
void Student::set() {
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter CGPA: ";
    cin >> gpa;
    cout << "Degree Program: ";
    cin.ignore();
    getline(cin, degree);
    cout << "Enter Total Marks and Obtained Marks: ";
    cin >> totalMarks >> obtainedMarks;
    percentage = (totalMarks > 0) ? (obtainedMarks / totalMarks) * 100 : 0;
}
void Student::assignGrade() {
    if (percentage >= 86) grade = "A+";
    else if (percentage >= 80) grade = "A";
    else if (percentage >= 75) grade = "B+";
    else if (percentage >= 69) grade = "B";
    else if (percentage >= 62) grade = "B-";
    else if (percentage >= 58) grade = "C+";
    else if (percentage >= 53) grade = "C";
    else if (percentage >= 47) grade = "C-";
    else if (percentage >= 40) grade = "D";
    else grade = "F";
}
void Student::display() {
    cout << "Student Name: " << name << ", ID: " << id << ", CGPA: " << gpa << endl;
    cout << "Degree Program: " << degree << ", Total Marks: " << totalMarks << ", Obtained Marks: " << obtainedMarks << endl;
    cout << "Percentage: " << percentage << "%, Grade: " << grade << endl;
}

//------------------------------------------------------------------------------------------
void testAvg() {
    int a = 3, b = 6;
    average(a, b);

    double x = 4.5, y = 7.8;
    average(x, y);
}

void testArea() {
    cout << "Area of square with length 4.0: " << area(4.0f) << endl;
    cout << "Area of triangle with base 5 and height 6: " << area(5, 6) << endl;
    cout << "Area of circle with radius 3: " << area(3) << endl;
}

void testRectangle() {
    Rectangle r1;
    r1.set();
    r1.display();
    r1.calculateArea();
}

void testStudent() {
    int num;
    cout << "How many students data do you want to enter? ";
    cin >> num;
    Student* students = new Student[num];
    for (int i = 0; i < num; ++i) {
        cout << "\n--- Entering data for student " << (i + 1) << " ---" << endl;
        students[i].set();
        students[i].assignGrade();
    }
    cout << "\n--- Displaying student information ---" << endl;
    for (int i = 0; i < num; ++i) {
        students[i].display();
    }
    delete[] students;
}


//------------------------------------------------------------------------------------------






















//------------------------------------------------------------------------------------------
int main() {
    int choice;
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Test Average Function\n2. Test Area Function\n3. Test Rectangle Class\n4. Test Student Class\n5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: testAvg(); break;
            case 2: testArea(); break;
            case 3: testRectangle(); break;
            case 4: testStudent(); break;
            case 5: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
