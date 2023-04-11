#include <iostream>
#include <cstring>

using namespace std;

const int TABLE_SIZE = 128;

class HashNode {
public:
    int key;
    int value;
    HashNode* next;
    HashNode(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

class HashTable {
public:
    HashTable() {
        table = new HashNode*[TABLE_SIZE];
        for(int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }
    ~HashTable() {
        for(int i = 0; i < TABLE_SIZE; i++) {
            HashNode* node = table[i];
            while(node) {
                HashNode* prev = node;
                node = node->next;
                delete prev;
            }
        }
        delete[] table;
    }
    int get(int key) {
        int hashValue = hashFunction(key);
        HashNode* node = table[hashValue];
        while(node) {
            if(node->key == key) {
                return node->value;
            }
            node = node->next;
        }
        return -1; // Return -1 if key not found
    }
    void put(int key, int value) {
        int hashValue = hashFunction(key);
        HashNode* node = table[hashValue];
        while(node) {
            if(node->key == key) {
                node->value = value;
                return;
            }
            node = node->next;
        }
        node = new HashNode(key, value);
        node->next = table[hashValue];
        table[hashValue] = node;
    }
    void remove(int key) {
        int hashValue = hashFunction(key);
        HashNode* node = table[hashValue];
        HashNode* prev = NULL;
        while(node) {
            if(node->key == key) {
                if(prev) {
                    prev->next = node->next;
                } else {
                    table[hashValue] = node->next;
                }
                delete node;
                return;
            }
            prev = node;
            node = node->next;
        }
    }
private:
    HashNode** table;
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }
};

int main() {
    HashTable ht;
    ht.put(1, 10);
    ht.put(2, 20);
    cout << ht.get(1) << endl; // Output: 10
    cout << ht.get(2) << endl; // Output: 20
    ht.put(1, 100);
    cout << ht.get(1) << endl; // Output: 100
    ht.remove(1);
    cout << ht.get(1) << endl; // Output: -1 (not found)
    return 0;
}
