#ifndef PRINTER_H
#define PRINTER_H

#include "PeripheralDevice.h"

class Printer : public PeripheralDevice {
private:
    int printSpeed;  

public:
    Printer(string n = "", double p = 0, int speed = 0) : PeripheralDevice(n, p), printSpeed(speed) {}

    void display() override {  
        PeripheralDevice::display();
        cout << "Print Speed: " << printSpeed << " pages per minute" << endl;
    }

    double calculateMinPrice() override {  
        return price - (printSpeed * 0.1);
    }

    void setPrintSpeed(int speed) { 
        printSpeed = speed;
    }
};

#endif
