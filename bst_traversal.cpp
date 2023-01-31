class Solution {
private:
    void tr(TreeNode* root, vector<int>& ans) {
        // Input: root = [1,null,2,3], 
        if (root == nullptr) { return; }
        ans.push_back(root->val); // preorder, Output: [1,2,3]
        tr(root->left, ans);
        // ans.push_back(root->val); // inorder, Output: [1,3,2]
        tr(root->right, ans);
        // ans.push_back(root->val); // postorder, Output: [3,2,1]
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        tr(root, ans);
        return ans;
    }
};
