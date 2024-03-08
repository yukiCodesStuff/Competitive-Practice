#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxCount = 0;
        for (int num : nums) {
            if (count.find(num) == count.end()) {
                count[num] = 1;
            } else {
                count[num]++;
            }

            maxCount = max(maxCount, count[num]);
        }

        int res = 0;
        for (auto it : count) {
            if (it.second == maxCount) {
                res += it.second;
            }
        }

        return res;
    }
};