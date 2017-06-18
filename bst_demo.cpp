#include "bst.h"
#include "string.h"

using namespace std;

int main()
{
    BST bst;
    bst.insert(5, "a");
    bst.insert(4, "b");
    bst.insert(6, "c");
    bst.insert(7, "d");
    bst.insert(8, "e");
    bst.insert(1, "f");
    bst.insert(2, "g");
    bst.insert(3, "h");
    bst.printInOrder();

    cout << bst.find(4) << endl;

    cout << "Causual print" << endl;
    bst.printInOrder();

    cout << "Delete 5" << endl;
    bst.remove(5);
    bst.printInOrder();

    cout << "Delete 1" << endl;
    bst.remove(1);
    bst.printInOrder();

    return 0;
}