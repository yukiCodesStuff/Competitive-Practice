#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<pair<int, int>> dirs = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

int main() {
    long long n, xStart, yStart; cin >> xStart >> yStart;
    vector<pair<int, int>> goons;
    int maxX = 0;
    int maxY = 0;
    while (n--) {
        int x, y; cin >> x >> y;
        x--; y--;
        maxX = max(maxX, x);
        maxY = max(maxY, y);
        goons.push_back(make_pair(x, y));
    }

    cout << maxX << " " << maxY << endl;

    vector<vector<int>> grid(maxY, vector<int>(maxX, 0));
    vector<vector<int>> visited(maxY, vector<int>(maxX, 0));
    for (auto g : goons) {
        grid[g.first][g.second] = 1;
    }

    queue<pair<int, int>> q;
    q.push(make_pair(xStart, yStart));
    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        if (visited[curr.first][curr.second]) continue;
        if (
            curr.first == 0 || curr.first == maxX - 1 || 
            curr.second == 0 || curr.second == maxY - 1
        ) {
            cout << "NOT CONTAINED" << endl;
            return 0;
        }
        visited[curr.first][curr.second] = 1;
        for (auto d : dirs) {
            int dx = curr.first + d.first;
            int dy = curr.second + d.second;
            if (
                dx >= 0 && dx < maxX && dy >= 0 && dy < maxY && 
                grid[dx][dy] == 0
            ) {
                q.push(make_pair(dx, dy));
            }
        }
    }

    cout << "CONTAINED" << endl;
    return 0;
}