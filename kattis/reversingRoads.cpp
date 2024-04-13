#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

vector<unordered_set<int>> adj_list;
vector<unordered_set<int>> adj_list_t;
vector<pair<int, int>> edges;
vector<int> visited;
stack<int> visitStack;

void dfsFirstPass(int i) {
    if (visited[i] == 1) return;
    visited[i] = 1;
    for (auto nei : adj_list[i]) {
        dfsFirstPass(nei);
    }
    visitStack.push(i);
}

void dfsSecondPass(int i) {
    if (visited[i] == 2) return;
    visited[i] = 2;
    for (auto nei : adj_list_t[i]) {
        dfsSecondPass(nei);
    }
}

int kosaraju(int m) {
    visited.assign(m, 0);
    int numComponents = 0;
    for (int i = 0; i < adj_list.size(); ++i) {
        if (visited[i] != 1) {
            dfsFirstPass(i);
        }
    }

    while (!visitStack.empty()) {
        int curr = visitStack.top(); visitStack.pop();
        if (visited[curr] != 2) {
            dfsSecondPass(curr);
            numComponents++;
        }
    }

    return numComponents;
}

bool reverseRoads(int m) {
    for (int x = 0; x < m; ++x) {
        // for (int y = 0; y < m; ++y) {
        //     if (
        //         adj_list[x].find(y) == adj_list[x].end()
        //     ) {
        //         continue;
        //     }
        //     adj_list[x].erase(y);
        //     adj_list_t[y].erase(x);

        //     adj_list[y].insert(x);
        //     adj_list_t[x].insert(y);
        //     if (kosaraju(m) == 1) {
        //         cout << x << " " << y << endl;
        //         return true;
        //     }

        //     adj_list[y].erase(x);
        //     adj_list_t[x].erase(y);

        //     adj_list[x].insert(y);
        //     adj_list_t[y].insert(x);
        // }
        for (pair<int, int> e : edges) {
            int x = e.first;
            int y = e.second;
            adj_list[x].erase(y);
            adj_list_t[y].erase(x);

            adj_list[y].insert(x);
            adj_list_t[x].insert(y);
            if (kosaraju(m) == 1) {
                cout << x << " " << y << endl;
                return true;
            }

            adj_list[y].erase(x);
            adj_list_t[x].erase(y);

            adj_list[x].insert(y);
            adj_list_t[y].insert(x);
        }
    }
    return false;
}

int main() {
    int m, caseNo = 1;
    while (cin >> m) {
        adj_list.clear(); adj_list_t.clear();
        adj_list.resize(m); adj_list_t.resize(m);
        
        int n; cin >> n;
        edges.clear(); edges.resize(n);
        for (int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            adj_list[x].insert(y);
            adj_list_t[y].insert(x);
            edges.push_back({x, y});
        }

        cout << "Case " << caseNo++ << ": ";
        if (kosaraju(m) == 1) {
            cout << "valid" << endl;
        } else if (!reverseRoads(m)) cout << "invalid" << endl;
    }

    return 0;
}