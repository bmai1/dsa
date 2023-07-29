class Solution {
private:
    vector<int> nodes;
    void t(TreeNode* root) {
        if (!root) return;
        nodes.push_back(root->val);
        t(root->left);
        t(root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        t(root);
        set<int> s(nodes.begin(), nodes.end());
        if (s.size() <= 1) return -1;
        return *next(s.begin());
    }
};