class Solution {
    int sum = 0;
    int s(TreeNode* root) {
        if (!root) return 0;
        return root->val + s(root->right) + s(root->left);
    }
    void h(TreeNode* root) {
        if (!root) return;
        sum += abs(s(root->right) - s(root->left));
        h(root->left);
        h(root->right);
    }
public:
    int findTilt(TreeNode* root) {
        h(root);
        return sum;
    }
};