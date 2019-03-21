#include <iostream>
#include <bits/stdc++.h>


class Flyable {
public:
    virtual void fly() = 0;
};

class Quackable {
public:
    virtual void quack() = 0;
};

class FlyWithWings: public Flyable {
    void fly() {
        std::cout << "I am flying with wings" << std::endl;
    }
};

class CantFly : public Flyable {
    void fly() {
        std::cout << "I can't fly, because no wings" << std::endl;
    }
};

class CanQuack: public Quackable {
    void quack() {
        std::cout << "i am quacking, because i am a rubber duck" << std::endl;
    }
};

class CantQuack: public Quackable {
    void quack() {
        std::cout << "I can't quack, because you have mistaken me " << std::endl;
    }
};

class Duck {
public:
    Flyable* flyable;
    Quackable* quackable;
    std::string description;
    Duck() {
        description = "I am a duck";
    }
    void setFlyable(Flyable* fly) {
        this->flyable = fly;
    }
    virtual void setQuackable(Quackable* quack) {
        this->quackable = quack;
    }
    void performFly() {
        if (flyable != NULL) {
            flyable->fly();
        }
    }

    void performQuack() {
        if(quackable != NULL) {
            quackable->quack();
        }
    }
};

class RealDuck: public Duck {
public:
    RealDuck() {
        description = "I am a real duck";
    }

};

class RubberDuck: public Duck {
public:
    RubberDuck() {
        description = "I am a rubber duck";
    }

};


int main() {
    Duck* duck = new RubberDuck();
    duck->setFlyable(new CantFly());
    duck->setQuackable(new CanQuack());
    duck->performFly();
    duck->performQuack();
    std::cout << duck->description << std::endl;

    duck = new RealDuck;
    duck->setFlyable(new FlyWithWings());
    duck->setQuackable(new CantQuack());
    duck->performFly();
    duck->performQuack();
    std::cout << duck->description << std::endl;
    return 0;
}
