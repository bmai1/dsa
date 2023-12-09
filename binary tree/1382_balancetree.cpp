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
    vector<int> nodes;
    void t(TreeNode* root) {
        if (!root) return;
        nodes.push_back(root->val);
        t(root->left);
        t(root->right);
    }
    TreeNode* buildTree(int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildTree(start, mid - 1);
        root->right = buildTree(mid + 1, end);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        t(root);
        sort(nodes.begin(), nodes.end());
        return buildTree(0, nodes.size() - 1);
    }
};