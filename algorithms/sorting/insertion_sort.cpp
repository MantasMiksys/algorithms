#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void insertionSort(vector<int> & v) {

    for(int i = 1; i < v.size(); ++i){
        int e = v[i];
        int j = i - 1;
        while(j > 0 && v[j] > e){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = e;
    }
}

int main() {
    vector<int> v{4, 2, 4, 2, 1, 5, 10, -1};
    insertionSort(v);
    for_each(v.begin(), v.end(), [](int e) { cout << e << endl; });

    return 0;
}