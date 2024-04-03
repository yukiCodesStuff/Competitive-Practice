#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int Time = 0;

void dfsBridges(
    int node, int parent, vector<int> &visited,
    vector<int> &d, vector<int> &low, vector<pair<int, int>> &bridges, vector<vector<int>> &adj
) {
    visited[node] = 1;
    d[node] = low[node] = Time;
    Time++;
    for (auto &it : adj[node]) {
        if (it == parent) continue;
        if (visited[it] == 0) { // not visited
            dfsBridges(it, node, visited, d, low, bridges, adj);
            low[node] = min(low[node], low[it]); // look through adjacent node's EXCEPT PARENT
            if (low[it] > d[node]) {
                bridges.push_back({it, node});
            }
        } else { // adjacent node already visited, see if we can update the current low
            low[node] = min(low[node], low[it]);
        }
    }
}

int main() {
    int p, c;
    while (cin >> p) {
        cin >> c;
        if (!p && !c) break;
        
        vector<vector<int>> adj(p, vector<int>{});
        while (c--) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        // cout << "Adjacency List" << endl;
        // for (auto it : adj) {
        //     for (auto p : it) {
        //         cout << p << " ";
        //     }
        //     cout << endl;
        // }

        vector<int> d(p);
        vector<int> low(p);
        vector<int> visited(p, 0); // stores nodes
        vector<pair<int, int>> bridges;
        Time = 0;
        for (int node = 0; node < p; ++node) {
            if (!visited[node]) {
                dfsBridges(node, -1, visited, d, low, bridges, adj);
            }
        }

        // for (auto it : bridges) {
        //     cout << it.first << "->" << it.second << " ";
        // }
        // cout << endl;

        if (bridges.size()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}