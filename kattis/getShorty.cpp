#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <math.h>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;

typedef pair<double, int> edge; // edge weight, to node

int main() {
    int iter = 1;
    int n, m;
    while (cin >> n >> m) {
        if (!n) break;

        // cout << "Iter " << iter++ << endl;

        vector<vector<edge>> adj(n, vector<edge>()); // intersections
        vector<int> visited(n, 0);
        for (int i = 0; i < m; ++i) { // edges
            int a, b;
            double f; 
            cin >> a >> b >> f;
            edge e1 = {f, b};
            edge e2 = {f, a};
            adj[a].push_back(e1);
            adj[b].push_back(e2);
        }

        // priority_queue<edge, vector<edge>, greater<edge>> pq; // min heap
        priority_queue<edge> pq;
        pq.push({(double)1, 0});
        double maxFactor = 0;
        while (!pq.empty()) {
            double currFactor = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            if (visited[currNode]) continue;
            visited[currNode] = 1;
            if (currNode == n - 1) {
                maxFactor = max(maxFactor, currFactor);
            }
            for (auto nei : adj[currNode]) {
                if (!visited[nei.second]) {
                    pq.push({currFactor * nei.first, nei.second});
                }
            }
        }

        cout << fixed << setprecision(4) << maxFactor << endl;
    }

    return 0;
}