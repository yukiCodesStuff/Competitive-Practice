#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int x = 62507;
const int y = 62507;

int main() {
    int t; cin >> t;
    for (int c = 0; c < t; ++c) {
        int n, p, q; cin >> n >> p >> q;
        vector<int> prince(p + 1);
        vector<int> princess(q + 1);
        for (int i = 0; i < p + 1; ++i) cin >> prince[i];
        for (int i = 0; i < q + 1; ++i) cin >> princess[i];

        vector<vector<int>> dp(p + 1, vector<int>(q + 1, 0));
        for (int i = 1; i <= p; ++i) {
            for (int j = 1; j <= q; ++j) {
                if (prince[i] == princess[j]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        cout << "Case " << c + 1 << ": " << dp[p][q] + 1 << endl;
    }

    return 0;
}