#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> dp(n + 1, 0);
        dp[0] = 0; dp[1] = 2; dp[2] = 3;

        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= 1000000007;
        }
        // long long res = dp[n] % 1000000007;
        cout << dp[n] << endl;
        // cout << (long long)pow(2, n) - dp[n] << endl;
    }
    return 0;
}