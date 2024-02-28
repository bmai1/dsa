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
    int d = 0;
    int res;
    void dfs(TreeNode* root, int c) {
        if (!root) return;
        if (c > d) {
            d = c;
            res = root->val;
        }
        dfs(root->left, c + 1);
        dfs(root->right, c + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        res = root->val;
        dfs(root, 0);
        return res;
    }
};