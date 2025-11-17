#pragma once

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(long license); // Constructor that accepts the truck's license number

    void displayDetails() const;

    double calculateParkingTime() const;

    double calculateParkingCost() const;
};


