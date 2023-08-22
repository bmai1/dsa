class Solution {
    bool tr(TreeNode* root) {
        if (!root) return false; 
        if (root->val == 2) return tr(root->left) || tr(root->right);
        else if (root->val == 3) return tr(root->left) && tr(root->right);
        return root->val; 
    }
public:
    bool evaluateTree(TreeNode* root) {
        return tr(root);
    }
};