#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m; cin >> m;
    vector<double> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    
    double leftMax = 0, rightMax = 0;
    double leftSum = 0, rightSum = 0;
    for (int i = 0; i < c.size(); ++i) {
        leftSum += c[i];
        leftMax = max(leftMax, leftSum / (i + 1));
    }
    reverse(c.begin(), c.end());
    for (int i = 0; i < c.size(); ++i) {
        rightSum += c[i];
        rightMax = max(rightMax, rightSum / (i + 1));
    }

    // if (leftMax < 0 && rightMax < 0) cout << 0 << endl;
    // else cout << max(leftMax, rightMax) << endl;

    cout << max(leftMax, rightMax) << endl;

    return 0;
}