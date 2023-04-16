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
    void t(TreeNode* root, vector<int> &v) {
        // inord
        if (root == nullptr) { return; }
        t(root->left, v);
        v.push_back(root->val);
        t(root->right, v);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;
        t(root, values);
        // sort(values.begin(), values.end());
        return values[k - 1]; 
    }
};
