class Solution {
private:
    int ans = 0;
    void t(TreeNode* root, string path) {
        if (!root->left && !root->right) ans += stoi(path, nullptr, 2); 
        if (root->left)  t(root->left , path + to_string(root->left ->val));
        if (root->right) t(root->right, path + to_string(root->right->val));
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        t(root, to_string(root->val));
        return ans; 
    }
};