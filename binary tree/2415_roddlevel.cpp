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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> level;
            for (int i = 0; i < n; ++i) {
                auto node = q.front(); q.pop();
                level.push_back(node);
                if (node->left) q.push(node->left); 
                if (node->right) q.push(node->right);  
            }
            if (l++ % 2) {
                // i < n swaps twice and doesn't change anything
                for (int i = 0; i < n / 2; ++i) {
                    swap(level[i]->val, level[n - i - 1]->val);
                }
            }
        }
        return root;
    }
};