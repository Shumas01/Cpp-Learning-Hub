
#include <iostream>
using namespace std;

// Base Class: Vehicle
class Vehicle {
protected:
    double fuelCapacity;      // Capacity of the fuel tank in liters
    double distanceTravelled; // Distance travelled by the vehicle in kilometers

public:
    // Parameterized Constructor
    Vehicle(double fuel, double distance) : fuelCapacity(fuel), distanceTravelled(distance) {}

    // Display Function
    virtual void display() {
        cout << "Fuel Capacity: " << fuelCapacity << " liters" << endl;
        cout << "Distance Travelled: " << distanceTravelled << " kilometers" << endl;
    }

    // Virtual Function for Fuel Efficiency Calculation
    virtual double calculateFuelEfficiency() {
        return distanceTravelled / fuelCapacity;
    }

    // Virtual Destructor
    virtual ~Vehicle() {}
};

// Derived Class: Car
class Car : public Vehicle {
private:
    int maxSpeed; // Maximum speed limit for Car
    int speed;    // Current speed for Car

public:
    // Constructor
    Car(double fuel, double distance, int maxSpd, int spd) 
        : Vehicle(fuel, distance), maxSpeed(maxSpd), speed(spd) {}

    // Override display function
    void display()  {
        Vehicle::display();
        cout << "Max Speed: " << maxSpeed << " km/h" << endl;
        cout << "Current Speed: " << speed << " km/h" << endl;
    }

    // Override calculateFuelEfficiency function
    double calculateFuelEfficiency() {
        double efficiency = Vehicle::calculateFuelEfficiency();
        if (speed <= maxSpeed) {
            efficiency += 4; // Increase efficiency by 4 if within max speed
        }
        return efficiency;
    }
};

// Derived Class: Truck
class Truck : public Vehicle {
private:
    int payLoadCapacity; // Pay load capacity in tons

public:
    // Constructor
    Truck(double fuel, double distance, int payload) 
        : Vehicle(fuel, distance), payLoadCapacity(payload) {}

    // Override display function
    void display()  {
        Vehicle::display();
        cout << "Payload Capacity: " << payLoadCapacity << " tons" << endl;
    }

    // Override calculateFuelEfficiency function
    double calculateFuelEfficiency() {
        double efficiency = Vehicle::calculateFuelEfficiency();
        if (payLoadCapacity > 30) {
            efficiency *= 0.93; // Decrease efficiency by 7% if payload exceeds 30 tons
        }
        return efficiency;
    }
};

// Main Function
int main() {
    // Create an object of the base class Vehicle
    Vehicle vehicle(50, 500);
    vehicle.display();
    cout << "Fuel Efficiency (Vehicle): " << vehicle.calculateFuelEfficiency() << " km/l" << endl;
    cout << endl;

    // Create an object of the derived class Car
    Car car(40, 400, 120, 100);
    car.display();
    cout << "Fuel Efficiency (Car): " << car.calculateFuelEfficiency() << " km/l" << endl;
    cout << endl;

    // Create an object of the derived class Truck
    Truck truck(100, 800, 35);
    truck.display();
    cout << "Fuel Efficiency (Truck): " << truck.calculateFuelEfficiency() << " km/l" << endl;
    cout << endl;

    // Assign a subclass object (Car) to a superclass object (Vehicle)
    Vehicle vehicleAsCar = car;
    vehicleAsCar.display();
    cout << "Fuel Efficiency (Vehicle as Car): " << vehicleAsCar.calculateFuelEfficiency() << " km/l" << endl;
    cout << endl;

    // Assign a subclass object to a superclass pointer
    Vehicle* vehiclePtr = &truck;
    vehiclePtr->display();
    cout << "Fuel Efficiency (Vehicle pointer to Truck): " << vehiclePtr->calculateFuelEfficiency() << " km/l" << endl;

    return 0;
}
