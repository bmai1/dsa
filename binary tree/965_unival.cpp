class Solution {
private:
    int root_val = -1;
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        if (root_val < 0) root_val = root->val;
        return root->val == root_val && isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};