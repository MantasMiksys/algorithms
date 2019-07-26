#include <iostream>
#include <vector>

using namespace std;

// smallest index matching the specified value
int binSearchSmallest(const vector<int>& v, int x) { return -1; }

int binSearch(const vector<int>& v, int x) {
  int i = 0, j = v.size() - 1, m;
  while (i < j) {
    m = (i + j) / 2;
    if (v[m] == i)
      return m;
    else if (v[m] > i)
      i = m + 1;
    else
      j = m - 1;
  }
  return (v[i] == x) ? i : -1;
}

int main() {
  vector<int> v = {1, 3, 4, 6, 8, 9};
  cout << binSearch(v, 4) << endl;
  cout << binSearch(v, 2) << endl;

  return 0;
}
