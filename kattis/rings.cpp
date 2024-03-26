#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

vector<pii> dirs = {
    {0, -1},
    {1, -1},
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
    {-1, 0},
    {-1, -1}
};

int main() {

    // make board with boundary
    int m, n; cin >> m >> n;
    vector<vector<char>> grid(m + 2, vector<char>(n + 2, '.'));
    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            char tile; cin >> tile;
            grid[i][j] = tile;
        }
    }

    // check board
    // for (auto row : grid) {
    //     for (auto v : row) {
    //         cout << v;
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> ring(m, vector<int>(n, 0));
    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (
                grid[i][j] == '.' && (
                    grid[i][j - 1] == 'T' ||
                    grid[i][j + 1] == 'T' ||
                    grid[i - 1][j] == 'T' ||
                    grid[i + 1][j] == 'T' 
                )
            ) {
                // do BFS
                queue<pii> q;
                q.push({i, j});
                while (!q.empty()) {
                    pii coord = q.front();
                    int x = coord.first;
                    int y = coord.second;
                    q.pop();
                    for (pii d : dirs) {
                        int dx = d.first;
                        int dy = d.second;
                        if (grid[x + dx][y + dy] == 'T') {
                            q.push({x + dx, y + dy});
                            grid[x + dx][y + dy] = 'M';
                        }
                    }
                }
            }
        }
    }

    // check board
    for (auto row : grid) {
        for (auto v : row) {
            cout << v;
        }
        cout << endl;
    }

    return 0;
}