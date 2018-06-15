/* A binary heap is a collection of keys arranged in a complete heap-ordered binary tree, represented in level order in an array (not using the first entry). */

#include <algorithm>
#include <iostream>
#include "stddef.h"

using namespace std;

class MaxHeap {
    int * pq;
    size_t N;
    size_t capacity;

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int parent(int i) {
        return (i-1)/2;
    }

    void swim(int k) {
        while (k > 0 && pq[k] > pq[parent(k)]) {
            swap(pq[k], pq[parent(k)]);
            k = parent(k);
        }
    }

    void sink(int k) {
        int l = left(k);
        int r = right(k);
        int largest = k;

        if (l < N && pq[l] > pq[largest]) {
            largest = l;
        } else if (r < N && pq[r] > pq[largest]){
            largest = r;
        } 
        if (largest != k) {
            swap(pq[k], pq[largest]);
            sink(largest);
        }
    }

public:

    MaxHeap(size_t size) : N(0), capacity(size) {
        pq = new int[size];
    }

    ~MaxHeap() {
        delete [] pq;
    }

    void insert(int value) {
        pq[N] = value;
        ++N;
        swim(N-1);
    }

    int pop() { // delete max
        int max = pq[0];
        swap(pq[0], pq[N-1]);
        --N;
        pq[N] = -1;
        sink(0);
        return max;
    } 

    size_t size() {
        return N;
    }

    void printHeap() {
        for(int i = 0; i < N; ++i){
            cout << pq[i] << " ";
        }
        cout << endl;
    }
};
