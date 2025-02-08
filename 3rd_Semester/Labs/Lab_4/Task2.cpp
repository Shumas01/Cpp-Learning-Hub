//---------------------------------------------------------------------------------------------------------------------
 
 
 //Name: Muhammad Shumas Mazhar
 //Registration: l1f23bscs1097
 //Lab 14 OOPS
 //Task 2

//---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>

using namespace std;

class Engine {
private:
    int horsepower;
    int fuelCapacity;
    int displacement;

public:
    Engine() {
        horsepower = 0;
        fuelCapacity = 0;
        displacement = 0;
        cout << "Engine constructor called." << endl;
    }

    Engine(int hp, int fuelCap, int disp) {
        horsepower = hp;
        fuelCapacity = fuelCap;
        displacement = disp;
    }

    void display() const {
        cout << "Engine Details:" << endl;
        cout << "Horsepower: " << horsepower << " HP" << endl;
        cout << "Fuel Capacity: " << fuelCapacity << " liters" << endl;
        cout << "Displacement: " << displacement << " CC" << endl;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class Car {
private:
    char* brand;
    char* model;
    int year;
    Engine engine;

public:
    Car() : engine() {
        brand = nullptr;
        model = nullptr;
        year = 0;
        cout << "Car constructor called." << endl;
    }

    Car(const char* carBrand, const char* carModel, int manufactureYear, int hp, int fuelCap, int disp)
        : engine(hp, fuelCap, disp) {
        brand = new char[strlen(carBrand) + 1];
        strcpy(brand, carBrand);

        model = new char[strlen(carModel) + 1];
        strcpy(model, carModel);

        year = manufactureYear;
    }

    ~Car() {
        delete[] brand;
        delete[] model;
    }

    void display() const {
        cout << "Car Details:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        engine.display();
    }
};

//---------------------------------------------------------------------------------------------------------------------

int main() {
    Car car1("Toyota", "Corolla", 2022, 140, 50, 1800);
    car1.display();

    cout << endl;

    Car car2;
    car2.display();

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------

