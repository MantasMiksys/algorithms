#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Employee {
    string name;
    unsigned salary;
    vector<Employee *> subordinates;
public:
    Employee(const string & name, unsigned salary) : name(name), salary(salary) {}

    void addSubordinate(Employee * e) {
        subordinates.push_back(e);
    }

    void print(ostream & os) {
        os << "[" << name << ", " << salary << " (";
        for(auto & sub : subordinates) {
            sub->print(os);
            if (&sub != &subordinates.back())
                os << ",";
        }
        os << ")]";
    }
};

int main() {
    auto e1 = new Employee("Algis", 1000);
    auto e2 = new Employee("Kazys", 2000);
    auto e3 = new Employee("Juozas", 3000);
    e1->addSubordinate(e2);
    e2->addSubordinate(e3);
    e1->print(cout);
}
