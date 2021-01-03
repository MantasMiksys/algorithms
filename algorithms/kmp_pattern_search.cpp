#include <iostream>
#include <string>
#include <vector>

using namespace std;

// O(m) in the worst case

vector<int> kmpProcess(const string& needle) {
    int n = needle.size();
    vector<int> lps(needle.size(), 0);
    for(int i = 1, len = 0; i < n;) {
        if(needle[i] == needle[len]) {
            lps[i++] = ++len;
        } else if(len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

// strStr returns index for the first occurence of needle in haystack.
int strStr(const string& haystack, const string& needle) {
    int m = haystack.size(), n = needle.size();
    if(!n) {
        return 0;
    }
    vector<int> lps = kmpProcess(needle);
    for(int i = 0, j = 0; i < m;) {
        if(haystack[i] == needle[j]) {
            i++, j++;
        }
        if(j == n) {
            return i -j;
        }
        if(i < m && haystack[i] != needle[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    return -1;
}


int main() {
    string haystack = "hello", needle = "ll";
    cout << strStr(haystack, needle) << endl;
}