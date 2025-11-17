#pragma once
#include "Vehicle.h" 

class Car : public Vehicle {    
public:
    Car(long license);     // Constructor that accepts the car's license number

    void displayDetails() const;

    double calculateParkingTime() const;  

    double calculateParkingCost() const; 
};
