struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:

    int lowestLeft = 0;
    int ans = 0;

    void dfs(TreeNode* root, int level) {
        if (!root) return;
        dfs(root->left, level + 1);
        // cout << root->val << " " << level << endl;
        if (lowestLeft < level) {
            lowestLeft = level;
            ans = root->val;
        }
        dfs(root->right, level + 1);
        // cout << root->val << " " << level << endl;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        else dfs(root, 0);
        return ans;
    }
};