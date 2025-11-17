#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include "Car.h"
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Truck.h"
#include <iostream>
#include <fstream>   // For file handling (reading and writing to files)
#include <sstream>   // For using stringstream


using namespace std;

// Constructor to initialize the parking spots for cars, motorcycles, and trucks
Parking::Parking(int freeCarCount, int freeMotorcycleCount, int freeTruckCount)
    : freeCarParking(freeCarCount), freeMotorcycleParking(freeMotorcycleCount), freeTruckParking(freeTruckCount) {}

// Overload of operator+ to add a vehicle to the parking lot
Parking& Parking::operator+(Vehicle* vehicle) { 
    for (const Vehicle* car : parkedCars) {
        if (car->getLicenseNumber() == vehicle->getLicenseNumber()) {      // Check if the car is already parked
            cout << "This car is already parked." << endl;
            delete vehicle; // Free memory
            return *this; // Return the current Parking object
        }
    }
    for (const Vehicle* motorcycle : parkedMotorcycles) {     // Check if the motorcycle is already parked
        if (motorcycle->getLicenseNumber() == vehicle->getLicenseNumber()) {
            cout << "This motorcycle is already parked." << endl;
            delete vehicle; 
            return *this; 
        }
    }
    for (const Vehicle* truck : parkedTrucks) {     // Check if the truck is already parked
        if (truck->getLicenseNumber() == vehicle->getLicenseNumber()) {
            cout << "This truck is already parked." << endl;
            delete vehicle;  
            return *this; 
        }
    }

    // Add the vehicle to the correct parking vector if space is available
    if (vehicle->getVehicleType() == "Car" && freeCarParking > 0) {      

        parkedCars.push_back(vehicle);  // Add car to the vector
        freeCarParking--; // Reduce available car parking spots
        cout << "Another car in the parking lot. Available spaces for cars: " << freeCarParking << endl;

    }
    else if (vehicle->getVehicleType() == "Motorcycle" && freeMotorcycleParking > 0) {
        parkedMotorcycles.push_back(vehicle);  
        freeMotorcycleParking--;
        cout << "Another motorcycle in the parking lot. Available spaces for motorcycles: " << freeMotorcycleParking << endl;

    }
    else if (vehicle->getVehicleType() == "Truck" && freeTruckParking > 0) {
        parkedTrucks.push_back(vehicle);  
        freeTruckParking--;
        cout << "Another truck in the parking lot. Available spaces for trucks: " << freeTruckParking << endl;
    }
    else {
        cout << "There is no space available for this type of vehicle.\n";
    }

    return *this;   // Return the Parking object to allow chaining
}


// Overload of operator- to remove a vehicle from the parking lot by license number
Parking& Parking::operator-(long licenseNumber) {
    for (int i = 0; i < parkedCars.size(); ++i) {   
        if (parkedCars[i]->getLicenseNumber() == licenseNumber) {  
            parkedCars[i]->setDepartureTime(); 
            double cost = parkedCars[i]->calculateParkingCost(); 
            cout << "The car left the parking lot. The payment for parking is: " << cost << " NIS" << endl;
            parkedCars.erase(parkedCars.begin() + i);
            freeCarParking++; 
            return *this;
        }
    }
    for (int i = 0; i < parkedMotorcycles.size(); ++i) {
        if (parkedMotorcycles[i]->getLicenseNumber() == licenseNumber) {
            parkedMotorcycles[i]->setDepartureTime();
            double cost = parkedMotorcycles[i]->calculateParkingCost();
            cout << "The motorcycle left the parking lot. The payment for parking is: " << cost << " NIS" << endl;
            parkedMotorcycles.erase(parkedMotorcycles.begin() + i);   
            freeMotorcycleParking++;
            return *this;
        }
    }

    for (int i = 0; i < parkedTrucks.size(); ++i) {
        if (parkedTrucks[i]->getLicenseNumber() == licenseNumber) {
            parkedTrucks[i]->setDepartureTime();
            double cost = parkedTrucks[i]->calculateParkingCost();
            cout << "The truck left the parking lot. The payment for parking is: " << cost << " NIS" << endl;
            parkedTrucks.erase(parkedTrucks.begin() + i);  
            freeTruckParking++;
            return *this;
        }
    }

    cout << "The vehicle is not in this parking lot.\n";
    return *this; 
}

// Function to display the current status of the parking lot
void Parking::displayParkingStatus() const {
    double totalCarTime = 0.0, totalCarCost = 0.0;
    double totalMotorcycleTime = 0.0, totalMotorcycleCost = 0.0;
    double totalTruckTime = 0.0, totalTruckCost = 0.0;

    for (int i = 0; i < parkedCars.size(); ++i) {
        totalCarTime += parkedCars[i]->calculateParkingTime();
        totalCarCost += parkedCars[i]->calculateParkingCost();
    }

    for (int i = 0; i < parkedMotorcycles.size(); ++i) {
        totalMotorcycleTime += parkedMotorcycles[i]->calculateParkingTime();
        totalMotorcycleCost += parkedMotorcycles[i]->calculateParkingCost();
    }

    for (int i = 0; i < parkedTrucks.size(); ++i) {
        totalTruckTime += parkedTrucks[i]->calculateParkingTime();
        totalTruckCost += parkedTrucks[i]->calculateParkingCost();
    }

    // Display the overall parking status
    cout << "\nTotal number of parked vehicles: " << parkedCars.size() + parkedMotorcycles.size() + parkedTrucks.size() << endl;
    cout << "The number of spaces available for cars: " << freeCarParking << endl;
    cout << "The number of spaces available for motorcycle: " << freeMotorcycleParking << endl;
    cout << "The number of spaces available for truck: " << freeTruckParking << endl;

    cout << "\nTotal parking time for all vehicle: " << totalCarTime + totalMotorcycleTime + totalTruckTime << " hours" << endl;
    cout << "Total parking cost for all vehicle: " << totalCarCost + totalMotorcycleCost + totalTruckCost << " NIS" << endl;

}


// Function to save parking data to a file
void Parking::saveParkingData(const string& filename) const {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error opening file for saving parking data.\n";
        return;
    }

    for (const Vehicle* car : parkedCars) {
        outFile << "Car " << car->getLicenseNumber() << " " << car->getParkingEntryTime() << endl;
    }

    for (const Vehicle* motorcycle : parkedMotorcycles) {
        outFile << "Motorcycle " << motorcycle->getLicenseNumber() << " " << motorcycle->getParkingEntryTime() << endl;
    }

    for (const Vehicle* truck : parkedTrucks) {
        outFile << "Truck " << truck->getLicenseNumber() << " " << truck->getParkingEntryTime() << endl;
    }

    outFile.close();
    cout << "Parking data saved to file successfully.\n";
}

// Function to load parking data from a file
void Parking::loadParkingData(const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Error opening file for loading parking data.\n";
        return;
    }

    string vehicleType;
    long licenseNumber;
    string entryTime;  

    cout << "Loaded parking data from file:\n";

    // Read the data from the file
    while (inFile >> vehicleType >> licenseNumber >> entryTime) {
        if (vehicleType == "Car") {
            cout << "Vehicle Type: Car\n";
        }
        else if (vehicleType == "Motorcycle") {
            cout << "Vehicle Type: Motorcycle\n";

        }
        else if (vehicleType == "Truck") {
            cout << "Vehicle Type: Truck\n";

        }

        cout << "License Number: " << licenseNumber << endl;
        cout << "Entry Time: " << entryTime << endl;
        cout << "--------------------------\n";

    }

    inFile.close();
    cout << "Parking data loaded from file successfully.\n";
}
