#include <iostream>
#include <string>

using namespace std;

class Theme {
public:
    virtual string getColor() = 0;
};

class DarkTheme : public Theme {
public:
    string getColor() {
        return "Dark Black";
    }
};

class Webpage {
public:
    virtual void getContents() = 0;
};

class About : public Webpage {
Theme * theme;
public:
    About(Theme * theme) : theme(theme) { }
    void getContents() {
        cout << "About page in " << theme->getColor() << endl;
    }
};

int main() {
    auto about = new About(new DarkTheme());
    about->getContents();
}
