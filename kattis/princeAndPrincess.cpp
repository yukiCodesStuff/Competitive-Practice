#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

int LIS(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    vector<int> sub;
    sub.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > sub[sub.size() - 1]) {
            sub.push_back(nums[i]);
        } else {
            int subIndex = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
            sub[subIndex] = nums[i];
        }
    }

    return sub.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int c = 0; c < t; ++c) {
        int n, p, q; cin >> n >> p >> q;
        p++; q++;
        vector<int> a(p);
        vector<int> b(q);
        unordered_map<int, int> bMap;
        for (int i = 0; i < p; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < q; ++i) {
            cin >> b[i];
            bMap[b[i]] = i;
        }

        vector<int> aPrime;
        for (int i = 0; i < p; ++i) {
            if (bMap.find(a[i]) != bMap.end()) {
                aPrime.push_back(bMap[a[i]]);
            }
        }

        cout << "Case " << c + 1 << ": " << LIS(aPrime) << endl;
    }

    return 0;
}

// Remember that this approach only works if all elements are UNIQUE
