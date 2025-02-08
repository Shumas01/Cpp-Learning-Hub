

//---------------------------------------------------------------------------------------------------------------------

// Name: Muhammad Shumas Mazhar
// Registration: l1f23bscs1097
// Lab 15 OOPS
// Task 3

//---------------------------------------------------------------------------------------------------------------------

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
        size = 0.0;
        type = new char[1];
        strcpy(type, "");
    }
    Screen(int res, float sizee, const char *typee)
    {
        resolution = res;
        size = sizee;
        type = new char[strlen(typee) + 1];
        strcpy(type, typee);
    }

    void Display()
    {
        cout << "Details of the Screen " << endl;
        cout << "REsolution: " << resolution << endl;
        cout << "Size: " << size << endl;
        cout << "Type: " << type << endl;
    }
    ~Screen()
    {
        delete[] type;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class Battery
{
    int capacity;

public:
    Battery()
    {
        capacity = 0;
    }
    Battery(int cp)
    {
        capacity = cp;
    }
    void Display()
    {
        // Screen::Display();
        cout << "Battery Deatils:" << endl;
        cout << "Capacity: " << capacity << endl;
    }
};

//---------------------------------------------------------------------------------------------------------------------

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

    Smartphone(const char *br, int warr, int pr, int res, float sz, const char *tp, int cap)
            : Sobj(res, sz, tp), Bobj(cap)
    {
        brand = new char[strlen(br) + 1];
        strcpy(brand, br);
        warranty = warr;
        price = pr;
    }
    void Display(){
        cout<<"SMartphone Details"<<endl;
        cout<<"Warrantyy: "<<warranty<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Brand: "<<endl;
        Sobj.Display();
        Bobj.Display();
    }
    ~Smartphone(){
        delete[] brand;
    }


};

//---------------------------------------------------------------------------------------------------------------------

int main (){
    Smartphone phone1("Apple", 2, 999, 441, 6.1, "Applleee", 4000);
    phone1.Display();
}

//---------------------------------------------------------------------------------------------------------------------
