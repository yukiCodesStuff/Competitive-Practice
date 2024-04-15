#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n, l, q; cin >> n >> l >> q;
    unordered_map<string, string> trans;
    for (int i = 0; i < n; ++i) {
        string engWord, throwAway, spanWord;
        cin >> engWord >> throwAway >> spanWord;
        trans[engWord] = spanWord;
    }

    vector<string> sentenceStruct(l);
    for (int i = 0; i < l; ++i) {
        cin >> sentenceStruct[i];
    }

    while (q--) {
        vector<string> sent(l);
        for (int i = 0; i < l; ++i) {
            cin >> sent[i];
        }

        bool yes = true;
        for (int i = 0; i < l; ++i) {
            if (trans.find(sent[i]) != trans.end()) {
                if (trans[sent[i]] != sentenceStruct[i]) {
                    yes = false;
                    break;
                }
            } else if (sentenceStruct[i] != "???") {
                yes = false;
                break;
            }
        }

        if (yes) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}