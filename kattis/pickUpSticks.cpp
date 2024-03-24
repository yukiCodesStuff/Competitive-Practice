#include <iostream>
#include <unordered_set>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
queue<int> ordering;

bool dfs(int s, unordered_set<int> &seen) {
    if (seen.find(s) != seen.end()) return false; // cycle detected
    if (visited[s]) return true;
    visited[s] = true;
    seen.insert(s);
    for (int x : adj_list[s]) {
        if (!dfs(x, seen)) {
            return false;
        } 
    }

    seen.erase(s);
    ordering.push(s);
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    adj_list.resize(n + 1);
    visited.assign(n + 1, false);
    while (m--) {
        int a, b; cin >> a >> b;
        adj_list[b].push_back(a);
    }

    // explore nodes 1 to n
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            // dfs(i);
            unordered_set<int> seen = {};
            if (!dfs(i, seen)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    while (!ordering.empty()) {
        cout << ordering.front() << endl;
        ordering.pop();
    }

    return 0;
}