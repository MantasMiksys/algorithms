#include <iostream>

class Color {
private:
    int r, g, b;
    Color(int r, int g, int b) : r(r), g(g), b(b) {}
public:
    // factory method
    static Color makeColorRGB(int r, int g, int b) {
        std::cout << "Creating new color" << std::endl;
        return Color(r, g, b);
    }

};

int main() {
    Color c = Color::makeColorRGB(10, 20, 30);
    return 0;
}
