#include "OpenClosedPattern.h"
#include <bits/stdc++.h>



void FlyWithWings::fly() {
    std::cout << "I can fly because I am a real duck" << std::endl;
}

void CantFly::fly() {
    std::cout << "I can't fly because I'm fake" << std::endl;
}
void CanQuack::quack() {
    std::cout << "I can quack, bcz I am rubber duck" << std::endl;
}

void CantQuack:: quack() {
    std::cout << "I can't quack" << std:: endl;
}

void Duck::setQuackable(Quackable *quackable) {
    this->quackable = quackable;
}

void Duck::setFlyable(Flyable *flyable) {
    this->flyable = flyable;
}

void Duck::performFly() {
    this->flyable->fly();
}

void Duck::performQuack() {
    this->quackable->quack();
}

RubberDuck::RubberDuck() {
    description  = "I am a rubber duck";
}

RealDuck::RealDuck() {
    description = "I am a real duck";
}


void OpenClosedPatternDriver::Main() {
    Duck* duck = new RubberDuck();
    duck->setFlyable(new CantFly());
    duck->setQuackable(new CanQuack());
    duck->performFly();
    duck->performQuack();
    std::cout << duck->description << std::endl;

    duck = new RealDuck();
    duck->setFlyable(new FlyWithWings());
    duck->setQuackable(new CantQuack());
    duck->performFly();
    duck->performQuack();
    std::cout << duck->description << std::endl;
}