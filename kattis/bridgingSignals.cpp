#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int p; cin >> p;
    vector<int> nums(p);
    for (int i = 0; i < p; ++i) {
        cin >> nums[i];
    }
    if (nums.empty()) {
        return 0;
    }

    int n = nums.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *std::max_element(dp.begin(), dp.end()) << endl;
}