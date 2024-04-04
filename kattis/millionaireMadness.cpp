#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<pair<int, int>> dirs = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<pair<int, pair<int, int>>> pq; // weight : next node's coord
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int maxDiff = 0;
    pq.push({0, {0, 0}});
    visited[0][0] = true;
    while (!pq.empty() && !visited[m - 1][n - 1]) {
        pair<int, pair<int, int>> curr = pq.top();
        visited[curr.second.first][curr.second.second] = true;
        maxDiff = max(maxDiff, -curr.first);
        pq.pop();
        // cout << curr.second.first << ", " << curr.second.second << endl;
        for (auto d : dirs) {
            int dx = d.first, dy = d.second;
            int x = curr.second.first, y = curr.second.second;
            if (
                (x + dx) >= 0 && (x + dx) < grid.size() && 
                (y + dy) >= 0 && (y + dy) < grid[0].size() && 
                !visited[x + dx][y + dy]
            ) {
                int diff = max(0, grid[x + dx][y + dy] - grid[x][y]);
                pq.push({-diff,{x + dx, y + dy}});
            }
        }
        
        // priority_queue<pair<int, pair<int, int>>>  copyPq = pq;
        // while (!copyPq.empty()) {
        //     pair<int, pair<int, int>> curr = copyPq.top();
        //     cout << "{" << -curr.first << ": (" << curr.second.first << ", " << curr.second.second << ")} ";
        //     copyPq.pop();
        // }
        // cout << endl;
    }

    cout << maxDiff << endl;

    return 0;
}