#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> indegrees;
vector<bool> visited;
queue<int> q;

void dfs(int i) {
    if (visited[i]) return;
    visited[i] = true;
    q.push(i);
    for (int n : adj_list[i]) {
        dfs(n);
        indegrees[n]--;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj_list.assign(n + 1, {});
    indegrees.assign(n + 1, 0);
    visited.assign(n + 1, false);

    while (m--) {
        int x, y; cin >> x >> y;
        adj_list[x].push_back(y);
        indegrees[y]++;
    }

    for (int i = 0; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    cout << endl;

    for (int n : indegrees) {
        cout << n << endl;
    }

    return 0;
}