#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stock {
    string ticker;
public:
    Stock(const string & ticker) : ticker(ticker) {}

    void buy(unsigned amount) {
        cout << "Bought " << amount << " of " << ticker << endl;
    }


    void sell(unsigned amount) {
        cout << "Sold " << amount << " of " << ticker << endl;
    }
};

class Order {
public:
     virtual void execute() = 0; 
};

class BuyOrder : public Order {
Stock stock;
unsigned amount;
public:
    BuyOrder(const Stock & s, unsigned amount) : stock(stock), amount(amount) {}
    void execute() {
        stock.buy(amount);
    }
};

class SellOrder : public Order {
Stock stock;
unsigned amount;
public:
    SellOrder(const Stock & stock, unsigned amount) : stock(stock), amount(amount) {}
    void execute() {
        stock.sell(amount);
    }
};

class Broker {
    vector<Order*> orders;
public:
    void takeOrder(Order * order) {
        orders.push_back(order);
    }

    void placeOrders() {
        for(Order * order : orders) {
            order->execute();
        }
    }
};


int main() {

    Broker broker;
    broker.takeOrder(new BuyOrder(Stock("IBM US Equity"), 20));
    broker.takeOrder(new SellOrder(Stock("AAPL US Equity"), 5));

    broker.placeOrders();
}