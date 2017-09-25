#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestIncreasingSequence(const vector<int> & v) {
    vector<int> m(v.size());

    for (auto i = 0; i < v.size(); ++i) {
        if (i == 0 || v[i] < v[i-1]) {
            m[i] = 1;
        } else {
            m[i] = m[i-1] + 1;
        }
    }

    return *max_element(m.begin(), m.end());
}

int main() {
    vector<int> v{2, 1, 2, 3, 2, 5};
    cout << longestIncreasingSequence(v) << endl;
    return 0;
}
