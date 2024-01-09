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
class FindElements {
public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        root->val = 0;
        recover(root);
    }

    void recover(TreeNode* root) {
        if (!root) return;
        int x = root->val;
        s.insert(x);
        if (root->left) {
            root->left->val = 2 * x + 1;
        }
        if (root->right) {
            root->right->val = 2 * x + 2;
        }
        recover(root->left);
        recover(root->right);
    }

    bool find(int target) {
       return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */