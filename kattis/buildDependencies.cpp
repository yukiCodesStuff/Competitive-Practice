#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <set>

using namespace std;

unordered_map<string, vector<string>> adj;
unordered_map<string, bool> visited;
stack<string> ordering;

bool dfsTopSort(string s, set<string> &seen) {
    if (seen.find(s) != seen.end()) return false; // cycle detected
    if (visited.find(s) != visited.end()) return true;
    visited[s] = true;
    seen.insert(s);
    for (string x : adj[s]) {
        if (!dfsTopSort(x, seen)) {
            return false;
        } 
    }

    seen.erase(s);
    ordering.push(s);
    return true;
}

int main() {

    int n; cin >> n;
    // unordered_map<string, vector<string>> adj; 
    n++;
    while (n--) {
        string line; getline(cin, line);
        if (line.empty()) continue;
        stringstream ss(line);
        string fname; ss >> fname;
        fname = fname.substr(0, fname.size() - 1);
        string fileToAdd;
        while (ss >> fileToAdd) {
            adj[fileToAdd].push_back(fname);
        }
    }

    string changedFile; cin >> changedFile;
    set<string> seen;
    dfsTopSort(changedFile, seen);
    while (!ordering.empty()) {
        cout << ordering.top() << endl;
        ordering.pop();
    }
    

    return 0;
}