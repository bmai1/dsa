class Solution {
private: 
    int ans = 0; 
    void dfs(TreeNode *root, int lastValue) {
        if (!root) return; 
        if (root->val >= lastValue) {
            ++ans; 
            dfs(root->left, root->val);  
            dfs(root->right, root->val);  
        }
        else {
            dfs(root->left, lastValue);
            dfs(root->right, lastValue);
        }
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans; 
    }
};
