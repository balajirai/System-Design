#include <iostream>
using namespace std;

// Strategy
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

// Concrete Strategy 1
class CreditCard : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid $" << amount << " using Credit Card\n";
    }
};

// Concrete Strategy 2
class PayPal : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid $" << amount << " using PayPal\n";
    }
};

// Concrete Strategy 3
class UPI : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid $" << amount << " using UPI\n";
    }
};

// Context
class PaymentProcessor {
private:
    PaymentStrategy* strategy;

public:
    PaymentProcessor(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    void processPayment(int amount) {
        strategy->pay(amount);
    }
};

// Client code
int main() {
    CreditCard card;
    PayPal paypal;
    UPI upi;

    PaymentProcessor p1(&card);
    p1.processPayment(100);

    PaymentProcessor p2(&paypal);
    p2.processPayment(200);

    PaymentProcessor p3(&upi);
    p3.processPayment(300);
}
