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
    vector<int> sums;
    void dfs(TreeNode* root, int lvl) {
        if (!root) return;
        // weird trick to add levels without messing up recursion
        sums.resize(max((int) sums.size(), lvl));
        sums[lvl - 1] += root->val;

        dfs(root->left, lvl + 1);
        dfs(root->right, lvl + 1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);

        int min_lvl = 0, max_sum = INT_MIN;
        for (int x = 0; x < sums.size(); ++x) {
            if (sums[x] > max_sum) {
                max_sum = sums[x];
                min_lvl = x + 1;
            }
        }
        return min_lvl;
    }
};