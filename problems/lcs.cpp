#include <string>
#include <iostream>
#include <vector>

using namespace std;


int lcs(const string & a, const string & b) {

    vector<vector<int>> l(a.size(), vector<int>(b.size(), 0));

    for(auto i = 1; i < a.size(); ++i) {
        for(auto j = 1; j < b.size(); ++j){
            
            if(a[i] == b[j]){
                l[i][j] = 1 + l[i-1][j-1];
            } else {
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }

        }
    }
    return l.back().back();
}

int main() {
    string a = "abscdda";
    string b = "xsyda";
    cout << lcs(a, b) << endl;

    return 0;
}
