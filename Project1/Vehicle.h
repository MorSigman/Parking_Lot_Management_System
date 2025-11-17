#pragma once
#include <iostream>  
#include <string>  
#include <ctime >  

using namespace std;

class Vehicle {   // Abstract base class for different types of vehicles
protected:
	long licenseNumber;
	string vehicleType;
	time_t parkingEntryTime;  
	time_t departureTime;  

public:
	Vehicle(long license, string type);	

	virtual void displayDetails() const = 0;      // Pure virtual function to display the vehicle details (must be implemented by derived classes)

	virtual double calculateParkingTime() const = 0; // Pure virtual function to calculate the parking time

	virtual double calculateParkingCost() const = 0; // Pure virtual function to calculate the parking cost 

	void setDepartureTime(); 

	long getLicenseNumber() const { return licenseNumber; }     // Getter function for license number

	string getVehicleType() const { return vehicleType; }     // Getter function for vehicle type

	const char* getParkingEntryTime() const;  // Function to return the parking entry time in format


	virtual ~Vehicle() {} // Virtual destructor

};
