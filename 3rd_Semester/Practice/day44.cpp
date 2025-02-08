
// Class: Screen
// Attributes:
// 	•	resolution (int) – The resolution of the screen in dpi (e.g.,441 or 403).
// 	•	size (float) – The size of the screen in inches.
// 	•	type (char *) – The type of screen (e.g., "OLED", "LCD").
// Functions:
// 	•	Constructor: Implement a parameterized constructor to initialize resolution, size, type.
// 	•	Default Constructor: Implement a default constructor that initializes default values and prints "Screen constructor called."
// 	•	display(): Implement a function that displays the screen's details.

#include <iostream>
#include <cstring>
using namespace std;

class Screen
{
    int resolution;
    float size;
    char *type;

public:
    Screen()
    {
        resolution = 0;
        size = 0;
        type = new char[1];
        strcpy(type, "");
    }
    Screen(int reso, float sizee, const char *typee)
    {

        resolution = reso;
        size = sizee;
        type = new char[strlen(typee) + 1];
        strcpy(type, typee);
    }
    void Display()
    {
        cout << "Type of the screen: " << type << endl;
        cout << "Resolution: " << resolution << endl;
        cout << "Size: " << size << endl;
    }
    ~Screen()
    {
        delete[] type;
    }
};

// Class: Battery
// Attributes:
// 	•	capacity (int) – The battery capacity in (mAh).
// Functions:
// 	•	Constructor: Implement a parameterized constructor to initialize capacity.
// 	•	Default Constructor: Implement a default constructor that initializes default values and prints "Battery constructor called."
// 	•	display(): Implement a function that displays the battery's details.

class Battery
{
public:
    int capacity;
    Battery()
    {
        capacity = 0;
    }
    Battery(int cap)
    {
        capacity = cap;
    }
    void Display()
    {
        cout << "Battery capacity: " << capacity <<" mAH"<< endl;
    }
};

// Base Class: Smartphone
// Attributes:
// 	•	brand (char *) – The manufacturer of the smartphone.
// 	•	screen (an object of Screen class) – The screen of the smartphone.
// 	•	battery (an object of Battery class) – The battery of the smartphone.
// 	•	warranty (int) – Warranty of the device in years.
// 	•	price (int) – Price of smartphone.
// Functions:
// 	•	Constructor: Implement a parameterized constructor to initialize brand, warranty, price and create objects for Screen and Battery.
// 	•	Default Constructor: Implement a default constructor that initializes default values and prints "Smartphone constructor called."
// 	•	display(): Implement a function that displays the smartphone's details, including the screen and battery details.
// 	•	batteryConsumption(float currentPercentage, int hoursUsed):

// 	•	This function calculates the battery’s power consumed (in mAh) since its full charged, based on the current battery percentage.
// 	•	Then it should estimate that how many further hours the battery will last until it is completely drained based on the consumption rate calculated above (this will be calculated based on user’s choice)

class Smartphone
{
    char *brand;
    int warranty;
    int price;
    Screen Sobj;
    Battery Bobj;

public:
    Smartphone()
    {
        warranty = 0;
        price = 0;
        brand = new char[1];
        strcpy(brand, "");
    }
    Smartphone(const char *br, int warr, int pricee, int reso, float sizee, const char *typee, int cap)
        : Sobj(reso, sizee, typee),
          Bobj(cap)
    {
        warranty = warr;
        price = pricee;
        brand = new char[strlen(br) + 1];
        strcpy(brand, br);
    }
    void Display()
    {
        cout << "Brand of the Smartphone: " << brand << endl;
        cout << "Warranty: " << warranty << endl;
        cout << "Price: " << price << endl;
        Sobj.Display();
        Bobj.Display();
    }
    ~Smartphone(){
        delete[]brand;
    }
};

int main()
{
    Smartphone S1("QMobile",2,20000,1260,10,"LED",10);
    S1.Display();
}