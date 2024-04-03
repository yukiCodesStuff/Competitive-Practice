#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <queue>

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
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>{});
    while (m--) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> d(n);
    vector<int> low(n);
    vector<int> visited(n, 0); // stores nodes
    vector<pair<int, int>> bridges;
    Time = 0;
    dfsBridges(0, -1, visited, d, low, bridges, adj); // we only care about bridges reachable from entrance

    unordered_map<int, unordered_set<int>> cantCross;
    for (auto it : bridges) {
        cantCross[it.first].insert(it.second);
        cantCross[it.second].insert(it.first);
    }

    queue<int> q;
    q.push(0);
    unordered_set<int> v = {0};
    int count = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int nei : adj[curr]) {
            if (
                v.find(nei) == v.end() &&
                (
                    cantCross.find(nei) == cantCross.end() ||
                    cantCross[nei].find(curr) == cantCross[nei].end()
                )
            ) {
                v.insert(nei);
                q.push(nei);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}