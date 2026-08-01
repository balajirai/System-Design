#include <iostream>
using namespace std;

// Product
class Car {
public:
    virtual void drive() = 0;
    virtual ~Car() {}
};

// Concrete Products
class BMW : public Car {
public:
    void drive() override {
        cout << "Driving BMW\n";
    }
};

class Audi : public Car
{
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

// Creator
class CarFactory {
public:
    virtual Car* createCar() = 0;
    virtual ~CarFactory() {}
};

// Concrete Factories
class BMWFactory : public CarFactory {
public:
    Car* createCar() override {
        return new BMW();
    }
};

class AudiFactory : public CarFactory {
public:
    Car* createCar() override {
        return new Audi();
    }
};

class TeslaFactory : public CarFactory {
public:
    Car* createCar() override {
        return new Tesla();
    }
};

// Client Code
int main() {
    CarFactory* factory = new TeslaFactory();

    Car* car = factory->createCar();

    car->drive();

    delete car;
    delete factory;

    return 0;
}
