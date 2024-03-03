#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int t; cin >> t; // test cases
    while (t--) {
        int n, l, r; cin >> n >> l >> r;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());
        if (n == 1) {
            cout << (nums[0] >= l && nums[0] <= r) << endl;
            continue;
        } else if (nums[n - 2] + nums[n - 1] < l || nums[0] + nums[1] > r) {
            // cout << (nums[n - 2] + nums[n - 1] < l) << " " << (nums[0] + nums[1] > r) << endl;
            cout << 0 << endl;
            continue;
        }

        int total = 0;
        for (int i = 0; i < n / 2 + 1; ++i) {
            int currNum = nums[i], left = 0, right = n - 1;
            int leftCalc = 0, rightCalc = n - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (
                    currNum + nums[mid] >= l &&
                    currNum + nums[mid - 1] <= l
                ) {
                    leftCalc = mid;
                    break;
                } else if (
                    currNum + nums[mid] < l &&
                    currNum + nums[mid - 1] < l
                ) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            left = 0; right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (
                    currNum + nums[mid] >= r &&
                    currNum + nums[mid - 1] <= r
                ) {
                    rightCalc = mid - 1;
                    break;
                } else if (
                    currNum + nums[mid] < r &&
                    currNum + nums[mid - 1] < r
                ) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            cout << leftCalc << " " << rightCalc << endl;
            total += rightCalc - leftCalc + 1;
        }
        cout << total << endl;
    }

    return 0;
}