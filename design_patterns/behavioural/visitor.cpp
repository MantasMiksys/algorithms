#include <iostream>
#include <vector>

using namespace std;

class Motherboard;
class Monitor;
class Mouse;
class Keyboard;

class ComputerPartVisitor {
public:
    virtual void visit(Motherboard * motherboard) = 0;
    virtual void visit(Monitor * monitor) = 0;
    virtual void visit(Mouse * mouse) = 0;
    virtual void visit(Keyboard * keyboard) = 0;
};

class ComputerPartConnectorVisitor : public ComputerPartVisitor {
public:
    void visit(Motherboard * motherboard) {
        cout << "Connecting motherboard" << endl;
    }
    void visit(Monitor * monitor) {
        cout << "Connecting monitor" << endl;
    }

    void visit(Mouse * mouse) {
        cout << "Connecting mouse" << endl;
    }

    void visit(Keyboard * keyboard) {
        cout << "Connecting mouse" << endl;
    }
};

class ComputerPart {
public:
    virtual void accept(ComputerPartVisitor * visitor) = 0;
};

class Monitor : public ComputerPart {
public:
    void accept(ComputerPartVisitor * visitor) {
        visitor->visit(this);
    }
};

class Keyboard : public ComputerPart {
public:
    void accept(ComputerPartVisitor * visitor) {
        visitor->visit(this);
    }
};

class Mouse : public ComputerPart {
public:
    void accept(ComputerPartVisitor * visitor) {
        visitor->visit(this);
    }
};

class Motherboard : public ComputerPart{
vector<ComputerPart*> parts;
public:
    Motherboard() : parts{new Monitor(), new Keyboard(), new Mouse()} {}

    void accept(ComputerPartVisitor * visitor) {
        for(auto part : parts) {
            part->accept(visitor);
        }
        visitor->visit(this);
    }
};

int main() {
    Motherboard motherboard;
    motherboard.accept(new ComputerPartConnectorVisitor());
}