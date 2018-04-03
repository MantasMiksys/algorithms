#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<double> & v) {

    for(int i = 1; i < v.size(); ++i){
        double e = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > e){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = e;
    }
}

void bucketSort(vector<double> & v) {
    int n = v.size();
    vector<vector<double>> b(n, vector<double>());
    for(auto e : v) {
        int i = n * e;
        b[i].push_back(e);
    }
    for(int i = 0; i < b.size(); ++i) {
        insertionSort(b[i]);
    }
    int c = 0;
    for(int i = 0; i < b.size(); ++i) {
        for(int j = 0; j < b[i].size(); ++j) {
            v[c] = b[i][j];
            ++c;
        }
    }
}

int main() {
    vector<double> v{0.3, 0.5, 0.1, 0.1, 0.01, 0.4};
    bucketSort(v);
    for(auto e : v) {
        cout << e << endl;
    }
    return 0;
}