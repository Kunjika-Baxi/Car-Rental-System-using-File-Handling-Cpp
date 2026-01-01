#  Car Rental Management System

## Overview
This project is a **Car Rental Management System** implemented in C++ using **file handling**.  
It simulates a simplified version of a car rental service (Zoom Car), allowing users to sign up, sign in, view available cars, update car details, delete cars, and rent cars with dynamic pricing based on distance and rental duration.

The program demonstrates:
- Object-Oriented Programming (OOP) concepts (class `carmodel`)
- File handling (`ifstream`, `ofstream`, `fstream`)
- CRUD operations on car records
- Basic authentication and rental charge calculation

---

## Features
- **Sign-up / Sign-in**:
  - New users can register with name, contact, email, and driving license check.
  - Existing users can log in with a password (`Zoomcar_rent@123`).
- **Add Cars**: Enter car model, color, and number to add to the system.
- **Display Cars**: View all available cars for rent.
- **Update Car Details**:
  - Update car model.
  - Update car color.
- **Delete Car**: Remove a specific car record from the system.
- **Rent Car**:
  - Select a car by number and model.
  - Charges vary by car type:
    - Hatchbacks (Swift, Grand-i10, Wagonar): ₹13/km
    - Sedans/SUVs (Verna, Xcent, Innova): ₹15/km
    - Others: ₹17/km
  - Extra charges: ₹200/day for rentals of 24 hours or more.
  - Receipt generated with total charge and advance payment (50%).
  - Updates availability list after renting.

---

## File Structure
- **Carrent.dat** → Binary file storing available cars.
- **carrents.dat** → Updated availability list after renting.
- **new.dat / New.dat** → Temporary files used during deletion or availability update.

---

## Menu Options
1. Enter the Available Cars
2. Display All
3. Update Car Model
4. Update Car Colour
5. Delete data of Specific Car
6. Rent Car
0. EXIT

---

Important Notes : 
- Password for existing users.
- Driving license is mandatory for new users.
- Charges depend on car type and rental duration.
- Data is stored in binary format for efficiency.
- On program start, Carrent.dat is removed to ensure a fresh run (you may remove this line if persistence is required).
