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
class BSTIterator {
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode* root) {
        push_all(root);
    }
    bool hasNext() {
        return !stk.empty();
    }
    int next() {
        TreeNode* tmp = stk.top();
        stk.pop();
        push_all(tmp->right);
        return tmp->val;
    }
private:
    void push_all(TreeNode* node) {
        for (; node != NULL; stk.push(node), node = node->left);
    }    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
