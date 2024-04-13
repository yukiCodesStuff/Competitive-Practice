#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long n, c, d; cin >> n >> c >> d;
        vector<long long> a(n * n);
        for (int i = 0; i < n * n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());   
        vector<long long> b(n * n);
        b[0] = a[0];
        for (int i = n; i < n * n; i += n) {
            b[i] = b[i - n] + c;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                b[(i * n) + j] = b[(i * n) + j - 1] + d;
                // cout << j << " " << (i * n) + j - 1 << endl;
            }
        }
        sort(b.begin(), b.end());

        // for (auto i : a) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (auto i : b) {
        //     cout << i << " ";
        // }
        // cout << endl;

        if (a == b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}