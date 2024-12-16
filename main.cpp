#include <iostream>
#include <string>
using namespace std;

const int MAX_CARS = 100;

class Car {
public:
    string make;
    string model;
    int year;
    double price;

    void showDetails() {
            cout << "\n========================================" << endl;
        cout << "Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Price: €" << price << endl;
    cout << "========================================" << endl;
    }
};

class CarShop {
public:
    Car cars[MAX_CARS];
    int carCount = 0;

    void addCar() {
        if (carCount < MAX_CARS) {
            cars[carCount].make = "Porsche";
            cout << "Enter car model: ";
            cin >> cars[carCount].model;
            cout << "Enter car year: ";
            cin >> cars[carCount].year;
            cout << "Enter car price: ";
            cin >> cars[carCount].price;
            carCount++;
            cout<<"\n\n";
            cout << "\t\tCar added successfully!" << endl;
        } else {
            cout<<"\n\n";
            cout << "\t\tCar shop is full!" << endl;
        }
    }

    void listAllCars() {
        if (carCount == 0) {
                cout<<"\n\n";
            cout << "\t\tNo cars available in the shop." << endl;
            return;
        }

        for (int i = 0; i < carCount; ++i) {
            cout << i + 1 << ". ";
            cars[i].showDetails();
        }
    }

    void searchCar() {
        string make, model;
         make="Porsche";
        cout << "Enter car model to search: ";
        cin >> model;

        bool found = false;
        for (int i = 0; i < carCount; ++i) {
            if (cars[i].make == make && cars[i].model == model) {
                cars[i].showDetails();
                found = true;
            }
        }

        if (!found) {
                cout<<"\n\n";
            cout << "\t\tCar not found." << endl;
        }
    }

    void deleteCar() {
        int index;
        cout << "Enter car index to delete: ";
        cin >> index;

        if (index < 1 || index > carCount) {
                cout<<"\n\n";
            cout << "\t\tInvalid car index." << endl;
            return;
        }

        for (int i = index - 1; i < carCount - 1; ++i) {
            cars[i] = cars[i + 1];
        }
        carCount--;
        cout<<"\n\n";
        cout << "\t\tCar deleted successfully!" << endl;
    }
};

void displayHeader() {
    cout << "\n========================================" << endl;
    cout << "          Porsche Car Shop Management System          " << endl;
    cout << "========================================" << endl;
}

int main() {
    CarShop shop;
    int choice;

    do {
        displayHeader();

        cout << "\nChoose an option:" << endl;
        cout << "1. Add New Porsche Car" << endl;
        cout << "2. List All Available Porsche Cars" << endl;
        cout << "3. Search for a Specific Porsche Car" << endl;
        cout << "4. Delete a Car from Inventory" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            shop.addCar();
            break;
        case 2:
            shop.listAllCars();
            break;
        case 3:
            shop.searchCar();
            break;
        case 4:
            shop.deleteCar();
            break;
        case 5:
            cout << "Exiting Porsche Car Shop Management System..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
