/* 
A binary search tree (BST) is a binary tree where each node has a Comparable key (and an associated value) and satisfies the restriction that the key in any node is larger than the keys in all nodes in that node’s left subtree and smaller than the keys in all nodes in that node’s right subtree.
*/
#include <iostream>
#include <string>

using namespace std;

class BST { // TODO can there be duplicate keys?

    struct Node {
        int key;
        string value;
        Node * left;
        Node * right;
    };

    Node * root {nullptr};

    Node * find(Node * node, int key) const {
        if (node == nullptr) {
            return node;
        } else if (node->key == key) {
            return node;
        } else if(node->key < key) {
            return find(node->right, key);
        } else {
            return find(node->left, key);
        }
    }

    void insert(Node * node, Node * newNode) {
        if (node->key < newNode->key) {
            if (node->right == nullptr) {
                node->right = newNode;
            } else {
                insert(node->right, newNode);
            }
        } else {
            if (node->left == nullptr) {
                node->left = newNode;
            } else {
                insert(node->left, newNode);
            }
        }
    }

    void printInOrder(Node * node) const {
        if (node != nullptr) {
            printInOrder(node->left);
            cout << "key=" << node->key << " value=" << node->value << endl;
            printInOrder(node->right);
        }
    }

    Node * minimum(Node * node) {
        if (node == nullptr){
            return nullptr;
        }
        if(node->left == nullptr) {
            return node;
        } else {
            return minimum(node->left);
        }
    }

    Node * remove(Node * node, int key) {
        if (node == nullptr) {
            return nullptr;
        } else if (node->key > key) {
            return remove(node->left, key);
        } else if (node->key < key) {
            return remove(node->right, key);
        } else {
            // if ((node->left == nullptr) && (node->right == nullptr)) {
            //     return nullptr;
            // } else 
            if (node->left == nullptr) {
                return node->right;
            } else if (node->right == nullptr) {
                return node->left;
            } else {
                Node * m = minimum(node->right);
                m->right = deleteMin(node->right);
                m->left = node->left;
                return m;
            }
        }
    }

    Node * deleteMin(Node * node) {
        if (node->left == nullptr) {
            return node->right;
        } 
        node->left = deleteMin(node->left);
        return node;
    }

public:
    void insert(int key, string value) {
        Node * newNode = new Node{key, value, nullptr, nullptr};
        if (root == nullptr) {
            root = newNode;
        } else {
            insert(root, newNode);
        }
    }

    void remove(int key) {
        root = remove(root, key);
    }

    string find(int key) const {
        Node * node = find(root, key);
        if(node == nullptr)
            return "NOT FOUND";
        return node->value;
    }

    int size() const{
        return 0;
    }

    void printInOrder() const {
        printInOrder(root);
    }

};
