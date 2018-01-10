#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Shape {
public:
    void draw();
};

class Circle : public Shape {
private:
    string color;
    int x, y, radius;
public:
    Circle(const string & color) : color(color) {}

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setRadius(int radius) {
        this->radius = radius;
    }

    void draw() {
        cout << "Drawing circle x=" << x << " y=" << y << " radius=" << radius << endl;
    }

};

class ShapeFactory {
    static unordered_map<string, Circle*> circleMap;
public:
    static Circle * getCircle(const string & color) {
        if(circleMap.find(color) == circleMap.end()) {
            circleMap[color] = new Circle(color);
        }
        return circleMap.at(color);
    }
};

unordered_map<string, Circle*> ShapeFactory::circleMap;

int main() {
    auto circle = ShapeFactory::getCircle("green");
    circle->setX(2);
    circle->setY(3);
    circle->setRadius(4);
    circle->draw();
    
}
