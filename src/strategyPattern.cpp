#include <bits/stdc++.h>

using namespace std;

class PaymentInterface {
    public:
    virtual void MakePayment() = 0;
};

class PayTM: public PaymentInterface {
    public:
    void MakePayment() {
        cout << "Here I am making payment through PayTM" << endl;
    }
};

class PhonePe: public PaymentInterface {
    public:
    void MakePayment() {
        cout << "I am making payment through PhonePe" << endl;
    }
};

class Payment {
    private:
    PaymentInterface* paymentInterface;

    public:
    void SetPaymentInterface(PaymentInterface* paymentInterface) {
        this->paymentInterface = paymentInterface;
    }

    void pay() {
        this->paymentInterface->MakePayment();
    }

};

int main() {
    Payment* payment = new Payment();
    
    //pay through PayTM
    payment->SetPaymentInterface(new PayTM());
    payment->pay();
    
    //pay through Phonepe
    payment->SetPaymentInterface(new PhonePe()) ;
    payment->pay();
    return 0;
}