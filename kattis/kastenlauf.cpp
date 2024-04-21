#include <iostream>
#include <unordered_map>
#include <math.h>
#include <queue>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};

typedef pair<double, double> node;
typedef pair<double, node> edge;

double getDist(node a, node b) {
    double x1 = a.first, y1 = a.second;
    double x2 = b.first, y2 = b.second;
    return abs(abs(y2 - y1) + abs(x2 - x1));
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        double radius = 20 * 50;
        unordered_map<node, vector<node>, pair_hash> adj;
        unordered_map<node, bool, pair_hash> visited;
        node fin;
        node start;
        for (int i = 0; i < n + 2; ++i) {
            int a, b; cin >> a >> b;
            node pt = {a, b};
            if (i == 0) start = pt;
            if (i == n + 1) fin = pt;

            adj[pt] = {};
        }

        // make graph
        for (auto k : adj) {
            visited[k.first] = false;
            for (auto j : adj) {
                int dist = getDist(k.first, j.first);
                if (k.first != j.first && dist <= radius) {
                    adj[j.first].push_back(k.first);
                    adj[k.first].push_back(j.first);
                }
            }
        }

        queue<node> q;
        q.push(start);
        bool isSad = true;
        while (!q.empty()) {
            node currNode = q.front();
            q.pop();
            if (visited[currNode]) continue;
            visited[currNode] = true;
            if (currNode == fin) {
                isSad = false;
                cout << "happy" << endl;
                break;
            }
            for (auto nei : adj[currNode]) {
                if (!visited[nei]) {
                    q.push(nei);
                }
            }
        }

        if (isSad) cout << "sad" << endl;
    }
    return 0;
}