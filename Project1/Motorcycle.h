#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle {  
public:
	Motorcycle(long license);   // Constructor that accepts the motorcycle's license number

	void displayDetails() const;

	double calculateParkingTime() const;

	double calculateParkingCost() const;
};

