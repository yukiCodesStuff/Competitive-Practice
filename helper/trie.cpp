#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct vertex {
    char alphabet;
    bool exist;
    vector<vertex*> child;
    vertex(char a): alphabet(a), exist(false) { child.assign(26, NULL); }
};

class Trie { // this is TRIE
private: // NOT Suffix Trie
    vertex* root;
public:
    Trie() { root = new vertex('!'); }

    void insert(string word) { // insert a word into trie
        vertex* cur = root;
        for (int i = 0; i < (int)word.size(); ++i) { // O(n)
            int alphaNum = word[i] - 'A';
            if (cur->child[alphaNum] == NULL) // add new branch if NULL
            cur->child[alphaNum] = new vertex(word[i]);
            cur = cur->child[alphaNum];
        }
        cur->exist = true;
    }

    bool search(string word) { // true if word in trie
        vertex* cur = root;
        for (int i = 0; i < (int)word.size(); ++i) { // O(m)
            int alphaNum = word[i]-'A';
            if (cur->child[alphaNum] == NULL) // not found
            return false;
            cur = cur->child[alphaNum];
        }
        return cur->exist; // check exist flag
    }

    bool startsWith(string prefix) { // true if match prefix
        vertex* cur = root;
        for (int i = 0; i < (int)prefix.size(); ++i) {
            int alphaNum = prefix[i]-'A';
            if (cur->child[alphaNum] == NULL) // not found
            return false;
            cur = cur->child[alphaNum];
        }
        return true; // reach here, return true
    }
};

// BE AWARE OF TEST CASE CAPITALIZATION