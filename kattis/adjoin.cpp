#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> parents;

int findFurthest(int p, int c, vector<vector<int>> &adj) {
    int furthest;
    queue<int> q;
    vector<bool> visited(c, false);
    q.push(p);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        visited[curr] = true;
        for (int nei : adj[curr]) {
            if (!visited[nei]) {
                q.push(nei);
            }
        }
        furthest = curr;
    }

    return furthest;
}

int findDiameter(int p, int c, vector<vector<int>> &adj) {
    int a = findFurthest(p, c, adj);
    int pathLength = 0;
    queue<int> q;
    vector<bool> visited(c, false);
    q.push(a);
    while (!q.empty()) {
        queue<int> newQ;
        bool pushed = false;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            for (int nei : adj[curr]) {
                if (!visited[nei]) {
                    newQ.push(nei);
                    pushed = true;
                }
            }
        }
        q = newQ;
        if (pushed) pathLength++;
    }

    return pathLength;
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
    int c, l; cin >> c >> l;
    parents.resize(c);
    for (int i = 0; i < c; ++i) {
        parents[i] = i;
    }

    // make adjacency list
    vector<vector<int>> adj(c);
    while (l--) {
        int a, b; cin >> a >> b;
        unionSet(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // find longest path;
    vector<bool> visitedParent(c, false);
    vector<int> diameters;
    for (int i = 0; i < parents.size(); ++i) {
        int p = findParent(i);
        if (!visitedParent[p]) {
            // do BFS to find longest path length
            diameters.push_back(findDiameter(p, c, adj));
            visitedParent[p] = true;
        }
    }

    sort(diameters.begin(), diameters.end());
    while(diameters.size() > 1) {
        // keep joining until done
        int wing1 = diameters.back() / 2;
        int wing2 = diameters.back() / 2;
        if(diameters.back() % 2 == 1) wing1++;
        diameters.pop_back();

        int wing3 = diameters.back() / 2;
        int wing4 = diameters.back() / 2;
        if(diameters.back() % 2 == 1) wing3++;
        diameters.pop_back();

        int op1 = wing1 + wing2;
        int op2 = wing3 + wing4;
        int op3 = wing1 + wing3 + 1;

        diameters.push_back(max({op1, op2, op3}));
    }

    cout << diameters[0] << endl;

    return 0;    
}