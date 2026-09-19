#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton(){
        cout << "Constructor is called" << endl;
    }

public:
    static Singleton* getInstance(){
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = new Singleton;  // Eager Initialization

int main() {
    
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    if(s1 == s2){
        cout << "Both Instances are same" << endl;
    }
    else cout << "Both Instances are same different" << endl;

    return 0;
}
