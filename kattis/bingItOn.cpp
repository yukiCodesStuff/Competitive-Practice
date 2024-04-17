#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct vertex {
    char alphabet;
    bool exist;
    vector<vertex*> child;
    int count;
    vertex(char a): alphabet(a), exist(false) { 
        child.assign(26, NULL);
        this->count = 0;
    }
};

class Trie { // this is TRIE
private: // NOT Suffix Trie
    vertex* root;
public:
    Trie() { root = new vertex('!'); }

    void insert(string word) { // insert a word into trie
        vertex* cur = root;
        for (int i = 0; i < (int)word.size(); ++i) { // O(n)
            int alphaNum = word[i] - 'a';
            if (cur->child[alphaNum] == NULL) // add new branch if NULL
            cur->child[alphaNum] = new vertex(word[i]);
            cur = cur->child[alphaNum];
            cur->count++;
        }
        cur->exist = true;
    }

    bool search(string word) { // true if word in trie
        vertex* cur = root;
        for (int i = 0; i < (int)word.size(); ++i) { // O(m)
            int alphaNum = word[i]-'a';
            if (cur->child[alphaNum] == NULL) {
                cout << 0 << endl;
                return false;
            }
            cur = cur->child[alphaNum];
        }
        cout << cur->count << endl;
        return cur->exist; // check exist flag
    }

    bool startsWith(string prefix) { // true if match prefix
        vertex* cur = root;
        for (int i = 0; i < (int)prefix.size(); ++i) {
            int alphaNum = prefix[i]-'a';
            if (cur->child[alphaNum] == NULL) // not found
            return false;
            cur = cur->child[alphaNum];
        }
        return true; // reach here, return true
    }
};

int main() {
    int n; cin >> n;
    Trie trie;
    while (n--) {
        string word; cin >> word;
        // cout << word << endl;
        trie.search(word);
        trie.insert(word);
    }
    return 0;
}