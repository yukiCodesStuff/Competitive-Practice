#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, int markingNum, int beingMarked) {
    if (
        row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || 
        grid[row][col] != beingMarked || grid[row][col] == markingNum
    ) {
        return;
    }

    grid[row][col] = markingNum;
    dfs(row + 1, col, grid, markingNum, beingMarked);
    dfs(row - 1, col, grid, markingNum, beingMarked);
    dfs(row, col + 1, grid, markingNum, beingMarked);
    dfs(row, col - 1, grid, markingNum, beingMarked);
}

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        string row; cin >> row;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = row[j] - '0';
        }
    }

    vector<vector<int>> binGrid = grid;

    int markingNum = 2;
    int initial = -1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] <= 1) {
                if (initial == -1) initial = grid[i][j];
                dfs(i, j, grid, markingNum, grid[i][j]);
                markingNum++;
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        if (grid[x1][y1] == grid[x2][y2]) {
            if (binGrid[x1][y1] == 0) cout << "binary" << endl;
            else cout << "decimal" << endl;
        } else {
            cout << "neither" << endl;
        }
    }

    return 0;
}