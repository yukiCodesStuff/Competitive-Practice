#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

int main() {
    long long n, m; cin >> n >> m;
    vector<pair<long long, long long>> reqs(n); // requests
    for (long long i = 0; i < n; ++i) {
        long long a, b; cin >> a >> b; // start time : end
        reqs[i] = {a, a + b};
    }

    long long saves = 0;
    sort(reqs.begin(), reqs.end());
    priority_queue<long long, vector<long long>, greater<long long>> pq; // workstations
    for (long long i = 0; i < n; ++i) {
        pair<long long, long long> currReq = reqs[i];
        if (pq.empty()) {
            pq.push(currReq.second);
            continue;
        }

        long long diff = currReq.first - pq.top();
        while (!pq.empty()) {
            if (diff < 0) {
                pq.push(currReq.second);
                break;
            } else {
                if (diff > m) {
                    pq.pop();
                    diff = currReq.first - pq.top();
                } else if (diff <= m) {
                    if (!(currReq.second < pq.top())) {
                        pq.pop();
                        pq.push(currReq.second);
                    } 
                    saves++;
                    break;
                }
            }
        }
    }

    cout << saves << endl;
    return 0;
}