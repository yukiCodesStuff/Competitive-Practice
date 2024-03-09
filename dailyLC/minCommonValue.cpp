#include <vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        while (p1 < nums1.size() || p2 < nums2.size()) {
            if (p1 >= nums1.size() || p2 >= nums2.size()) break;
            
            if (nums1[p1] == nums2[p2]) return nums1[p1];
            else if (p1 == nums1.size() - 1 || nums1[p1] > nums2[p2]) ++p2;
            else if (p2 == nums2.size() - 1 || nums2[p2] > nums1[p1]) ++p1;
        }

        return -1;
    }
};