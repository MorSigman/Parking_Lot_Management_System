#include <iostream>
#include "Car.h"
#include "Parking.h"
#include "Motorcycle.h"  
#include "Truck.h"

using namespace std;

// Function to display the menu options
void menu() {
    cout << "--------------------------";
    cout << "\nSelect an option \n\n";
    cout << "1. Entry and start of parking \n";
    cout << "2. Exiting and payment \n";
    cout << "3. Display parking status\n";
    cout << "4. Save parking data to a file \n";
    cout << "5. Loading parking data from a file \n";
    cout << "6. exit \n\n";
}

int main() {
    Parking parking(10, 5, 3); // Initialize Parking object with available spots for cars, motorcycles, and trucks
    int choice;
    cout << "\n\n";

    while (true) {  // Infinite loop to keep the menu active
        menu();
        cin >> choice;

        // Case 1: Entry and start of parking
        if (choice == 1) {
            int type;
            cout << "Select vehicle type:\n 1. Car\n 2. Motorcycle\n 3. Truck\n";
            cin >> type;
            if (type == 1) {
                long license;
                cout << "Enter the car license number: ";
                cin >> license;
                Car* car = new Car(license); 
                if (parking.getfreeCarParking() == 0) { 
                    cout << "No available parking for cars.\n";
                    delete car;  
                }
                else {
                    parking + car; 

                }
            }

            else if (type == 2) {
                long license;
                cout << "Enter the motorcycle license number: ";
                cin >> license;
                Motorcycle* motorcycle = new Motorcycle(license);
                if (parking.getfreeMotorcycleParking() == 0) { 
                    cout << "No available parking for motorcycles.\n";
                    delete motorcycle;  
                }
                else {
                    parking + motorcycle; 
                }
            }
            else if (type == 3) {
                long license;
                cout << "Enter the truck license number: ";
                cin >> license;
                Truck* truck = new Truck(license);
                if (parking.getfreeTruckParking() == 0) {  
                    cout << "No available parking for trucks.\n";
                    delete truck;  
                }
                else {
                    parking + truck; 
                }
            }
            else {
                cout << "Invalid selection.\n";
            }
        }

        // Case 2: Exiting and payment
        else if (choice == 2) {
            long license;
            cout << "Enter the vehicle license number to remove: ";
            cin >> license;
            parking - license; 
        }

        // Case 3: Display parking status
        else if (choice == 3) {
            parking.displayParkingStatus();
        }

        // Case 4: Save parking data to a file
        else if (choice == 4) {
            parking.saveParkingData("parking_data.txt");  
            cout << "Parking data saved to 'parking_data.txt'.\n";
        }

        // Case 5: Load parking data from a file
        else if (choice == 5) {
            parking.saveParkingData("parking_data.txt");  
            parking.loadParkingData("parking_data.txt");  
            cout << "Parking data loaded from 'parking_data.txt'.\n";
        }

        // Case 6: Exit the program
        else if (choice == 6) {
            cout << "Exiting the program.\n";
            return 0;
        }

        else {
            cout << "Invalid selection, please try again.\n";
        }
    }

    return 0;
}

