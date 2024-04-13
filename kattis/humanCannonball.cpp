#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <math.h>
#include <queue>

using namespace std;

typedef pair<double, double> node;
typedef pair<double, node> edge; // edge weight, to node

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};

// unordered_map<node, vector<edge>, pair_hash> adj;
unordered_map<node, vector<node>, pair_hash> adj;
unordered_map<node, bool, pair_hash> visited;
// unordered_map<node, double> min_time;

double getTime(node n1, node n2, bool walking = false) {
    double x1 = n1.first, y1 = n1.second;
    double x2 = n2.first, y2 = n2.second;
    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    if (walking) {
        return dist / 5;
    }

    if (dist > 50) {
        double distAfterLaunch = dist - 50;
        double calcTime = 2 + distAfterLaunch / 5; // running at a rate of 5m/s
        return calcTime;
    } else if (dist < 50) {
        double walkTime = dist / 5;
        double launchTime = (50 - dist) / 5;
        return min(walkTime, launchTime + 2);
    }

    return 2;
}

// double getDist(node x, node y) {
//     return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
// }

int main() {
    double x1, y1; cin >> x1 >> y1;
    node start = {x1, y1};
    double x2, y2; cin >> x2 >> y2;
    node end = {x2, y2};
    // adj[start].push_back({getTime(start, end), end});
    // adj[end].push_back({getTime(start, end), start});
    adj[start].push_back(end);
    adj[end].push_back(start);
    visited[start] = false;
    visited[end] = false;

    
    int n; cin >> n;
    vector<node> nodes(n);
    for (int i = 0; i < n; ++i) {
        double x, y; cin >> x >> y;
        node cannon = {x, y};
        nodes[i] = cannon;
        visited[cannon] = false;
        adj[start].push_back(cannon);
        adj[cannon].push_back(end);
        // for (auto n : adj) {
        // //     if (n.first == start) {
        // //         adj[cannon].push_back(n.first);
        // //         adj[n.first].push_back({getTime(n.first, cannon, true), cannon});
        // //     } else {
        // //         adj[cannon].push_back({getTime(n.first, cannon), n.first});
        // //         adj[n.first].push_back({getTime(n.first, cannon), cannon});
        // //     }
        //     adj[cannon].push_back(n.first);
        //     adj[n.first].push_back(cannon);
        // }
    }

    // make complete graph
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            node n1 = nodes[i];
            node n2 = nodes[j];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
    }

    // priority_queue<edge, vector<edge>, greater<edge>> pq; // min heap
    priority_queue<pair<double, node>, vector<pair<double, node>>, greater<pair<double, node>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        double currTime = pq.top().first;
        node currNode = pq.top().second; 
        pq.pop();
        if (visited[currNode]) continue;
        // cout << "Node: ";
        // cout << currNode.first << " " << currNode.second << " Curr Time: " << currTime << endl;
        visited[currNode] = true;
        if (currNode == end) {
            cout << currTime << endl;
            return 0;
        }
        for (auto nei : adj[currNode]) {
            if (!visited[nei]) {
                if (currNode == start) {
                    pq.push({getTime(currNode, nei, true) + currTime, nei});
                } else {
                    pq.push({getTime(currNode, nei) + currTime, nei});
                    // cout << currNode.first << "," << currNode.second << "->" << nei.first << "," << nei.second << " " << getTime(currNode, nei) << endl;
                    // visited[nei.second] = true;
                }
            }
        }
    }

    return 0;
}