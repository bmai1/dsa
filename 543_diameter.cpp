class Solution {
    int helper(TreeNode* root, int &d) {
        if (!root) { return 0; }
        int left = helper(root->left, d);
        int right = helper(root->right, d);
        d = max(d, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        helper(root, d);
        return d;
    }
};
