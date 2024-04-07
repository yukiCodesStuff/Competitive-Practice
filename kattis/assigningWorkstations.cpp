#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        intervals.push_back(make_pair(x, y));
    }

    vector<int> computers(n,0);
    sort(intervals.begin(), intervals.end());
    int lastFree = 0;
    int unlocksSaved = 0;
    for (int i = 0; i < intervals.size(); ++i) {
        int start = intervals[i].first;
        int end = intervals[i].first + intervals[i].second;
        
        // find next available station
        int finderIndex = 0;
        while (start < computers[finderIndex]) {
            finderIndex++;
        }

        // cout << "Stopped at " << finderIndex << endl;

        if (computers[finderIndex] != 0 && start - computers[finderIndex] <= m) {
            unlocksSaved++;
        }
        computers[finderIndex] = end;
    }

    cout << unlocksSaved << endl;

    return 0;
}