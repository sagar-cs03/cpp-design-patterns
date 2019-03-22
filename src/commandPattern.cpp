#include <bits/stdc++.h>

using namespace std;

class ElectronicTV {
    int state = 0;
    int volume = 0;
    public:
    void TurnOff() {
        this->state = 0;
        cout << "Turned Off TV" << endl;
    }

    void TurnOn() {
        this->state = 1;
        cout << "Turned On TV" << endl;
    }
    
    void VolumeUp() {
        (this->volume)++;
    }

    void VolumeDown() {
        (this->volume)--;
    }
};


class WashingMachine {
    int state = 0;
    int startLoad = 0;

    public:
    void TurnOn() {
        this->state = 1;
        cout << "Turned on Washing Machine" << endl;
    }

    void TurnOff() {
        this->state = 0;
        cout << "Turned off Washing Machine" << endl;
    }

    void StartQuick30Wash() {
        if(state) {
            this->startLoad = 1;
            cout << "Started Quick Wash" << endl;
        } else {
            cout << "Turn on your Washing machine" << endl;
        }
    }

    void StopQuick30Wash() {
        this->startLoad = 0;
        cout << "Stopped Quick 30 Wash" << endl;
    }
};

class Command {
    public:
    virtual void execute()=0;
};

class TurnOnTV: public Command {
    ElectronicTV* electronicTV;

    public:

    TurnOnTV(ElectronicTV* electronicTV) {
        this->electronicTV = electronicTV;
    }

    void execute() {
        this->electronicTV->TurnOn();
    }
};
//likewise for TurnOffTv also

class TurnOnWashingMachine: public Command {
    WashingMachine* washingMachine;

    public:
    TurnOnWashingMachine(WashingMachine* washingMachine) {
        this->washingMachine = washingMachine;
    }

    void execute() {
        this->washingMachine->TurnOn();
    }

};

//Command
class StartQuick30WashCommand: public Command {
    //Receiver
    WashingMachine* washingMachine;
    public:
    StartQuick30WashCommand(WashingMachine* washingMachine) {
        this->washingMachine = washingMachine;
    }
    
    void execute() {
        this->washingMachine->StartQuick30Wash();
    }
};


//invoker
class RemoteControlForTVAndWashingMachine {

    //this could also be an array, for simplification, I'll just change the reference to different commands
    //i.e Command* command[no] - where no could be no of buttons. 

    //for now, let's simply assume that you can only control one device at a time since there's only one button
    Command* command;
    public:
    RemoteControlForTVAndWashingMachine(Command* command) {
        this->command = command;
    }

    void SetCommand(Command* command) {
        this->command = command;
    }

    void PressButton() {
        this->command->execute();
    }
};


int main() {
    ElectronicTV electronicTV;
    WashingMachine washingMachine;

    RemoteControlForTVAndWashingMachine remoteControl(new TurnOnTV(&electronicTV));

    //Turns on the TV
     remoteControl.PressButton();

    //Turns on Washing Machine
     remoteControl.SetCommand(new TurnOnWashingMachine(&washingMachine));
     remoteControl.PressButton();

    //StartsQuickWash if the machine was on
     remoteControl.SetCommand(new StartQuick30WashCommand(&washingMachine));
     remoteControl.PressButton();

    return 0;
}