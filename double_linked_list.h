#ifndef ALGO_DOUBLE_LINKED_LIST
#define ALGO_DOUBLE_LINKED_LIST

#include <iostream>
#include <exception> 
#include "stddef.h"

using namespace std;

class DoubleLinkedList {
    struct Node {
        int val;
        Node * prev;
        Node * next;
    };

    private:
        Node * head {nullptr};
        size_t size {0}; // TODO follow naming conventions    

    public:
        size_t getSize() const { // TODO why name clash?
            return size;
        }

        void pushBack(int val) {
            insertAt(size, val);
        }

        void deleteAt(int index) {
            cout << "Deleting value at " << index << endl;
            if (index < 0 || index > size) {
                throw invalid_argument("Invalid index");
            }

            if (index == 0) { // deleting head
                if (head == nullptr) {
                    throw invalid_argument("Cannot delete items from an empty list");
                } else {
                    Node * tmp  = head;
                    head = head->next;
                    delete tmp;
                }
            } else {
                Node * node = head;
                for (size_t i = 0; i < index; ++i) {
                    node = node->next;
                }

                Node * next = node->next;
                node->prev->next=next;
                if (next != nullptr) {
                    next->prev = node->prev;
                }
                delete node;
            }

        }

        void insertAt(int index, int val) {
            cout << "Inserting " << val << " at " << index << endl;
            if (index < 0 || index > size) {
                throw invalid_argument("Invalid index");
            }
            Node * newNode = new Node{val, nullptr, nullptr};
            if (index == 0) {
                if (head == nullptr) {
                    head = newNode;
                } else {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
            } else {
                Node * node = head;
                for (size_t i = 1; i < index; ++i) {
                    node = node->next;
                }

                Node * next = node->next;
                node->next = newNode;
                newNode->prev = node;
                newNode->next = next;
                if (next != nullptr) { // if not tail
                    next->prev = newNode;
                }
            }
            ++size;

        }

        void print() {
            Node * node = head;
            while (node != nullptr) {
                cout << node->val << " ";
                node = node->next;
            }
            if (head != nullptr) {
                cout << endl;
            }
        }

        // TODO custom destructor to not leak memory
};

#endif