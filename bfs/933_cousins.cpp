class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        int size;
        bool fx, fy;
        while (!q.empty()) {
            size = q.size();
            fx = false, fy = false;
            for (int i = 0; i < size; ++i) {
                auto curr = q.front(); q.pop();
                if (curr->val == x) fx = true;
                if (curr->val == y) fy = true;
                // check same parent node
                if (curr->left && curr->right) {
                    if (curr->left->val == x && curr->right->val == y) return false;
                    if (curr->left->val == y && curr->right->val == x) return false;
                }
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (fx && fy) return true;
        }
        return false;
    }
};