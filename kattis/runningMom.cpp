#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool cycleDetected(unordered_map<string, vector<string>> &adj, 
    unordered_map<string, bool> &visited, string curr) {
    if (visited[curr]) return true;
    visited[curr] = true;
    for (auto nei : adj[curr]) {
        if (cycleDetected(adj, visited, nei)) return true;
    }
    visited[curr] = false;

    return false;
}

int main() {
    int n; cin >> n;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> visited;
    for (int i = 0; i < n; ++i) {
        string from, to; cin >> from >> to;
        adj[from].push_back(to);
        visited[from] = false;
        visited[to] = false;
    }

    string dest;
    while (cin >> dest) {
        bool safe = cycleDetected(adj, visited, dest);
        if (safe) {
            cout << dest << " safe" << endl;
        } else {
            cout << dest << " trapped" << endl;
        }
    }
    return 0;
}