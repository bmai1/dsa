class Solution {
private: 
    TreeNode* ans = nullptr; 
    void helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return; 
        if (has(root, p) && has(root, q)) { ans = root; }
        helper(root->left, p, q);
        helper(root->right, p, q);
    }
    bool has(TreeNode* start, TreeNode* target) {
        if (!start) return false; 
        if (start == target) { return true; }
        return has(start->right, target) || has(start->left, target);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans; 
    }
};
