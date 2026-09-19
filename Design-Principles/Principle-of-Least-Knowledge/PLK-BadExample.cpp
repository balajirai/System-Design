#include <iostream>
using namespace std;

class Sensor {
public:
    void checkFuel() {
        cout << "Fuel checked\n";
    }
};

class FuelInjector {
public:
    Sensor sensor;
};

class Engine {
public:
    FuelInjector injector;
};

class Car {
public:
    Engine engine;

    void start() {
        // Bad: reaching deep into other objects
        engine.injector.sensor.checkFuel();
    }
};

int main() {
    Car car;
    car.start();
}
