#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int k, q; cin >> k >> q;
        vector<int> ks(k);
        vector<int> qs(q);
        for (int i = 0; i < k; ++i) {
            cin >> ks[i];
        }
        for (int i = 0; i < q; ++i) {
            // cin >> qs[i];
            int currQ; cin >> currQ;
            cout << min(currQ, ks[0] - 1) << " ";
        }
        cout << endl;
    }
    return 0;
}