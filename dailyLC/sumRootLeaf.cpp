#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> nums;
    void getNumFromRoot(TreeNode* root, int num) {
        if (!root) return;
        if (!root->left && !root->right) {
            int currDigit =  root->val;
            nums.push_back(num + currDigit);
            return;
        }

        int currDigit = root->val;
        int newNum = (num + currDigit) * 10;
        getNumFromRoot(root->left, newNum);
        getNumFromRoot(root->right, newNum);
    }

    int sumNumbers(TreeNode* root) {
        getNumFromRoot(root, 0);
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        return sum;
    }
};