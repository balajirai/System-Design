#include <iostream>
using namespace std;

class Singleton {
private:
    inline static Singleton* instance = nullptr;

    Singleton() {
        cout << "Constructor is called" << endl;
    }

    ~Singleton() {
        cout << "Destructor is called" << endl;
    }

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton;
        }

        return instance;
    }

    static void destroyInstance() {
        delete instance;
        instance = nullptr;
    }
};

int main() {

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if(s1 == s2) {
        cout << "Both instances are same" << endl;
    }
    else {
        cout << "Both instances are different" << endl;
    }

    Singleton::destroyInstance();

    return 0;
}
