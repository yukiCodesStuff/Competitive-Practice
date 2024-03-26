#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main() {
    int m; cin >> m;
    vi c(m);
    while (m--) {
        cin >> c[c.size() - m - 1];
    }
    
    float leftMax = 0, rightMax = 0;
    float leftRunningAvg = 0, rightRunningAvg = 0;
    int leftSum = 0, rightSum = 0;
    for (int i = 1; i <= c.size(); ++i) {
        leftSum += c[i - 1];
        leftRunningAvg = (float)leftSum / i;
        leftMax = max(leftMax, leftRunningAvg);
    }
    reverse(c.begin(), c.end());
    for (int i = 1; i <= c.size(); ++i) {
        rightSum += c[i - 1];
        rightRunningAvg = (float)rightSum / i;
        rightMax = max(rightMax, rightRunningAvg);
    }

    if (leftMax < 0 && rightMax < 0) cout << 0 << endl;
    else cout << max(leftMax, rightMax) << endl;

    return 0;
}