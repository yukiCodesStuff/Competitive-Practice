#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, l; cin >> n >> m >> l;
        vector<vector<int>> adj(n, vector<int>());
        vector<int> visited(n, 0);

        // make graph
        for (int i = 0; i < m; ++i) {
            int x, y; cin >> x >> y; x--; y--;
            adj[x].push_back(y);
        }

        queue<int> q;
        for (int i = 0; i < l; ++i) {
            int z; cin >> z; z--;
            q.push(z);
        }

        int dominoes = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (visited[curr]) continue;
            visited[curr] = 1;
            for (auto nei : adj[curr]) {
                if (!visited[nei]) {
                    q.push(nei);
                }
            }
            dominoes++;
        }

        cout << dominoes << endl;
    }
    return 0;
}