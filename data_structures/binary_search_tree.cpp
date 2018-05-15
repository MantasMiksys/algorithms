#include <iostream>

using namespace std;

struct BSTNode {
    BSTNode * left;
    BSTNode * right;
    int key;

};

// assume no duplicate keys
class BinarySearchTree {
public:
    void insert(int key);
    void remove(int key);
    bool contains(int key) const;

private:
    BSTNode * root{nullptr};
};

void BinarySearchTree::insert(int key) {
    BSTNode * newNode = new BSTNode{nullptr, nullptr, key};
    if (root == nullptr) {
        root = newNode;
    } else {
        auto cur = root;
        auto prev = root;
        while(cur != nullptr) {
            prev = cur;
            if(cur->key <= key) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        if(prev->key <= key) {
            prev->right = newNode;
        } else {
            prev->left = newNode;
        }
    }
}

void BinarySearchTree::remove(int key) {
    if(root->key == key) {
        delete root;
        root = nullptr;
    } else {
        auto cur = root;
        auto prev = root;
        while(cur != nullptr && cur->key != key) {
            prev = cur;
            if (cur->key < key) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        if(cur != nullptr) {
            delete cur;
            if (prev->key < key) {
                prev->right = nullptr;
            } else {
                prev->left = nullptr;
            }
        }
    }
}

bool BinarySearchTree::contains(int key) const {
    auto cur = root;
    while(cur != nullptr) {
        if(cur->key == key) {
            return true;
        } else if(cur->key < key) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return false;
}

int main() {
    BinarySearchTree tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    cout << boolalpha << tree.contains(2) << endl;
    tree.remove(2);
    cout << boolalpha << tree.contains(2) << endl;
}
