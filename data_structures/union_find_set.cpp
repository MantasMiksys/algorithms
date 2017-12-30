#include <iostream>

using namespace std;

// this is actually weighted union which gives O(log(n))
class UnionFindSet {
private:
    int root(int a) {
        while(arr[a] != a) {
            // This line make root O(log*(N)) which is pretty much const
            arr[a] = arr[arr[a]];
            a = arr[a];
        }
        return a;
    }
    int * arr;
    int * size;
public:
    UnionFindSet(int N) : arr(new int[N]), size(new int[N]) {
        for(int i = 0; i < N; ++i) {
            arr[i] = i;
            size[i] = 1;
        }
    }

    void makeUnion(int a, int b) {
        int rootA = root(a);
        int rootB = root(b);
        int largerRoot = (size[rootA] > size[rootB]) ? rootA : rootB;
        int smallerRoot = (size[rootA] <= size[rootB]) ? rootA : rootB;
        arr[smallerRoot] = largerRoot;
        size[largerRoot]+= size[smallerRoot];
    }

    bool find(int a, int b) {
        return root(a) == root(b);
    }
};

int main() {
    UnionFindSet ufs(10);
    ufs.makeUnion(2, 5);
    ufs.makeUnion(2, 4);
    ufs.makeUnion(9, 0);

    cout << boolalpha;
    cout << "Exp=false, act=" << ufs.find(5, 0) << endl;
    cout << "Exp=true, act=" << ufs.find(4, 5) << endl;
    cout << "Exp=true, act=" << ufs.find(2, 5) << endl;
    cout << "Exp=false, act="  << ufs.find(6, 7) << endl;
}
