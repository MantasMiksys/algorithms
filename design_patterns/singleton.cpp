#include <iostream>

using namespace std;

class GlobalClass {
    int m_value = 0;

    public:
        static GlobalClass & getInstance(){
            static GlobalClass instance;

            return instance;
        }

        int getValue() {
            return m_value;
        }

};


int main() {

    auto gc = GlobalClass::getInstance();

    cout << "value: " << gc.getValue() << endl;

    return 0;
}