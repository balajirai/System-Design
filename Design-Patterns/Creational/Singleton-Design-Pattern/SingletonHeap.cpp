#include <iostream>
using namespace std;

class Singleton {
private:
    inline static Singleton* instance = nullptr;
    Singleton(){
        cout << "Constructor is called" << endl;
    }

public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton;
        }
        return instance;
    }
};


int main() {
    
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    if(s1 == s2){
        cout << "Both Instances are same" << endl;
    }
    else cout << "Both Instances are different" << endl;

    return 0;
}
