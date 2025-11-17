#include "Car.h"
#include <iostream>
#include <chrono>  

using namespace std;


Car::Car(long license) : Vehicle(license, "Car") {} // Constructor for the Car class, calls the base class (Vehicle) constructor with "Car" as the vehicle type


void Car::displayDetails() const {
    cout << "Car license number: " << licenseNumber << endl;
}

double Car::calculateParkingTime() const {
    time_t currentTime;
    time(&currentTime); 

    double stayDuration = difftime(currentTime, parkingEntryTime) / 3600;     // Calculate the difference between the current time and the parking entry time in hours
    return stayDuration; 
}

double Car::calculateParkingCost() const {
    double hours = calculateParkingTime();  
    return hours * 5.0; 
}
