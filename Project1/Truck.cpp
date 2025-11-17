#include "Truck.h"
#include <iostream>
#include <chrono>

using namespace std;

// Constructor for the Truck class, initializes the truck with a license number and sets its vehicle type as "Truck"
Truck::Truck(long license) : Vehicle(license, "Truck") {}

void Truck::displayDetails() const {
    cout << "Truck license number: " << licenseNumber << endl;
}

double Truck::calculateParkingTime() const {
    time_t currentTime;
    time(&currentTime);  

    double stayDuration = difftime(currentTime, parkingEntryTime) / 3600;    // Calculate the duration of the truck's stay in hours by finding the difference between the current time and the parking entry time
    return stayDuration;  
}

double Truck::calculateParkingCost() const {
    double hours = calculateParkingTime();
    return hours * 100.0;
}
