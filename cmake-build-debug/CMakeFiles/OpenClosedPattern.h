
#ifndef UNTITLED_OPENCLOSEDPATTERN_H
#define UNTITLED_OPENCLOSEDPATTERN_H
#include <bits/stdc++.h>
class Flyable {
public:
    virtual void fly()  = 0;
};
class Quackable {
public:
    virtual void quack() = 0;
};
class FlyWithWings: public Flyable {
public:
    void fly();
};
class CantFly: public Flyable{
public:
    void fly();
};

class CanQuack: public Quackable{
public:
    void quack();
};
class CantQuack: public Quackable {
public:
    void quack();
};

class Duck {
public:
    Flyable* flyable;
    Quackable* quackable;
    std::string description;
    void setFlyable(Flyable* flyable);
    void setQuackable(Quackable* quackable);
    void performFly();
    void performQuack();
};

class RubberDuck: public Duck {
public:
    RubberDuck();
};

class RealDuck: public Duck {
public:
    RealDuck();
};

class OpenClosedPatternDriver {
public:
    static void Main();
};

#endif //UNTITLED_OPENCLOSEDPATTERN_H
