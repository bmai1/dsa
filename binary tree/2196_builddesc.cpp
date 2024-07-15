/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    unordered_map<int, pair<int, int>> v;
    void build(TreeNode* root) {
        if (!root) return;

        int left = v[root->val].first;
        int right = v[root->val].second;

        if (left) root->left = new TreeNode(left);
        if (right) root->right = new TreeNode(right);
           
        build(root->left);
        build(root->right);
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> p;
        for (auto& d : descriptions) {
            if (d[2]) v[d[0]].first = d[1];
            else v[d[0]].second = d[1];
            p.insert(d[1]);
        }
        for (auto& d : descriptions) {
            if (!p.contains(d[0])) {
                TreeNode* root = new TreeNode(d[0]);
                build(root);
                return root;
            }
        }
        return nullptr;
    }
};