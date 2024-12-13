#ifndef PERIPHERALDEVICE_H
#define PERIPHERALDEVICE_H

#include <iostream>
#include <string>
using namespace std;

class PeripheralDevice {
protected:
    string name;  
    double price; 

public:
    PeripheralDevice(string n = "", double p = 0) : name(n), price(p) {}

    virtual void display() {  
        cout << "Name: " << name << ", Price: " << price << endl;
    }

    virtual double calculateMinPrice() = 0;  

    virtual ~PeripheralDevice() {}
};

#endif
