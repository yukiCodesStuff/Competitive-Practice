#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int l, n; cin >> l >> n;
        int minPos = 0, maxPos = 0;
        vector<int> dists(n);
        for (int i = 0; i < n; ++i) {
            int ant; cin >> ant;

            int closerEdge = min(ant, l - ant);
            int furtherEdge = max(ant, l - ant);

            maxPos = max(maxPos, furtherEdge);
            minPos = max(minPos, closerEdge);
        }

        cout << minPos << " " << maxPos << endl;
    }
    return 0;
}