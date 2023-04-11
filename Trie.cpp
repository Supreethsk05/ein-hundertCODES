#include <iostream>
#include <cstring>

using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }
private:
    TrieNode* root;
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    cout << trie.search("hello") << endl; // Output: 1 (true)
    cout << trie.search("world") << endl; // Output: 1 (true)
    cout << trie.search("hi") << endl; // Output: 0 (false)
    return 0;
}
