#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int markingIndex = abs(nums[i]) - 1;
            if (nums[markingIndex] < 0) res.push_back(abs(nums[i]));
            else nums[markingIndex] = -nums[markingIndex];
        }

        return res;
    }
};