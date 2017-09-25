#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int> & v) {

    for(int i = 0; i < v.size()-2; ++i){
        for(int j = v.size()-1; j > i; --j){
            if(v[j] < v[j-1]){
                swap(v[j], v[j-1]);
            }
        }
    }
}

int main() {
    vector<int> v{4, 2, 4, 2, 1, 5, 10, -1};
    bubbleSort(v);
    for_each(v.begin(), v.end(), [](int e) { cout << e << endl; });

    return 0;
}