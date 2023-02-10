class Solution {
private: 
    // running sum
    int sum = 0; 
    void inord(TreeNode* root) {
        if (root == nullptr) { return; }
        inord(root->right);
        sum += root->val;
        root->val = sum;
        inord(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        inord(root);
        return root;
    }
};
