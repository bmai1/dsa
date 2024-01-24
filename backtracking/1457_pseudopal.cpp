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
    int res = 0;
    void tr(TreeNode* root, unordered_map<int, int>& m) {
        if (!root) return;

        m[root->val]++;
        
        if (!root->left && !root->right) {
            int odd = 0;
            for (auto it : m) odd += it.second % 2 != 0;
            res += odd <= 1;
        }
        tr(root->left, m);
        tr(root->right, m);

        // pogger backtrack
        m[root->val]--;

        if (m[root->val] == 0) {
            m.erase(root->val);
        }
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> m;
        tr(root, m);
        return res;
    }
};