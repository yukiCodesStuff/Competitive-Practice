#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;

set<vector<int>> visited;
int markingNum = 1;
vvi res;

void dfs(int row, int col, vvc &board) {
    // cout << row << " " << col << endl;
    if (
        visited.find({row, col}) != visited.end() ||
        row < 0 || row >= board.size() ||
        col < 0 || col >= board[0].size() ||
        board[row][col] == '.'
    ) return;
    if (
        (
            // if on the outer edge
            row - 1 < 0 || row + 1 >= board.size() ||
            col - 1 < 0 || col + 1 >= board[0].size()
        ) 
        ||
        (
            // if touching a '.'
            (
                row - 1 >= 0 && row + 1 < board.size() &&
                col - 1 >= 0 && col + 1 < board[0].size()
            ) &&
            board[row + 1][col] == '.' ||
            board[row - 1][col] == '.' ||
            board[row][col + 1] == '.' ||
            board[row][col - 1] == '.' || 
            board[row + 1][col] == markingNum - 1 + '0' ||
            board[row - 1][col] == markingNum - 1 + '0' ||
            board[row][col + 1] == markingNum - 1 + '0' ||
            board[row][col - 1] == markingNum - 1 + '0'
        ) 
    ) {
        // board[row][col] = 'M';
        board[row][col] = markingNum + '0';
        res[row][col] = markingNum;
        visited.insert({row, col});

        // diagonals
        dfs(row + 1, col + 1, board);
        dfs(row - 1, col + 1, board);
        dfs(row + 1, col - 1, board);
        dfs(row - 1, col - 1, board);

        // laterals
        dfs(row + 1, col, board);
        dfs(row - 1, col, board);
        dfs(row, col + 1, board);
        dfs(row, col - 1, board);
    }
}

int main() {

    int m, n;
    cin >> m >> n;

    vvc grid(m, vector<char>(n));
    res.assign(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'T') {
                // cout << "called at " << i << ", " << j << endl;
                dfs(i, j, grid);
                // cout << endl;
                // for (auto row : grid) {
                //     for (auto v : row) {
                //         cout << v;
                //     }
                //     cout << endl;
                // }
                markingNum++;
            }
        }
    }

    if (markingNum < 10) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!res[i][j]) cout << "..";
                else cout << "." << res[i][j];
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!res[i][j]) cout << "..";
                else if (res[i][j] < 10) cout << ".." << res[i][j];
                else cout << "." << res[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}