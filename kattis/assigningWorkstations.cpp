#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> reqs(n); // requests
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b; // start time : duration
        reqs[i] = {a, a + b};
    }

    int saves = 0;
    sort(reqs.begin(), reqs.end());
    priority_queue<int, vector<int>, greater<int>> pq; // workstations
    for (int i = 0; i < n; ++i) {
        pair<int, int> currReq = reqs[i];
        if (pq.empty()) {
            pq.push(currReq.second);
            continue;
        }
        int closestEndTime = pq.top();
        if (currReq.first >= closestEndTime) {
            // cout << "Saved with start time " << currReq.first << endl;
            
            // REMOVE AFTER EXPIRING
            
            pq.pop();
            saves++;
        }

        pq.push(currReq.second);
    }

    cout << saves << endl;
    return 0;
}