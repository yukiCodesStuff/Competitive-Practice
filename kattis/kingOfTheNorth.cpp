#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;

class MaxFlow
{
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<ii> p;

    bool BFS(int s, int t) { // searches for augmenting path
        d.assign(V, -1); d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1}); // record BFS sp tree
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break; // stop as sink t reached
            for (auto &idx : AL[u]) { // explore neighbors of u
                auto &[v, cap, flow] = EL[idx]; // stored in EL[idx]
                if ((cap-flow > 0) && (d[v] == -1)) // positive residual edge
                d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
            }
        }
        return d[t] != -1; // has an augmenting path
    }

    ll send_one_flow(int s, int t, ll f = INF) { // send one flow from s->t
        if (s == t) return f; // bottleneck edge f found
        auto &[u, idx] = p[t];
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap-flow));
        flow += pushed;
        auto &rflow = get<2>(EL[idx^1]); // back edge
        rflow -= pushed; // back flow
        return pushed;
    }

    ll DFS(int u, int t, ll f = INF) { // traverse from s->t
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u]+1) continue; // not part of layer graph
            if (ll pushed = DFS(v, t, min(f, cap-flow))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i]^1]); // back edge
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
public:
    MaxFlow(int initialV) : V(initialV) {
        EL.clear();
        AL.assign(V, vi());
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return; // safeguard: no self loop
        EL.emplace_back(v, w, 0); // u->v, cap w, flow 0
        AL[u].push_back(EL.size()-1); // remember this index
        EL.emplace_back(u, directed ? 0 : w, 0); // back edge
        AL[v].push_back(EL.size()-1); // remember this index
    }

    ll edmonds_karp(int s, int t) {
        ll flow = 0; // flow stands for max_flow
        while (BFS(s, t)) { // an O(V*E^2) algorithm
            ll f = send_one_flow(s, t); // find and send 1 flow f
            if (f == 0) break; // if f == 0, stop
            flow += f; // if f > 0, add to flow
        }
        return flow;
    }

    ll dinic(int s, int t) {
        ll flow = 0; // flow stands for max_flow
        while (BFS(s, t)) { // an O(V^2*E) algorithm
            last.assign(V, 0); // important speedup
            while (ll f = DFS(s, t)) // exhaust blocking flow
            flow += f;
        }
        return flow;
    }
};

void printGrid(vector<vector<int>> &grid) {
    cout << endl;
    for (auto r : grid) {
        for (auto el : r) {
            cout << el << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<pair<int, int>> dirs = {
    {1,0}, {0,1}, {-1,0}, {0,-1}
};

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, -1));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int x, y; cin >> x >> y;

    // each node will be represented with 2 nodes: input node and output node
    // first half of the nodes will rep input, second half output
    MaxFlow flow(2 * n * m + 1); // only need one because source is a node
    int source = 2 * m * n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int node = i * n + j;
            if ( // border
                i == 0 || i == m - 1 || j == 0 || j == n - 1
            ) {
                flow.add_edge(source, node, INF);
            }
            flow.add_edge(node, m * n + node, grid[i][j]);
            for (auto &d : dirs) {
                int dx = i + d.first; int dy = j + d.second;
                if (
                    dx >= 0 && dx < m && dy >= 0 && dy < n
                ) {
                    int nei = dx * n + dy;
                    flow.add_edge(m * n + node, nei, INF);
                }
            }
        }
    }

    // cout << "Finished adding edges" << endl;

    int sink = (m * n) + (x * n + y);
    cout << flow.dinic(source, sink) << endl;

    return 0;
}
