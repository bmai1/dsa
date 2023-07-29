class Solution {
private:
    set<int> s;
    void t(TreeNode* root) {
        if (!root) return;
        s.insert(root->val);
        t(root->left);
        t(root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        t(root);
        if (s.size() <= 1) return -1;
        return *next(s.begin());
    }
};