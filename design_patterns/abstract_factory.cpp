#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


class AbstractWidgetFactory {
    public:
        virtual string createButton() = 0;

        virtual string createPanel() = 0;
};

class WindowsWidgetFactory : public AbstractWidgetFactory {
    public: 
        string createButton(){
            return "windows_button";
        }

        string createPanel(){
            return "windows_panel";
        }
};

class LinuxWidgetFactory : public AbstractWidgetFactory {
    public:
        string createButton() override {
            return "linux_button";
        }

        string createPanel() override {
            return "linux_panel";
        }
};


AbstractWidgetFactory * getWidgetFactory(const string & os){
    if(os == "Windows"){
        return new WindowsWidgetFactory();
    } else if (os == "Linux") {
        return new LinuxWidgetFactory();
    }
    throw runtime_error("Unsupported OS!");
}



int main() {

    string os = "Windows";
    cout << os << endl;

    try {
        AbstractWidgetFactory * factory = getWidgetFactory(os);
        cout << factory->createButton() << " " << factory->createPanel() << endl;
    } catch (const exception & e){
        cerr << e.what() << endl;
        throw;
    }

    return 0;
}