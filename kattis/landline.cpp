#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> parents;

int findParent(int i) {
    if (parents[i] == i) {
        return i;
    }
    parents[i] = findParent(parents[i]);
    return parents[i];
}

void unionSet(int a, int b) {
    int x = findParent(a);
    int y = findParent(b);
    if (x == y) return;
    parents[x] = y;
}

int main() {
    int n, m, p; cin >> n >> m >> p;
    vector<int> bad(n + 1, 0);
    for (int i = 0; i < p; ++i) {
        int h; cin >> h;
        bad[h] = 1;
    }

    vector<vector<pair<int, int>>> goodEdge(n + 1);
    vector<pair<int, pair<int, int>>> badEdge(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y, w; cin >> x >> y >> w;
        // if (bad[x] && bad[y]) continue; // connecting bads are not good
        if (bad[x] || bad[y]) {
            // badEdge[x].push_back({-w, y});
            // badEdge[y].push_back({-w, x});
            badEdge.push_back({w, {x, y}});
        } else {
            goodEdge[x].push_back({-w, y});
            goodEdge[y].push_back({-w, x});
        }
    }

    parents.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        parents[i] = i;
    }

    vector<bool> inMST(n + 1, false);
    int totalWeight = 0;
    // priority_queue<pair<int, int>> pq;
    for (int i = 1; i < n + 1; ++i) {
        if (!bad[i] && !inMST[i]) {
            // cout << "Found good node " << i << endl;
            priority_queue<pair<int, int>> pq;
            pq.push({0, i});
            while (!pq.empty()) {
                int weight = pq.top().first;
                int node = pq.top().second;

                // cout << "Currently on " << node << endl;

                pq.pop();
                if (inMST[node]) continue;
                inMST[node] = true;
                totalWeight -= weight;
                for (auto it : goodEdge[node]) {
                    pq.push(it);
                    unionSet(node, it.second);
                }
            }
        }
    }

    sort(badEdge.begin(), badEdge.end());
    for (auto it : badEdge) {
        int weight = it.first;
        int x = it.second.first;
        int y = it.second.second;
        if (!inMST[x]) {
            inMST[x] = true;
            unionSet(x, y);
            totalWeight += weight;
        } else if (!inMST[y]) {
            inMST[y] = true;
            unionSet(x, y);
            totalWeight += weight;
        }
    }

    for (int i = 2; i < n + 1; ++i) {
        if (findParent(i - 1) != findParent(i)) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << totalWeight << endl;

    return 0;
}