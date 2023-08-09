class Solution {
private:
    int depth(TreeNode* root, bool dir, int d) {
        if (!root) return d;
        if (dir) return depth(root->left, dir, d + 1);
        return depth(root->right, dir, d + 1);
    }
public:
    int countNodes(TreeNode* root) {
        int left =  depth(root, true, 0);
        int right = depth(root, false, 0);
        if (left == right) return pow(2, left) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};