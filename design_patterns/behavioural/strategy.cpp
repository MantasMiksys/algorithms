
#include <iostream>

// Example: One interface, different implenentations with different algs

class AirportTransfer {
public:
    virtual void transfer() = 0;
};

class CarTransfer : public AirportTransfer {
public:
    void transfer() override {
        std::cout << "Car transfer" << std::endl;
        // get your private car 
        // and drive yourself
    }
};

class TaxiTransfer : public AirportTransfer {
public:
    void transfer() override {
        std::cout << "Taxi transfer" << std::endl;
        // call a cab
        // tell airport anme
        // and go
    }
};

int main() {
    AirportTransfer * t1 = new CarTransfer();
    t1->transfer();
    TaxiTransfer * t2 = new TaxiTransfer();
    t2->transfer();
}
