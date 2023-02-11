class Solution {
private:
    int ans = 0;
    int sum, n;
    int subtree(TreeNode* root) {
        if (!root) { return -1; }
        if (root->right) { 
            sum += root->right->val;
            ++n; 
        }
        if (root->left) { 
            sum += root->left->val;
            ++n; 
        }
        subtree(root->left);
        subtree(root->right);
        return sum;
    }
    
    void helper(TreeNode* root) {
        if (!root) { return; }
        n = 1; // including root
        sum = root->val;
        if (root->val == subtree(root) / n) { ++ans; }
        helper(root->left);
        helper(root->right);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if (!root->right && !root->left) { return 1; }
        helper(root);
        return ans;
    }
};
