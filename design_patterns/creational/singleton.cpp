#include <iostream>

using namespace std;

class Singleton {
    int m_value = 0;

    public:
        static Singleton & getInstance(){
            static Singleton instance;

            return instance;
        }

        int getValue() {
            return m_value;
        }
};

int main() {

    auto gc = Singleton::getInstance();

    cout << "value: " << gc.getValue() << endl;

    return 0;
}
