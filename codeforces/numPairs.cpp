#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t; cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());

        int total = 0;
        for (int i = 0; i < n / 2 + 1; ++i) {
            cout << "Num: " << nums[i] << " ";
            int left = lower_bound(nums.begin(), nums.end(), l - nums[i]) - nums.begin();
            int right = lower_bound(nums.begin(), nums.end(), r - nums[i]) - nums.begin();
            cout << left << " " << right << endl;
            total += right - left + 1;
        }
        cout << total << endl;
    }

    return 0;
}