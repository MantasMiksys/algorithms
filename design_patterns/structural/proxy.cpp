#include <iostream>
#include <string>

using namespace std;

class Image {
public:
    virtual void display() = 0;
};

class RealImage : public Image {
    string filename;
public:
    RealImage(const string & filename) : filename(filename) {
        // loading image from disk
    }
    void display() {
        cout << "Displaying " << filename << endl;
    }
};

class ProxyImage : public Image {
    string filename;
    RealImage * image{nullptr};
public:
    ProxyImage(const string & filename) : filename(filename) {
        // NOT loading image from disk
    }

    void display() {
        if(image == nullptr) {
            image = new RealImage(filename);
        }
        image->display();
    }
};

int main() {
    auto image = new ProxyImage("image.jpg");
    image->display();
    image->display();
}
