#include <bits/stdc++.h>
using namespace std;

class ObserverInterface {
    public:
    virtual void Notify() = 0;
};

class Observer: public ObserverInterface {

    public:
    string name = "";
    Observer(string num) {
        name = num ;
    }
    void Notify() {
        cout << "Observer notified " << name <<  endl;
    }
};


class Notifier {
    public:
    vector< ObserverInterface* > observers;

    void Register(ObserverInterface* obs) {
        observers.push_back(obs);
    }

    void DeRegister(ObserverInterface* obs) {
        for  (int i = 0; i < observers.size(); i++) {
            if (observers[i] == obs) {
                observers.erase(observers.begin() + i);
                break;
            }
        }
    }

    void UpdateAll() {
        for(ObserverInterface* obs: observers) {
            if (obs != NULL) {
                obs->Notify();
            }
        }
    }
};

int main() {
    Observer obs1("one");
    Observer obs2("two");
    Observer obs3("three");
    Notifier notifier;
    notifier.Register(&obs1);
    notifier.Register(&obs2);
    notifier.UpdateAll();
}