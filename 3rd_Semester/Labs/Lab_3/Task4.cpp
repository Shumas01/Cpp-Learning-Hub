
// #include <iostream>
// #include <cstring> // For strcpy
// using namespace std;

// // Define the value of pi manually
// const float PI = 3.14159;

// // Base class: Shape
// class Shape {
// protected:
//     char* color;
//     int sides;

// public:
//     // Parameterized Constructor
//     Shape(const char* color, int sides) {
//         cout << "Shape constructor called." << endl;
//         this->color = new char[strlen(color) + 1]; // Allocate memory for color
//         strcpy(this->color, color);
//         this->sides = sides;
//     }

//     // Virtual Method: area()
//     virtual float area() const = 0; // Pure virtual function

//     // Virtual Destructor
//     virtual ~Shape() {
//         cout << "Shape destructor called." << endl;
//         delete[] color; // Free allocated memory
//     }
// };

// // Derived Class: Circle
// class Circle : public Shape {
// private:
//     float radius;

// public:
//     // Constructor
//     Circle(const char* color, float radius)
//         : Shape(color, 0), radius(radius) { // Circle has 0 sides
//         cout << "Circle constructor called." << endl;
//     }

//     // Override area()
//     float area() const override {
//         return PI * radius * radius; // Area of a circle: πr²
//     }

//     // Destructor
//     ~Circle() {
//         cout << "Circle destructor called." << endl;
//     }

//     // Display details (optional)
//     void display() const {
//         cout << "Circle: Color = " << color
//              << ", Radius = " << radius
//              << ", Area = " << area() << endl;
//     }
// };

// // Derived Class: Rectangle
// class Rectangle : public Shape {
// private:
//     float width;
//     float height;

// public:
//     // Constructor
//     Rectangle(const char* color, float width, float height)
//         : Shape(color, 4), width(width), height(height) { // Rectangle has 4 sides
//         cout << "Rectangle constructor called." << endl;
//     }

//     // Override area()
//     float area() const override {
//         return width * height; // Area of a rectangle: width * height
//     }

//     // Destructor
//     ~Rectangle() {
//         cout << "Rectangle destructor called." << endl;
//     }

//     // Display details (optional)
//     void display() const {
//         cout << "Rectangle: Color = " << color
//              << ", Width = " << width
//              << ", Height = " << height
//              << ", Area = " << area() << endl;
//     }
// };

// // Main function
// int main() {
//     // Create an array of pointers to Shape
//     Shape* shapes[3];

//     // Add Circle and Rectangle objects to the array
//     shapes[0] = new Circle("Red", 5.0);        // Circle with radius 5.0
//     shapes[1] = new Rectangle("Blue", 4.0, 6.0); // Rectangle with width 4.0 and height 6.0
//     shapes[2] = new Circle("Green", 3.0);     // Circle with radius 3.0

//     // Loop through the array and display details
//     for (int i = 0; i < 3; i++) {
//         cout << "Shape " << i + 1 << " details: " << endl;
//         shapes[i]->area(); // Demonstrate dynamic polymorphism
//     }

//     cout << endl;

//     // Destructor Observation
//     cout << "Deleting objects from the array..." << endl;
//     for (int i = 0; i < 3; i++) {
//         delete shapes[i]; // Proper cleanup using the base class pointer
//     }

//     return 0;
// }
