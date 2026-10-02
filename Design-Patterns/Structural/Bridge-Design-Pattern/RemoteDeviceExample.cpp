#include <iostream>
using namespace std;

// Implementation
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setVolume(int volume) = 0;

    virtual ~Device() = default;
};


// Concrete Implementation
class TV : public Device {
public:
    void turnOn() override {
        cout << "TV is ON\n";
    }

    void turnOff() override {
        cout << "TV is OFF\n";
    }

    void setVolume(int volume) override {
        cout << "TV volume set to " << volume << "\n";
    }
};


// Concrete Implementation
class Radio : public Device {
public:
    void turnOn() override {
        cout << "Radio is ON\n";
    }

    void turnOff() override {
        cout << "Radio is OFF\n";
    }

    void setVolume(int volume) override {
        cout << "Radio volume set to " << volume << "\n";
    }
};


// Abstraction
class Remote {
protected:
    Device* device;

public:
    Remote(Device* device)
        : device(device) {}

    virtual void turnOn() {
        device->turnOn();
    }

    virtual void turnOff() {
        device->turnOff();
    }

    virtual void setVolume(int volume) {
        device->setVolume(volume);
    }

    virtual ~Remote() = default;
};


// Refined Abstraction
class AdvancedRemote : public Remote {
public:
    AdvancedRemote(Device* device)
        : Remote(device) {}

    void mute() {
        device->setVolume(0);
        cout << "Device muted\n";
    }
};


int main() {

    TV tv;
    Radio radio;

    // Basic remote controlling TV
    Remote tvRemote(&tv);

    tvRemote.turnOn();
    tvRemote.setVolume(20);
    tvRemote.turnOff();

    cout << "\n";

    // Advanced remote controlling Radio
    AdvancedRemote radioRemote(&radio);

    radioRemote.turnOn();
    radioRemote.setVolume(15);
    radioRemote.mute();
    radioRemote.turnOff();

    return 0;
}
