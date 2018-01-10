#include <iostream>

using namespace std;

// A facade is an object that provides a simplified interface to a larger body of code, such as a class library.

class Computer {
public:
    void showLoadingScreen() {
        cout << "Loading screen..." << endl;
    }

    void initOS() {
        cout << "Initializing OS" << endl;
    }

    void initSystemProcesses() {
        cout << "Initializing system processes" << endl;
    }

    void showLoginPage() {
        cout << "Login page" << endl;
    }

    void stopUserApps(){
        cout << "Stopping user apps" << endl;
    }

    void stopSystemProcesses(){
        cout << "Stopping system processes" << endl;
    }

    void stopOS() {
        cout << "Stopping OS" << endl;
    }
};

class ComputerFacade {
Computer * m_computer;
public:
    ComputerFacade(Computer * computer) : m_computer(computer) {}

    void turnOn() {
        m_computer->showLoadingScreen();
        m_computer->initOS();
        m_computer->initSystemProcesses();
        m_computer->showLoginPage();    
    }

    void turnOff() {
        m_computer->stopUserApps();
        m_computer->stopSystemProcesses();
        m_computer->stopOS();
    }
};

int main() {
    auto computer = new ComputerFacade(new Computer());
    computer->turnOn();
    cout << "Computer is on" << endl;
    computer->turnOff();

    return 0;
}
