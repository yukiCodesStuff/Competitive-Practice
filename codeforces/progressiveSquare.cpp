#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, c, d; cin >> n >> c >> d;
        unordered_map<long long, int> numCt;
        long long currMin = 1e18;
        for (int i = 0; i < n * n; ++i) {
            long long num; cin >> num;
            numCt[num]++;
            currMin = min(currMin, num);
        }

        vector<vector<long long>> matrix(n, vector<long long>(n));
        matrix[0][0] = currMin;
        for (int i = 0; i < n; ++i) {
            if (i > 0) matrix[i][0] = matrix[i - 1][0] + c;
            for (int j = 1; j < n; ++j) {
                matrix[i][j] = matrix[i][j - 1] + d;
            }
        }

        // cout << endl;
        // for (auto r : matrix) {
        //     for (auto i : r) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        bool no = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!numCt[matrix[i][j]]) {
                    cout << "NO" << endl;
                    no = true;
                    break;
                } else numCt[matrix[i][j]]--;
            }
        }

        if (!no) cout << "YES" << endl;

    }
    return 0;
}