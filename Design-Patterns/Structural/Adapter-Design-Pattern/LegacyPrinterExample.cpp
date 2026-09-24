#include <iostream>
using namespace std;

class Printer {
public:
    virtual void print() = 0;
    virtual ~Printer() = default;
};

class LegacyPrinter {
public:
    void printDocument() {
        cout << "Legacy Printer is printing document" << endl;
    }
};

class PrinterAdapter : public Printer {
private:
    LegacyPrinter* legacyPrinterObject;

public:
    PrinterAdapter(LegacyPrinter* legacyPrinterObject) : legacyPrinterObject(legacyPrinterObject) {}

    void print() override {
        legacyPrinterObject->printDocument();
    }
};

void clientCode(Printer* printerObject) {
    printerObject->print();
}

int main() {
    LegacyPrinter legacyPrinter;

    PrinterAdapter printerAdapter(&legacyPrinter);

    clientCode(&printerAdapter);

    return 0;
}
