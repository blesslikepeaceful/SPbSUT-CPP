#ifndef MONITOR_H
#define MONITOR_H

#include "PeripheralDevice.h"

class Monitor : public PeripheralDevice {
private:
    double screenSize;  

public:
    Monitor(string n = "", double p = 0, double size = 0) : PeripheralDevice(n, p), screenSize(size) {}

    void display() override { 
        PeripheralDevice::display();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }

    double calculateMinPrice() override {  
        return price - (screenSize * 2);
    }

    void setScreenSize(double size) {  
        screenSize = size;
    }
};

#endif
