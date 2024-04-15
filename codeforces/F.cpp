#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

typedef pair<double, double> pdd;

// struct pair_hash {
//     template <class T1, class T2>
//     size_t operator () (const pair<T1,T2> &pair) const {
//         auto hash1 = hash<T1>{}(pair.first);
//         auto hash2 = hash<T2>{}(pair.second);
//         return hash1 ^ hash2; // Combine the two hash values
//     }
// };

vector<pair<int, int>> dirs = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1},
    {1, 1}, {-1, -1}, {-1, 1}, {1, -1}   
};

int main() {
    string line; cin >> line;
    vector<int> tIndexes;
    vector<pair<int, int>> goodDims;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == 'T') tIndexes.push_back(i);
    }

    for (int i = 1; i < line.size() + 1; ++i) {
        double quotient = (double)line.size() / i;
        if (floor(quotient) == quotient) {
            int width = quotient, height = i;
            // set<pair<int, int>> badCoords;
            vector<vector<int>> grid(height, vector<int>(width, 0));
            for (auto t : tIndexes) {
                int y = t % width;
                int x = t / width;
                pair<int, int> c = {x, y};
                for (auto d : dirs) {
                    // badCoords.insert({c.first + d.first, c.second + d.second});
                    int dx = c.first + d.first, dy = c.second + d.second;
                    if (
                        dx >= 0 && dx < height && dy >= 0 && dy < width
                    ) {
                        grid[dx][dy] = 1;
                    }
                }
            }

            bool goodCoord = true;
            for (auto t : tIndexes) {
                int y = t % width;
                int x = t / width;
                pair<int, int> c = {x, y};
                // if (badCoords.find(c) != badCoords.end()) {
                //     goodCoord = false;
                //     break;
                // }
                if (grid[x][y] == 1) {
                    goodCoord = false;
                    break;
                }
            }
            if (goodCoord) goodDims.push_back({height, width});
        }
    }

    cout << goodDims.size() << endl;
    for (auto it : goodDims) {
        cout << it.first << "x" << it.second << endl;
    }

    return 0;
}