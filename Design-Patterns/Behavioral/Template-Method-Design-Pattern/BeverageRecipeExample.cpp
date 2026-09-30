#include <iostream>
using namespace std;

// Abstract Base Class
class Beverage {
public:

    // Template Method
    void makeBeverage() {
        boilWater();
        brew();
        pourIntoCup();
        addCondiments();
    }

protected:

    // Common step
    void boilWater() {
        cout << "Boiling water\n";
    }

    // Variable steps
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    // Common step
    void pourIntoCup() {
        cout << "Pouring into cup\n";
    }

public:
    virtual ~Beverage() = default;
};


// Concrete Class
class Tea : public Beverage {
protected:

    void brew() override {
        cout << "Steeping tea leaves\n";
    }

    void addCondiments() override {
        cout << "Adding lemon\n";
    }
};


// Concrete Class
class Coffee : public Beverage {
protected:

    void brew() override {
        cout << "Brewing coffee grounds\n";
    }

    void addCondiments() override {
        cout << "Adding sugar and milk\n";
    }
};


int main() {

    Tea tea;
    Coffee coffee;

    cout << "Making Tea:\n";
    tea.makeBeverage();

    cout << "\nMaking Coffee:\n";
    coffee.makeBeverage();

    return 0;
}
