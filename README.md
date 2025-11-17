# Smart Parking Lot Management System

A final project for an Object-Oriented Programming (C++) course, simulating a smart parking lot management system for various vehicle types.

##  Project Goal

This project was written as an academic assignment with the aim of implementing object-oriented programming principles for parking lot management, including:
* Managing the entry and exit of vehicles.
* Calculating parking fees based on vehicle type and parking duration.
* Managing the parking lot's capacity.

##  Key Features

* **Vehicle Entry:** Adding a vehicle (private car, motorcycle, truck) to the parking lot and checking for available space.
* **Vehicle Exit:** Removing a vehicle from the parking lot and automatically calculating the parking fee.
* **Status Display:** Showing current occupancy, available spots, and total revenue.
* **Save & Load:** The ability to save the current state of the parking lot to a file and reload it.

##  Key Technologies and Principles

* **Language:** C++
* **Object-Oriented Programming (OOP):**
    * **Polymorphism:** Using virtual functions (`virtual`) to calculate different parking costs for each vehicle type.
    * **Inheritance:** Creating a class hierarchy (`Vehicle` -> `Car`, `Motorcycle`, `Truck`).
    * **Abstraction:** Using an abstract base class.
* **Memory Management:** Use of dynamic memory allocations.
* **Data Structures:** Using `std::vector` to manage the collections of parked vehicles.
* **File Handling:** Saving and loading parking lot data.
