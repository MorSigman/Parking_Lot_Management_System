#include "Motorcycle.h"
#include <iostream>
#include <chrono>

using namespace std;

Motorcycle::Motorcycle(long license) : Vehicle(license, "Motorcycle") {} // Constructor for the Motorcycle class, calls the Vehicle constructor with the license number and "Motorcycle" as the vehicle type

void Motorcycle::displayDetails() const {
    cout << "Motorcycle license number: " << licenseNumber << endl;
}

double Motorcycle::calculateParkingTime() const {
    time_t currentTime;
    time(&currentTime);  

    double stayDuration = difftime(currentTime, parkingEntryTime) / 3600;   // Calculate the difference between the current time and the parking entry time in hours
    return stayDuration;  
}
double Motorcycle::calculateParkingCost() const {
    double hours = calculateParkingTime();
    return hours * 1.0;
}



