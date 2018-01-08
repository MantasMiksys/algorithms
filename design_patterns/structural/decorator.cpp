#include <iostream>
#include <string>

using namespace std;

class Coffee {
public:
    virtual string getDescription() = 0;
    virtual unsigned getCost() = 0;
};

class SimpleCoffee : public Coffee {
public:
    string getDescription() { return "Coffee"; }

    unsigned getCost() { return 3; }
};

class MilkCoffee : public Coffee {
Coffee * coffee;
public:
    MilkCoffee(Coffee * coffee) : coffee(coffee) {}

    string getDescription() { return coffee->getDescription() + ", milk"; }
    unsigned getCost() { return coffee->getCost() + 1; }
};

class VanillaCoffee : public Coffee {
Coffee * coffee;
public:
    VanillaCoffee(Coffee * coffee) : coffee(coffee) {}

    string getDescription() { return coffee->getDescription() + ", vanilla"; }
    unsigned getCost() { return coffee->getCost() + 1; }
};

int main() {
    auto simpleCoffee = new SimpleCoffee();
    auto milkCoffee = new MilkCoffee(simpleCoffee);
    auto vanillaCoffee = new VanillaCoffee(milkCoffee);

    cout << vanillaCoffee->getDescription() << " -> " << vanillaCoffee->getCost() << endl;
}
