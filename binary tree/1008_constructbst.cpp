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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk; 
        stk.push(root);
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* curr = new TreeNode(preorder[i]);
            if (curr->val < stk.top()->val) {
                stk.top()->left = curr;
            }
            else {
                TreeNode* prev;
                while (!stk.empty() && stk.top()->val < curr->val) {
                    prev = stk.top(); stk.pop();
                }
                prev->right = curr;
            }
            stk.push(curr);
        }
        return root;
    }
};