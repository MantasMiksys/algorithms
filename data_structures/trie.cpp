
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode * children[ALPHABET_SIZE];
    bool isEndOfWord;
};

class Trie {
private:
    TrieNode * head;
public:
    Trie() : head(new TrieNode()) { }

    void insert(const string & s) {
        TrieNode * cur = head;
        for(const char & c : s) {
            int i = c - 'a';
            if(cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->isEndOfWord = true;
    }

    bool contains(const string & s) {
        TrieNode * cur = head;
        for(const char & c : s) {
            int i = c - 'a';
            if(cur->children[i] == nullptr)
                return false;
            cur = cur->children[i];
        }
        return cur!=nullptr && cur->isEndOfWord;
    }
};


int main() {

    Trie t;
    t.insert("abcd");
    t.insert("abc");
    t.insert("abe");
    t.insert("dog");

    cout << t.contains("ab") << endl;
    cout << t.contains("abcd") << endl;
    cout << t.contains("abc") << endl;
    cout << t.contains("dog") << endl;
    cout << t.contains("do") << endl;
    return 0;
}

