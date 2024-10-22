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
vector<long long> sums;
void traverse(TreeNode* root, int level) {
    if (!root) return;

    sums.resize(max((int) sums.size(), level));
    // if (sums.size() == level - 1) sums.push_back(0);
    sums[level - 1] += root->val;

    traverse(root->left, level + 1);
    traverse(root->right, level + 1);
}
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        traverse(root, 1);
        if (k > sums.size()) return -1;
        // sort from back for k-th largest
        sort(sums.rbegin(), sums.rend());
        return sums[k - 1];
    }
};