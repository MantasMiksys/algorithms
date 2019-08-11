#include <numeric>
#include <vector>

using namespace std;

// this is actually weighted union which gives O(log(n))
class UnionFindSet {
 private:
  vector<int> arr;
  vector<int> size;

  int root(int a) {
    while (arr[a] != a) {
      // This line make root O(log*(N)) which is pretty much const
      arr[a] = arr[arr[a]];
      a = arr[a];
    }
    return a;
  }

 public:
  UnionFindSet(int N) : arr(N), size(N, 1) { iota(arr.begin(), arr.end(), 0); }

  void makeUnion(int a, int b) {
    int rootA = root(a), rootB = root(b);
    if (rootA == rootB) return;
    int largerRoot = (size[rootA] > size[rootB]) ? rootA : rootB;
    int smallerRoot = (size[rootA] <= size[rootB]) ? rootA : rootB;
    arr[smallerRoot] = largerRoot;
    size[largerRoot] += size[smallerRoot];
  }

  bool find(int a, int b) { return root(a) == root(b); }
};
