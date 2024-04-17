#include <vector>
#include <string>
#include <algorithm>

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
    vector<string> words;

    void dfs(TreeNode* root, vector<char> word) {
        word.push_back(root->val + 'a');
        if (root->left) dfs(root->left, word);
        if (root->right) dfs(root->right, word);
        else if (!root->left && !root->right) {
            string str(word.begin(), word.end());
            reverse(str.begin(), str.end());
            words.push_back(str);
            return;
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, {});
        sort(words.begin(), words.end());
        return words[0];
    }
};