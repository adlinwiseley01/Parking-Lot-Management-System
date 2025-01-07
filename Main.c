#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum capacity of the parking lot
#define MAX_CAPACITY 10

// Structure to store vehicle details
typedef struct {
    char plateNumber[20];
    char ownerName[50];
    int hoursParked;
} Vehicle;

// Global variables
Vehicle parkingLot[MAX_CAPACITY];
int currentCount = 0;

// Function to add a vehicle
void addVehicle() {
    if (currentCount >= MAX_CAPACITY) {
        printf("Parking lot is full. Cannot add more vehicles.\n");
        return;
    }
    Vehicle newVehicle;
    printf("Enter Vehicle Plate Number: ");
    scanf("%s", newVehicle.plateNumber);
    printf("Enter Owner Name: ");
    scanf(" %[^\n]", newVehicle.ownerName);
    printf("Enter Hours Parked: ");
    scanf("%d", &newVehicle.hoursParked);

    parkingLot[currentCount++] = newVehicle;
    printf("Vehicle added successfully.\n");
}

// Function to remove a vehicle
void removeVehicle() {
    char plateNumber[20];
    printf("Enter Vehicle Plate Number to remove: ");
    scanf("%s", plateNumber);

    for (int i = 0; i < currentCount; i++) {
        if (strcmp(parkingLot[i].plateNumber, plateNumber) == 0) {
            // Calculate parking fee
            int fee = parkingLot[i].hoursParked * 10; // Assume $10 per hour
            printf("Vehicle removed. Parking fee: $%d\n", fee);

            // Shift the remaining vehicles
            for (int j = i; j < currentCount - 1; j++) {
                parkingLot[j] = parkingLot[j + 1];
            }
            currentCount--;
            return;
        }
    }
    printf("Vehicle not found in the parking lot.\n");
}

// Function to display all vehicles
void displayVehicles() {
    if (currentCount == 0) {
        printf("Parking lot is empty.\n");
        return;
    }
    printf("Vehicles in the parking lot:\n");
    printf("Plate Number\tOwner Name\tHours Parked\n");
    for (int i = 0; i < currentCount; i++) {
        printf("%s\t\t%s\t\t%d\n", parkingLot[i].plateNumber, parkingLot[i].ownerName, parkingLot[i].hoursParked);
    }
}

// Main menu
void menu() {
    printf("\n--- Parking Lot Management System ---\n");
    printf("1. Add Vehicle\n");
    printf("2. Remove Vehicle\n");
    printf("3. Display All Vehicles\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                removeVehicle();
                break;
            case 3:
                displayVehicles();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
