#include <iostream>
using namespace std;

class Singleton {
private:
    Singleton() {
        cout << "Constructor is called" << endl;
    }

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};

int main() {

    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    if(&s1 == &s2) {
        cout << "Both instances are same" << endl;
    }
    else {
        cout << "Both instances are different" << endl;
    }

    return 0;
}
