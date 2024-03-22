#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, unordered_set<string>> adj_list;
unordered_set<string> visited;
unordered_set<string> p1;
unordered_set<string> p2;

bool dfs(string s) {
    // nobody has it, still valid
    if (p1.find(s) == p1.end() && p2.find(s) == p2.end()) {
        p1.insert(s);
    }

    for (auto it : adj_list[s]) {
        if (
            p2.find(s) != p2.end() && 
            p1.find(it) == p1.end() && p2.find(it) == p2.end()
        ) {
            p1.insert(it);
            dfs(it);
        } else if (
            p1.find(s) != p1.end() &&
            p1.find(it) == p1.end() && p2.find(it) == p2.end()
        ) {
            p2.insert(it);
            dfs(it);
        } else if (
            (p1.find(s) != p1.end() && p1.find(it) != p1.end()) || 
            (p2.find(s) != p2.end() && p2.find(it) != p2.end())
        ) {
            // cout << "impossible with " << s << " " << it << endl;
            return false;
        }
    }

    return true;
}

int main() {

    // pre processing
    int n, m;
    cin >> n;
    while (n--) {
        string ingredient;
        cin >> ingredient;
        adj_list[ingredient] = {};
    }

    cin >> m;
    while (m--) {
        string x, y;
        cin >> x >> y;
        adj_list[x].insert(y);
        adj_list[y].insert(x);
    }

    // code

    for (auto it : adj_list) {
        if (!dfs(it.first)) {
            cout << "impossible" << endl;
            return 0;
        }

        // dfs(it.first);
    }

    for (auto it : p1) {
        cout << it << " ";
    }
    cout << endl;
     for (auto it : p2) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}