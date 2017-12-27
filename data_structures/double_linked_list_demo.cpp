#include "double_linked_list.h"
#include <exception>
#include <iostream>


int main() {
    DoubleLinkedList l;
    l.insertAt(0, 5);
    l.pushBack(4);
    l.pushBack(2);
    l.insertAt(2, 3);

    try {
        l.insertAt(-1, 0);
    } catch (std::invalid_argument & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    l.print();

    l.deleteAt(2);
    l.print();

    l.deleteAt(0);
    l.print();


    return 0;
}