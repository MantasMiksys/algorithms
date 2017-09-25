#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(vector<int> & v) {

    for(int i = 0; i < v.size()-1; ++i){
        // finding ith smallest item
        int m = i;
        for(int j = i + 1; j < v.size(); ++j){
            if(v[m] > v[j])
                m = j;
        }
        swap(v[i], v[m]);
    }
}

int main() {
    vector<int> v{4, 2, 4, 2, 1, 5, 10, -1};
    selectionSort(v);
    for_each(v.begin(), v.end(), [](int e) { cout << e << endl; });

    return 0;
}