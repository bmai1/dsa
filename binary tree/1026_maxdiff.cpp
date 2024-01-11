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
    int m(TreeNode* curr, int mn, int mx) {
        if (!curr) return mx - mn;

        mn = min(mn, curr->val);
        mx = max(mx, curr->val);

        int l = m(curr->left, mn, mx);
        int r = m(curr->right, mn, mx);

        return max(l, r);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return m(root, root->val, root->val);
    }
};