#include <iostream>
#include <vector>
#include <utility>

using namespace std;


void heapify(vector<int> & v, int i, int heapSize){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < heapSize && v[l] > v[largest])
        largest = l;

    if(r < heapSize && v[r] > v[largest])
        largest = r;

    if(largest != i){
        swap(v[largest], v[i]);
        heapify(v, largest, heapSize);
    }
}

void heapSort(vector<int> & v){
    int n = v.size();
    for(int i = v.size()/2 - 1; i >=0; --i)
        heapify(v, i, n);

    for(int i = n-1; i>=0; --i){
        swap(v[0], v[i]);
        heapify(v, 0, i);
    }
}

int main() {
    vector<int> v{4, 2, 5, 2, 5, 6, -1, 9};
    heapSort(v);

    for(int e : v){
        cout << e << endl;
    }

    return 0;
}