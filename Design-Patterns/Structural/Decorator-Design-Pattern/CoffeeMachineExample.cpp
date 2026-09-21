#include <iostream>
#include <string>
using namespace std;

class Coffee {
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
};

class PlainCoffee : public Coffee {
public:
    string getDescription() override {
        return "Plain Coffee";
    }

    double getCost() override {
        return 2.0;
    }
};

class CoffeeDecorator : public Coffee {     // 'Is-a' relationship
protected:
    Coffee* decoratedCoffee;                // 'Has-a' relationship

public:
    CoffeeDecorator(Coffee* decoratedCoffee) : decoratedCoffee(decoratedCoffee) {}

    string getDescription() override {
        return decoratedCoffee->getDescription();
    }

    double getCost() override {
        return decoratedCoffee->getCost();
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* decoratedCoffee) : CoffeeDecorator(decoratedCoffee) {}

    string getDescription() override {
        return decoratedCoffee->getDescription() + ", Milk";
    }

    double getCost() override {
        return decoratedCoffee->getCost() + 0.5;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* decoratedCoffee) : CoffeeDecorator(decoratedCoffee) {}

    string getDescription() override {
        return decoratedCoffee->getDescription() + ", Sugar";
    }

    double getCost() override {
        return decoratedCoffee->getCost() + 0.2;
    }
};

int main() {

    // Plain Coffee
    Coffee* coffee = new PlainCoffee();
    cout << "Description: " << coffee->getDescription() << endl;
    cout << "Cost: $" << coffee->getCost() << endl;

    // Coffee with Milk
    Coffee* milkCoffee = new MilkDecorator(new PlainCoffee());
    cout << "\nDescription: " << milkCoffee->getDescription() << endl;
    cout << "Cost: $" << milkCoffee->getCost() << endl;

    // Coffee with Sugar and Milk
    Coffee* sugarMilkCoffee = new SugarDecorator(new MilkDecorator(new PlainCoffee()));
    cout << "\nDescription: " << sugarMilkCoffee->getDescription() << endl;
    cout << "Cost: $" << sugarMilkCoffee->getCost() << endl;

    delete coffee;
    delete milkCoffee;
    delete sugarMilkCoffee;
    
    return 0;
}
