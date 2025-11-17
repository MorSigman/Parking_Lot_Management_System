#pragma once

#include <string>
#include <vector> 
#include "Vehicle.h"  
#include "Car.h"

using namespace std; 


class Parking {
private:
    int freeCarParking; 
    int freeMotorcycleParking;
    int freeTruckParking; 

    //Vectors to store currently parked vehicles
    vector<Vehicle*> parkedCars; 
    vector<Vehicle*> parkedMotorcycles; 
    vector<Vehicle*> parkedTrucks; 

public:
    Parking(int freeCarSpots, int freeMotorcycleSpots, int freeTruckSpots);      //Constructor to initialize parking spots

    Parking& operator+(Vehicle* vehicle);     // Add vehicle to parking

    Parking& operator-(long licenseNumber);  // Remove vehicle from parking

    void displayParkingStatus() const; 

    void saveParkingData(const string& filename) const;    
    void loadParkingData(const string& filename); 

    int getfreeCarParking() const { return freeCarParking; } 
    int getfreeMotorcycleParking() const { return freeMotorcycleParking; }  
    int getfreeTruckParking() const { return freeTruckParking; }  

};