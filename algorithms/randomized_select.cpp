#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <cstdlib>

using namespace std;


int partition(vector<int> & v, int s, int e) {
    int x = v[e];
    int p = s - 1;

    for(int i = s; i < e; ++i) {
        if(v[i] <= x) {
            ++p;
            swap(v[i], v[p]);
        }
    }
    swap(v[p+1], v[e]);

    return p+1;
}

int randomizedPartition(vector<int> & v, int s, int e) {
    int r = rand() % (e - s);
    swap(v[r + s], v[e]);

    return partition(v, s, e);
}

int randomizedSelect(vector<int> & v, int l, int h, int k) {
    if(l == h){
        return v[l];
    }
    int p = randomizedPartition(v, l, h);
    int w = p - l;
    if(w == k)
        return v[p];
    else if(k < w)
        return randomizedSelect(v, l, p - 1, k);

    return randomizedSelect(v, p + 1, h, k - w - 1);
}

int main() {
    vector<int> v{3, 1, 0, 5, 2, 4, 2};
    int q = randomizedSelect(v, 0, v.size()-1, 3);
    cout << q << endl;
    return 0;
}