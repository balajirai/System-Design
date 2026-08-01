#include <iostream>
using namespace std;

// Simple Factory is not a Design Pattern //

// ---- Product Interface ----
class Car {
public:
    virtual void drive() = 0;
    virtual ~Car() {}
};


// ---- Concrete Products ----
class BMW : public Car {
public:
    void drive() override
    {
        cout << "Driving BMW\n";
    }
};

class Audi : public Car {
public:
    void drive() override {
        cout << "Driving Audi\n";
    }
};

class Tesla : public Car {
public:
    void drive() override {
        cout << "Driving Tesla\n";
    }
};


// ---- Simple Factory ----
class CarFactory {
public:
    static Car* createCar(string type) {
        if(type == "BMW")
            return new BMW();

        if(type == "Audi")
            return new Audi();

        if(type == "Tesla")
            return new Tesla();

        return nullptr;
    }
};

// ---- Client Code ----
int main() {
    Car* car1 = CarFactory::createCar("BMW");
    Car* car2 = CarFactory::createCar("Audi");
    Car* car3 = CarFactory::createCar("Tesla");

    car1->drive();
    car2->drive();
    car3->drive();

    delete car1;
    delete car2;
    delete car3;

    return 0;
}
