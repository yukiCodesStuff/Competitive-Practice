#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<double, string> runner;

int main() {
    int n; cin >> n;
    vector<string> names(n);
    vector<double> firstLeg(n);
    vector<double> otherLeg(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        // double a; cin >> a; // first leg time
        // double b; cin >> b; // other leg time
        cin >> firstLeg[i];
        cin >> otherLeg[i];
    }

    double bestTime = 100;
    vector<string> winners;
    for (int i = 0; i < n; ++i) {
        double currTime = firstLeg[i];
        priority_queue<runner, vector<runner>, greater<runner>> pq;
        vector<string> winningTem = {names[i]};
        for (int j = 0; j < n; ++j) {
            if (i != j) pq.push({otherLeg[j], names[j]});
        }
        for (int j = 0; j < 3; j++) {
            currTime += pq.top().first;
            winningTem.push_back(pq.top().second);
            pq.pop();
        }

        if (currTime < bestTime) {
            bestTime = currTime;
            winners = winningTem;
        }
    }

    cout << bestTime << endl;
    for (auto w : winners) {
        cout << w << endl;
    }
    return 0;
}