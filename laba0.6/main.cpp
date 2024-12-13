#include <iostream>
#include "PeripheralDevice.h"
#include "Printer.h"
#include "Monitor.h"

using namespace std;

int main() {
    PeripheralDevice* devices[10];
    int deviceCount = 0;
    int choice;

    while (true) {
        cout << "\nMenu: \n";
        cout << "1. Add Printer\n";
        cout << "2. Add Monitor\n";
        cout << "3. Display Devices\n";
        cout << "4. Modify Device\n";
        cout << "5. Calculate Minimum Price\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            double price;
            int speed;
            cout << "Enter printer name: ";
            cin >> name;
            cout << "Enter printer price: ";
            cin >> price;
            cout << "Enter print speed: ";
            cin >> speed;
            devices[deviceCount++] = new Printer(name, price, speed);
        } else if (choice == 2) {
            string name;
            double price;
            double size;
            cout << "Enter monitor name: ";
            cin >> name;
            cout << "Enter monitor price: ";
            cin >> price;
            cout << "Enter screen size: ";
            cin >> size;
            devices[deviceCount++] = new Monitor(name, price, size);
        } else if (choice == 3) {
            for (int i = 0; i < deviceCount; i++) {
                devices[i]->display();
            }
        } else if (choice == 4) {
            int index;
            cout << "Enter device number to modify (0 to " << deviceCount - 1 << "): ";
            cin >> index;
            if (index < deviceCount) {
                int subChoice;
                cout << "1. Modify Printer Speed\n";
                cout << "2. Modify Monitor Size\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    int speed;
                    cout << "Enter new print speed: ";
                    cin >> speed;
                    static_cast<Printer*>(devices[index])->setPrintSpeed(speed);
                } else if (subChoice == 2) {
                    double size;
                    cout << "Enter new screen size: ";
                    cin >> size;
                    static_cast<Monitor*>(devices[index])->setScreenSize(size);
                }
            } else {
                cout << "Invalid device number!\n";
            }
        } else if (choice == 5) {
            double minPrice = 999999;
            for (int i = 0; i < deviceCount; i++) {
                double price = devices[i]->calculateMinPrice();
                if (price < minPrice) {
                    minPrice = price;
                }
            }
            cout << "Minimum price: " << minPrice << endl;
        } else if (choice == 6) {
            cout << "Exiting program...\n";
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }


    for (int i = 0; i < deviceCount; i++) {
        delete devices[i];
    }

    return 0;
}
