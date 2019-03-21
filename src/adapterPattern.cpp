#include <bits/stdc++.h>
using namespace std;

class OldRemoteInterface {
    public:
    int current_channel = 0;
    virtual void TurnOff() = 0;
    virtual void TurnOn() = 0;
    virtual void ChangeChannel(int num) = 0;
};

class OldTv: public OldRemoteInterface {
    public:
    void TurnOff() {
        cout << "turning off old TV" << endl;
    }

    void TurnOn() {
        cout << "turning On old TV" << endl;
    }

    void ChangeChannel(int num) {
        this->current_channel = num ;
        cout << "switched to channel" << this->current_channel << endl;
    }
};


class NewRemoteInterface {
    public:
    int current_channel = 0;
    virtual void SwitchOn() = 0;
    virtual void SwitchOff() = 0;
    virtual void SwitchChannel(int channel_no) = 0;
};


/*  *Think of this as a new tv that has behaviours implemented in different way.
     so it has SwitchOn(), SwitchOff(), ChangeChannel() i.e different types of interface/the method of communicating.

    ** Short Interface explanation for my sake of understanding
        *Think of Interfaces like this. You had a oldTV that had certain behaviours/features/standards compatible with oldremote, those features are
        TurnOff(), TurnOn(), ChangeChannel()
        *Those behaviours are the interface of communication between interacting objects/entitities. i.e since the oldTv implements 
        oldRemote interface, oldTv is compatible with oldRemote and when it implements, it has responsiblity on its part to provide 
        the features/characteristics for the remote to work.
        * Now, assuming technology advanced and we have NewTv and come with NewRemote, NewTV implements behaviours using
        SwitchOn(), SwitchOff() methods as the NewRemote now knows such features are there in the TV and knows how to work with such features/standard.
        Therefore, now you can operate NewTV with NewRemote since the protocols/rules/interface/ of communication is specified in 
        an interface client and those rules are followed by the interface server/remote 
        * interface client is like NewRemote
        * interface remote is like NewTV
        * this is atleast how I like to think of interfaces and have understood it, if there's any flaw, please help me correct it!
        * TLDR; when you want objects to communicate using some protocol, think interfaces. Establish some standards? think interfaces
            - example: when you have set of payment options like paytm, phonepe etc and you want to be able to pay using one of these platforms
                       In this case, you can create a interface PaymentDriver having payThrough() method that is implemented by paytm, phonepe classes.
                       Then, you can use PaymentDriver to call payThrough() of paytm or phonepe depending on the dynamic type at runtime
                       Here, the takeaway is, PayTM and PhonePe are understanding the standard for receiving payment requests

*/
class NewTv: public NewRemoteInterface {
    public:
    void SwitchOn() {
        cout << "Switching on my new TV" << endl;
    }

    void SwitchOff() {
        cout << "Switching off my new Tv"  << endl;
    }

    void SwitchChannel(int num) {
        current_channel = num ;
        cout << "Switched to my new TV " << this->current_channel << endl;
    }
};


class RemoteAdapterToNewTv: public OldRemoteInterface {
    public:
    NewTv* newTv;
    RemoteAdapterToNewTv(NewTv* newTv) {
        this->newTv = newTv;
    }

    void TurnOff () {
        this->newTv->SwitchOff();
    }

    void TurnOn () {
        this->newTv->SwitchOn();
    }

    void ChangeChannel(int num) {
        this->newTv->SwitchChannel(num);
    }
};

int main() {
    NewTv newTv;

    //use oldremote to access newTv through adapter
    OldRemoteInterface* oldRemote = new RemoteAdapterToNewTv(&newTv);
    oldRemote->TurnOff();
    oldRemote->TurnOn();
    oldRemote->ChangeChannel(5);

    cout << endl;

    //use oldremote to access oldTv directly
    oldRemote = new OldTv();
    oldRemote->TurnOff();
    oldRemote->TurnOn();
    oldRemote->ChangeChannel(10);
    
    return 0;
}