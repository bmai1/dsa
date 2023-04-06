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
    TreeNode* helper(vector<int> &nums, int start, int end) {
        if (end <= start) { return nullptr; }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        // lower numbers on left, higher on right
        root->left = helper(nums, start, mid);
        root->right = helper(nums, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};
