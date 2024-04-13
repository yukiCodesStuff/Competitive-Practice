#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector<pair<int, int>> dirs = {
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}
};

long long dfs(int r, int c, vector<vector<char>> &grid, int pathLength) {
    // cout << r << " " << c << endl;
    if (
        r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
        grid[r][c] == '#' || grid[r][c] == 'v'
    ) {
        return 1e18;
    } else if (
        (r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1) &&
        grid[r][c] == 'D'
    ) {
        cout << "Reached the exit" << endl;
        return pathLength;
    }

    char tile = grid[r][c];
    grid[r][c] = 'v';
    if (tile == 'D') {
        return 
        min(
            min(dfs(r + 1, c, grid, pathLength), dfs(r - 1, c, grid, pathLength)),
            min(dfs(r, c + 1, grid, pathLength), dfs(r, c - 1, grid, pathLength))
        );
    }
    return 
        min(
            min(dfs(r + 1, c, grid, pathLength + 1), dfs(r - 1, c, grid, pathLength + 1)),
            min(dfs(r, c + 1, grid, pathLength + 1), dfs(r, c - 1, grid, pathLength + 1))
        );
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    int x, y; cin >> x >> y; // starting coord
    cout << dfs(x - 1, y - 1, grid, 0) << endl;

    return 0;
}