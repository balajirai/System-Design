#include <iostream>
using namespace std;

// Target interface
class PaymentProcessor {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentProcessor() = default;
};

// Existing/Third-party class
class PayPal {
public:
    void makePayment(double amount) {
        cout << "PayPal payment: $" << amount << "\n";
    }
};

// Adapter
class PayPalAdapter : public PaymentProcessor {
private:
    PayPal& paypal;

public:
    PayPalAdapter(PayPal& paypal) : paypal(paypal) {}

    void pay(double amount) override {
        paypal.makePayment(amount);
    }
};

// Client
void checkout(PaymentProcessor& processor) {
    processor.pay(100);
}

int main() {
    
    PayPal paypal;

    PayPalAdapter adapter(paypal);

    checkout(adapter);

    return 0;
}
