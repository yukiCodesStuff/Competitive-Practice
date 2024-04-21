#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> edge; // weight, a -> b

vector<int> parents;

int findParent(int i) {
    if (parents[i] == i) return i;
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
    int t; cin >> t;
    while (t--) {
        int m, c; cin >> m >> c;
        parents.assign(c, 0);
        for (int i = 0; i < c; ++i) parents[i] = i;
        int numEdges = (c * (c - 1)) / 2;
        vector<edge> edges(numEdges);
        for (int i = 0; i < numEdges; ++i) {
            int a, b, w; cin >> a >> b >> w;
            edge e = {w, {a, b}};
            edges[i] = e;
        }

        sort(edges.begin(), edges.end());
        int totCost = 0;
        for (edge e : edges) {
            int a = e.second.first;
            int b = e.second.second;
            if (findParent(a) != findParent(b)) {
                totCost += e.first;
                unionSet(a, b);
            }
        }

        // cout << "Total " << totCost << endl;

        if (totCost + c <= m) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}