#include "heap.h"

#include <iostream>

using namespace std;

int main(){
    MaxHeap heap(5);

    heap.insert(1);
    heap.insert(2);
    heap.insert(4);
    heap.insert(3);

    cout << heap.pop() << endl;

    return 0;
}