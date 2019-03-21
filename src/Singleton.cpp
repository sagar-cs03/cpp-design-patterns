#include <bits/stdc++.h>
using namespace std;

class Singleton {
    private:
    string description = "";
    static Singleton* singleton;

    Singleton() { 
        description = "this is a singleton class ";
    }

    public:
    static Singleton* GetObject() {
        if (singleton == 0) {
            singleton = new Singleton();
        } 
        return singleton;
    }

    string GetDescription() {
        return description;
    }
};


Singleton* Singleton:: singleton = 0;

int main() {
    Singleton* s ;
    cout << s->GetObject()->GetDescription() << endl;
}