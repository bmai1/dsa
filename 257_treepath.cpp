/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<string> ans;
    void helper(TreeNode* root, string p) {
        if (!root) return;
        if (!root->left && !root->right) { ans.push_back(p); return; }
        if (root->left) { helper(root->left, p + "->" + to_string(root->left->val)); }
        if (root->right) { helper(root->right, p + "->" + to_string(root->right->val)); }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        helper(root, to_string(root->val));
        return ans;
    }
};
