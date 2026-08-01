#include <iostream>
using namespace std;

//---------------- Products ----------------

class Button{
public:
    virtual void paint() = 0;
    virtual ~Button() {}
};

class Checkbox{
public:
    virtual void check() = 0;
    virtual ~Checkbox() {}
};

//------------ Windows Products ------------

class WindowsButton : public Button {
public:
    void paint() override {
        cout << "Windows Button\n";
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void check() override {
        cout << "Windows Checkbox\n";
    }
};

//--------------- Mac Products -------------

class MacButton : public Button {
public:
    void paint() override {
        cout << "Mac Button\n";
    }
};

class MacCheckbox : public Checkbox {
public:
    void check() override {
        cout << "Mac Checkbox\n";
    }
};

//----------- Abstract Factory -------------

class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() {}
};

//--------- Concrete Factories -------------

class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }

    Checkbox* createCheckbox() override {
        return new WindowsCheckbox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }

    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
};

//--------------- Client -------------------

int main() {
    GUIFactory* factory = new WindowsFactory();

    Button* button = factory->createButton();
    Checkbox* checkbox = factory->createCheckbox();

    button->paint();
    checkbox->check();

    delete button;
    delete checkbox;
    delete factory;
}
