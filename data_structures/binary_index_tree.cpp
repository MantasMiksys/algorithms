#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class BinaryIndexTree {
    unsigned int N;
    int * bit;
public:
    BinaryIndexTree(int maxIndex) : N(maxIndex), bit(new int[N]) { }

    void update(unsigned int x, int val) {
        for(; x <= N;x += x&(-x))
             bit[x] += val;
    }

    int query(int x) {
        int res = 0;
        for(; x > 0; x -= x&(-x))
            res += bit[x];
        return res;
    }
};

int main() {
    BinaryIndexTree bit(10);
    vector<int> v{1, 4, 5, -6, 8, 2, 3, 1};
    for(int i = 1; i < v.size() + 1; ++i) {
        bit.update(i, v[i-1]);
    }
    cout << "Sum of the first 5 elements is " << bit.query(5) << endl;
    cout << "Sum of elements in range [3, 5] is " << bit.query(5) - bit.query(2) << endl;

    return 0;
}
