#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void merge(vector<int> & v, int i, int m, int j){
    vector<int> b(j - i + 1);

    int k = 0;
    int p = i;
    int q = m+1;

    while(p <= m && q <=j){
        if(v[p] < v[q]){
            b[k] = v[p];
            ++p;
        }else{
            b[k] = v[q];
            ++q;
        }
        ++k;
    }

    while(p <= m){
        b[k] = v[p];
        ++p;
        ++k;
    }

    while(q <= j){
        b[k] = v[q];
        ++q;
        ++k;
    }

    for(int x = 0; x < b.size(); ++x) {
        v[i + x] = b[x];
    }
}


void mergeSortAux(vector<int> & v, int i, int j) {
    if(i < j){
        int mid = (i + j)/2;
        mergeSortAux(v, i, mid);
        mergeSortAux(v, mid + 1, j);
        merge(v, i, mid, j);  
    }
}

void mergeSort(vector<int> & v) {
    mergeSortAux(v, 0, v.size()-1);
}

int main() {
    vector<int> v{4, 2, 4, 2, 1, 5, 10, -1};
    mergeSort(v);
    for_each(v.begin(), v.end(), [](int e) { cout << e << endl; });

    return 0;
}
