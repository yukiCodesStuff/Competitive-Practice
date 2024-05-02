#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> adj;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        adj.assign(n + 1, vector<pii>());
        int m; cin >> m;

        // make adjacency lists
        for (int i = 0; i < m; ++i) {
            int a, b, w; cin >> a >> b >> w;
            adj[a].push_back({w, b});
            adj[b].push_back({w, a});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        long long minPath = 0;
        int numPaths = 0;
        vector<bool> vis(n+1);
        pq.push({0, 1});
        while (!pq.empty()) {
            int currNode = pq.top().second;
            int pathWeight = pq.top().first;
            pq.pop();
            if (vis[currNode]) continue;
            vis[currNode] = 1;
            if (currNode == 2) {
                // cout << pathWeight << endl;
                break;
            }
            for (auto nei : adj[currNode]) {
                if (!vis[nei.second]) pq.push({nei.first + pathWeight, nei.second});
            }
            vis[currNode] = 0;
        }

        queue<pii> q;
        vis.assign(n+1, false);
        q.push({0, 2});
        while (!q.empty()) {
            int currNode = q.front().second;
            int pathWeight = q.front().first;
            q.pop();
            if (pathWeight > minPath) break;
            if (vis[currNode]) continue;
            vis[currNode] = 1;
            if (currNode == 1) {
                numPaths++;
            }
            for (auto nei : adj[currNode]) {
                if (!vis[nei.second]) q.push({nei.first + pathWeight, nei.second});
            }
            vis[currNode] = 0;
        }

        cout << numPaths << endl;
    }
    return 0;
}