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

    cout << sub.size() << endl;
    return 0;
}