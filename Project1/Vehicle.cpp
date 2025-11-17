#include <iostream>
#include "Vehicle.h"
#include <ctime>

using namespace std;

// Constructor for the Vehicle class, initializes the vehicle with a license number and type and sets the entry time to the current system time.
Vehicle::Vehicle(long license, string type) : licenseNumber(license), vehicleType(type), departureTime(0) {
    time(&parkingEntryTime); 
}

void Vehicle::setDepartureTime() {
    time(&departureTime);  
}

// Function to return the parking entry time in the "HH:MM" format
const char* Vehicle::getParkingEntryTime() const {
    static char buffer[10];  // Static buffer to store the formatted time (HH:MM)
    struct tm displayTime;   // Struct to hold the broken-down time information (H and M)
    localtime_s(&displayTime, &parkingEntryTime);  // Convert time_t to struct tm (local time)
    strftime(buffer, sizeof(buffer), "%H:%M", &displayTime);   // Format the time as HH:MM
    return buffer;
}