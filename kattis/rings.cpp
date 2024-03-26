#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <set>

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

    vector<vector<int>> ring(m + 2, vector<int>(n + 2, 0));
    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (
                // grid[i][j] == '.' && (
                //     grid[i][j - 1] == 'T' ||
                //     grid[i][j + 1] == 'T' ||
                //     grid[i - 1][j] == 'T' ||
                //     grid[i + 1][j] == 'T' 
                // )
                grid[i][j] == 'T' && (
                    grid[i][j - 1] == '.' ||
                    grid[i][j + 1] == '.' ||
                    grid[i - 1][j] == '.' ||
                    grid[i + 1][j] == '.' 
                )
            ) {
                // do BFS
                queue<pii> q;
                set<pii> visited;
                q.push({i, j});
                int currLevel = 1;
                while (!q.empty()) {
                    queue<pii> level = q;
                    q = {};
                    while (!level.empty()) {
                        // cout << currLevel << endl;
                        pii coord = level.front();
                        int x = coord.first;
                        int y = coord.second;
                        level.pop();
                        for (pii d : dirs) {
                            int dx = d.first;
                            int dy = d.second;
                            // cout << "(" << x + dx << ", " << y + dy << ") ";
                            if (
                                grid[x + dx][y + dy] == 'T' && visited.find({x + dx, y + dy}) == visited.end()
                            ) {
                                q.push({x + dx, y + dy});
                                // grid[x + dx][y + dy] = 'M';
                                // ring[x + dx][y + dy] = currLevel;
                                if (ring[x + dx][y + dy] == 0) ring[x + dx][y + dy] = currLevel;
                                else ring[x + dx][y + dy] = min(currLevel, ring[x + dx][y + dy]);
                                visited.insert({x + dx, y + dy});
                            }
                        }
                        // cout << endl;
                    }

                    currLevel++;

                    // pii coord = q.front();
                    // int x = coord.first;
                    // int y = coord.second;
                    // q.pop();
                    // for (pii d : dirs) {
                    //     int dx = d.first;
                    //     int dy = d.second;
                    //     if (grid[x + dx][y + dy] == 'T') {
                    //         q.push({x + dx, y + dy});
                    //         grid[x + dx][y + dy] = 'M';
                    //     }
                    // }
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

    cout << endl;

    for (auto row : ring) {
        for (auto v : row) {
            cout << v;
        }
        cout << endl;
    }

    return 0;
}