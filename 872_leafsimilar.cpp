class Solution {
private:
    void dfs(TreeNode* root, vector<int>& leaves) {
        if (!root) { return; }
        if (!root->left && !root->right) { leaves.push_back(root->val); }
        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        dfs(root1, l1);
        dfs(root2, l2);
        return l1 == l2; 
    }
};
