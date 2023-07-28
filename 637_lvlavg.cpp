class Solution {
private:
    vector<vector<int>> nodes;
    void t(TreeNode* root, int d) {
        if (!root) return;
        if (d + 1 > nodes.size()) nodes.push_back({root->val}); 
        else nodes[d].push_back(root->val);
        t(root->left, d + 1);
        t(root->right, d + 1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        t(root, 0);
        for (auto level : nodes) {
            double sum = accumulate(level.begin(), level.end(), 0.0);
            avg.push_back(sum / level.size());
        }
        return avg;
    }
};