#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

struct Node {
    int x;
    int y;
    int parent;
    Node(int x, int y, int parent) : x(x), y(y), parent(parent) {}
    void printCoord() {cout << "(" << x << ", " << y << ")";}
};

vector<int> parents;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<Node, Node> edge;

void printEdges(map<double, vector<edge>> &edges) {
    for (auto it : edges) {
        cout << it.first << ": ";
        for (auto e : it.second) {
            e.first.printCoord(); 
            cout << "->"; 
            e.second.printCoord();
            cout << " ";
        }
        cout << endl;
    }
}

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
    int n; cin >> n;
    while (n--) {
        int s, p; cin >> s >> p;
        map<double, vector<edge>> edges; // edgeWeight : {edges}
        vector<Node> nodes;
        parents.resize(p);
        int components = p;

        for (int i = 0; i < p; ++i) {
            double x, y; cin >> x >> y;
            nodes.push_back(Node(x, y, i));
            parents[i] = i;
        }

        for (int i = 0; i < nodes.size(); ++i) {
            for (int j = i + 1; j < nodes.size(); ++j) {
                double edgeWeight = sqrt(pow((nodes[i].x - nodes[j].x), 2) + pow((nodes[i].y - nodes[j].y), 2));
                edges[edgeWeight].push_back(make_pair(nodes[i], nodes[j]));
            }
        }

        bool found = false;
        for (auto it : edges) {
            for (auto e : it.second) {
                if (findParent(e.first.parent) != findParent(e.second.parent)) {
                    unionSet(e.first.parent, e.second.parent);
                    // mstEdges.push_back(it.first);
                    p--;
                }
                if (p == s) {
                    if (!found) {
                        printf("%.2f\n", it.first);
                        found = true;
                    }
                    break;
                }
            }
        }
    }
    // cout << "done" << endl;

    return 0;
}