#include <iostream>

using namespace std;

// Bridge is designed up-front to let the abstraction and the implementation vary independently. Adapter is retrofitted to make unrelated classes work together.

// Facade defines a new interface, whereas Adapter reuses an old interface. Remember that Adapter makes two existing interfaces work together as opposed to defining an entirely new one.

class Bird {
public:
    virtual void fly() = 0;
    virtual void chirp() = 0;;
};

class Sparrow : public Bird {
public:
    void fly() {
        cout << "Flying" << endl;;
    }

    void chirp() {
        cout << "Chirp Chirp" << endl;
    }
};
 
class ToyDuck {
public:
    virtual void squeak() = 0;
};
 
class PlasticToyDuck : public ToyDuck {
public:
void squeak(){
    cout << "Squeak" << endl;
}
};
 
class BirdAdapter : public ToyDuck {
Bird * bird;
public:
    BirdAdapter(Bird * bird) : bird(bird) {}
    void squeak(){
        bird->chirp();
    }
};

int main(){
    auto sparrow = new Sparrow();
    auto birdAdapter = new BirdAdapter(sparrow);
    birdAdapter->squeak();
}
