#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <tuple>

using namespace std;

typedef double ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;

struct Point2D {
    double x;
    double y;
    Point2D() : x(0), y(0) {}
    Point2D(double x, double y) : x(x), y(y) {}
};

class MaxFlow
{
private:
    int V;
    vector<edge> EL; // Edge List
    vector<vi> AL; // Adjacency List
    vi d, last;
    vector<ii> p;

    bool BFS(int s, int t) { // searches for augmenting path
        // cout << "Going from " << s << " to " << t << endl;
        d.assign(V, -1); d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1}); // record BFS sp tree
        while (!q.empty()) {
            int u = q.front(); q.pop();
            // cout << "Currently at " << u << endl;
            if (u == t) break; // stop as sink t reached
            for (auto &idx : AL[u]) { // explore neighbors of u
                // cout << "Exploring neighbor " << idx << endl;
                auto &[v, cap, flow] = EL[idx]; // stored in EL[idx]
                if ((cap-flow > 0) && (d[v] == -1)) // positive residual edge
                d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
            }
        }
        // cout << "Ending d[t] value " << d[t] << endl;
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
    
    int edmonds_karp(int s, int t) {
        ll mf = 0; // mf stands for max_flow
        while (BFS(s, t)) { // an O(V*E^2) algorithm
            // cout << "Came out true" << endl;
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

double getDist(Point2D p1, Point2D p2) {
    double dist = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return dist;
}

int main() {
    int n, m, s, v; 
    while (cin >> n) {
        cin >> m >> s >> v;
        double radius = (s * v); // gophers can reach within this radius

        MaxFlow maxFlow(n + m + 2); // nodes for both the gophers and the holes
        vector<Point2D> nodes(n + m + 2); // represents gophers and holes; last 2 are source and sink
        Point2D source(0, 0);
        Point2D sink(0, 0);
        nodes[n + m] = source;
        nodes[n + m + 1] = sink;
        
        // PAY ATTENTION TO DIRECTIONS

        // first n represent gophers
        for (int i = 0; i < n; ++i) {
            double x, y; cin >> x >> y;
            Point2D pt(x, y);
            nodes[i] = pt;
            maxFlow.add_edge(n + m, i, 1);
            // cout << "Adding source to " << i << endl;
        }

        // last m represent holes
        for (int i = 0; i < m; ++i) {
            double x, y; cin >> x >> y;
            Point2D pt(x, y);
            nodes[n + i] = pt;
            maxFlow.add_edge(n + i, n + m + 1, 1);
            // cout << "Adding " << n + i << " to sink" << endl;
        }

        // create bipartite graph
        for (int i = 0; i < n; ++i) {
            Point2D currGopher = nodes[i];
            for (int j = 0; j < m; ++j) {
                Point2D currHole = nodes[n + j];
                double dist = getDist(currGopher, currHole);
                if (dist <= radius) {
                    // cout << "Adding edge " << i << "->" << n + j << endl;
                    maxFlow.add_edge(i, n + j, 1); // each hole has a max capacity 1
                }
            }
        }

        int gophersSaved = maxFlow.edmonds_karp(n + m, n + m + 1);
        cout << (n - gophersSaved) << endl;
    }

    return 0;
}