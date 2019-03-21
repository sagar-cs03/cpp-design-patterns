#include <iostream>

class Pizza {
public:
    std::string description;
    int price;
    Pizza() {
        description = "this is a normal pizza";
        price = 50;
    }
    virtual int getPrice() = 0;
    virtual std::string getDescription() = 0;
};

class CrustedPizza: public Pizza {
public:
    CrustedPizza() {

    }

    int getPrice() {
        return 50;
    }
    std::string getDescription() {
        return "this is a crusted pizza";
    }
};

class ToppingDecorator: public Pizza {
public:
    Pizza* pizza ;
    ToppingDecorator() {

    };

    int getPrice() {
        pizza->getPrice();
    }
     std::string getDescription() {
        pizza->getDescription();
    }
};


class PineAppleToppingDecorator: public ToppingDecorator {
public:
    PineAppleToppingDecorator(Pizza* piz) {
        this->pizza = piz;
    }
    int getPrice() {
        return pizza->getPrice() + 20;
    }
    std::string getDescription() {
        return pizza->getDescription() + "with pineapple topping";
    }
};

class SausageDecorator: public ToppingDecorator {
public:
    SausageDecorator(Pizza* piz) {
        this->pizza = piz;
    }
    int getPrice() {
        return pizza->getPrice() + 30;
    }
    std::string getDescription() {
        return pizza->getDescription() + "with sausage topping" ;
    }
};

int main() {
    Pizza* pizza = new CrustedPizza;
    std::cout << pizza->getDescription() << " " << pizza->getPrice() << std::endl;
    pizza = new PineAppleToppingDecorator(pizza);
    std::cout << pizza->getDescription() << " " << pizza->getPrice() << std::endl;
    pizza = new SausageDecorator(pizza);
    std::cout << pizza->getDescription() << " " << pizza->getPrice() <<std::endl;
    return 0;
}
