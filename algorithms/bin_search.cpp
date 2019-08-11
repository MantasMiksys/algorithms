#include <iostream>
#include <vector>

using namespace std;

// smallest index matching the specified value
int binSearchSmallest(const vector<int>& v, int x) {
  int i = 0, j = v.size() - 1, m;
  while (i < j) {
    m = (i + j) / 2;
    if (v[m] == x)
      j = m;
    else if (v[m] < x)
      i = m + 1;
    else
      j = m - 1;
  }
  return (v[i] == x) ? i : -1;
}

int binSearchLargest(const vector<int>& v, int x) {
  int i = 0, j = v.size() - 1, m;
  while (i < j) {
    m = (i + j + 1) / 2;  // or ceil((i + j) / (double) 2);
    if (v[m] == x)
      i = m;
    else if (v[m] < x)
      i = m + 1;
    else
      j = m - 1;
  }
  return (v[i] == x) ? i : -1;
}

int binSearch(const vector<int>& v, int x) {
  int i = 0, j = v.size() - 1, m;
  while (i < j) {
    m = (i + j) / 2;
    if (v[m] == x)
      return m;
    else if (v[m] < x)
      i = m + 1;
    else
      j = m - 1;
  }
  return (v[i] == x) ? i : -1;
}

int main() {
  vector<int> v = {1, 3, 4, 6, 8, 9};
  cout << "expected=" << 2 << ", actual=" << binSearch(v, 4) << endl;
  cout << "expected=" << -1 << ", actual=" << binSearch(v, 2) << endl;

  vector<int> v2 = {1, 1, 1, 2, 3, 4, 5, 6};
  cout << "expected=" << 0 << ", actual=" << binSearchSmallest(v2, 1) << endl;
  cout << "expected=" << 6 << ", actual=" << binSearchSmallest(v2, 5) << endl;

  cout << "expected=" << 2 << ", actual=" << binSearchLargest(v2, 1) << endl;
  cout << "expected=" << 5 << ", actual=" << binSearchLargest(v2, 4) << endl;

  return 0;
}
