#include <iostream>
#include <vector>

using namespace std;

// TODO finish the implementation

void insertionSort(vector<double> & v) {
}

void bucketSort(vector<double> & v) {
    int n = v.size();
    vector<vector<double>> b(n, vector<double>());
    for(auto e : v) {
        int i = n * e;
        b[i].push_back(e);
    }
    for(int i = 0; i < b.size(); ++i) {
        if(!b[i].empty()) {
            insertionSort(b[i]);
        }
    }

    // combine the sorted buckets
}

int main() {
    vector<double> v{0.3, 0.5, 0.1, 0.1, 0.01, 0.4};
    bucketSort(v);

    return 0;
}