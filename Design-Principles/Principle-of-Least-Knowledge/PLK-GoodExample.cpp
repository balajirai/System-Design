#include <iostream>
using namespace std;

class Sensor {
public:
    void checkFuel() {
        cout << "Fuel checked\n";
    }
};

class FuelInjector {
private:
    Sensor sensor;

public:
    void injectFuel() {
        sensor.checkFuel();
        cout << "Fuel injected\n";
    }
};

class Engine {
private:
    FuelInjector injector;

public:
    void startEngine() {
        injector.injectFuel();
        cout << "Engine started\n";
    }
};

class Car {
private:
    Engine engine;

public:
    void start() {
        engine.startEngine();
        cout << "Car started\n";
    }
};

int main() {
    Car car;
    car.start();
}
