#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll, > edge;
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
        ll mf = 0; // mf stands for max_flow
        while (BFS(s, t)) { // an O(V*E^2) algorithm
            ll f = send_one_flow(s, t); // find and send 1 flow f
            if (f == 0) break; // if f == 0, stop
            mf += f; // if f > 0, add to mf
        }
        return mf;
    }

    ll dinic(int s, int t) {
        ll mf = 0; // mf stands for max_flow
        while (BFS(s, t)) { // an O(V^2*E) algorithm
            last.assign(V, 0); // important speedup
            while (ll f = DFS(s, t)) // exhaust blocking flow
            mf += f;
        }
        return mf;
    }
};

int main() {
    
    int V = 5; // Number of vertices in the graph
    MaxFlow maxFlow(V);

    maxFlow.add_edge(0, 1, 10); // Adding edge 0->1 with capacity 10
    maxFlow.add_edge(0, 2, 5);  // Adding edge 0->2 with capacity 5
    maxFlow.add_edge(1, 2, 15); // Adding edge 1->2 with capacity 15
    maxFlow.add_edge(1, 3, 10); // Adding edge 1->3 with capacity 10
    maxFlow.add_edge(2, 4, 10); // Adding edge 2->4 with capacity 10
    maxFlow.add_edge(3, 2, 2);  // Adding edge 3->2 with capacity 2
    maxFlow.add_edge(3, 4, 10); // Adding edge 3->4 with capacity 10

    int s = 0; // Source vertex
    int t = 4; // Sink vertex
    double maxFlowValue = maxFlow.edmonds_karp(s, t);
    cout << "The maximum flow from source to sink is: " << maxFlowValue << endl;

    return 0;
}
