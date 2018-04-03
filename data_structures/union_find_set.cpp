#include <iostream>
#include "union_find_set.h"

using namespace std;

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
