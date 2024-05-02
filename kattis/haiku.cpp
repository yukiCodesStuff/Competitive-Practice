#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int s; cin >> s;
    unordered_set<string> syllables;
    while (s--) {
        string syl; cin >> syl;
        syllables.insert(syl);
    }

    int sylls = 0;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string word;
        int currSylls = 0;
        while (ss >> word) {
            int start = 0, len = 1;
            string sub = word.substr(start, len);
            int turns = 0;
            while (start + len - 1 < word.size()) {
                // cout << sub << endl;
                if (syllables.find(sub) == syllables.end()) len++;
                else {
                    // cout << "Found " << sub << endl;
                    sylls++;
                    currSylls++;
                    start = start + len;
                    len = 0;
                }
                sub = word.substr(start, len);
            }
        }
        cout << "Line: " << currSylls << endl;
    }
    return 0;
}