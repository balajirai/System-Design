#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
    inline static Singleton* instance = nullptr;
    inline static mutex mtx;

    Singleton() {
        cout << "Constructor is called" << endl;
    }

public:
    static Singleton* getInstance() {
        lock_guard<mutex> lock(mtx);

        if(instance == nullptr) {
            instance = new Singleton; // Lazy Initialization
        }

        return instance;
    }
};

int main() {

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if(s1 == s2) {
        cout << "Both Instances are same" << endl;
    }
    else {
        cout << "Both Instances are different" << endl;
    }

    return 0;
}
