class Solution {
    int sum = 0;
    int h(TreeNode* root) {
        if (!root) return 0;
        int left = h(root->left), right = h(root->right);
        sum += abs(left - right);
        return root->val + left + right;
    }
public:
    int findTilt(TreeNode* root) {
        h(root);
        return sum;
    }
};