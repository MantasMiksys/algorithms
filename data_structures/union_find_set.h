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
        if(rootA == rootB)
            return;
        int largerRoot = (size[rootA] > size[rootB]) ? rootA : rootB;
        int smallerRoot = (size[rootA] <= size[rootB]) ? rootA : rootB;
        arr[smallerRoot] = largerRoot;
        size[largerRoot]+= size[smallerRoot];
    }

    bool find(int a, int b) {
        return root(a) == root(b);
    }
};
