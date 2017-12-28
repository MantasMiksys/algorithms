#include <iostream>
#include <functional>

using namespace std;

template <typename K, typename V>
struct HashNode {
    K key;
    V val;
    HashNode * next;
};

template <typename K, typename V>
class HashTable {
    constexpr static int TABLE_SIZE = 128;
    HashNode<K,V> ** table;
private:
    size_t getHash(const K & key) {
        size_t h = hash<K>{}(key);
        return h % TABLE_SIZE;
    }
public:
    HashTable() : table(new HashNode<K,V> * [TABLE_SIZE]) { }

    ~HashTable() {
        for(int i = 0; i < TABLE_SIZE; ++i) {
            if(table[i] != nullptr)
                delete table[i];
        }
        delete [] table;
    }

    void put(const K & key, const V & value) {
        size_t h = getHash(key);
        HashNode<K,V> * prev = nullptr;
        HashNode<K,V> * entry = table[h];
        while(entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }
        if(entry == nullptr) {
            entry = new HashNode<K, V>{key, value, nullptr};
            if(prev != nullptr) {
                prev->next = entry;
            } else {
                table[h] = entry;
            } 
        } else {
            entry->val = value;
        }
    }

    bool get(const K & key, V & value) {
        size_t h = getHash(key);
        HashNode<K,V> * entry = table[h];
        while(entry != nullptr && entry->key!=key) {
            if(entry->key==key) {
                value = entry->val;
                return true;
            }
            entry = entry->next;
        }
        return false;
    }

    bool remove(const K & key) {
        size_t h = getHash(key);
        HashNode<K,V> * prev = nullptr;
        HashNode<K,V> * entry = table[h];
        while(entry!=nullptr) {
            prev = entry;
            entry = entry->next;
        }
        if(entry == nullptr) {
            return false;
        } else {
            if(prev != nullptr) {
                prev->next = entry->next;
            } else {
                // remove first item of the list
                table[h] = entry->next;
            }
            cout << "Deleting entry " << entry->key << " " << entry->val << endl;
            delete entry;
        }
        return true;
    }
};

int main() {
    HashTable<string, int> ht;
    ht.put("Jim", 10);
    ht.put("Jane", 47);
    ht.put("Jack", 33);

    int value;
    bool res = ht.get("Jane", value);
    cout << "Jane->" << value << " " << res << endl;
    res = ht.get("Jack", value);
    cout << "Jack->" << value << " " << res << endl;
    res = ht.get("Alice", value);
    cout << "Alice->" << " " << res << endl;

    res = ht.remove("Jack");
    cout << "Jack removed " << res << endl;

    res = ht.get("Jack", value);
    cout << "Jack->" << res << endl;

    return 0;
}
