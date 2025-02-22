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
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int, TreeNode*> level;
        int cnt = 0;
        for (int i = 0; i < traversal.size(); ++i) {
            if (traversal[i] != '-') {
                string num = "";
                int j = i;
                while (j < traversal.size() && traversal[j] != '-') {
                    num += traversal[j];
                    ++j;
                }
                TreeNode* next = new TreeNode(stoi(num));
                level[cnt] = next;
                if (cnt > 0) {
                    TreeNode* parent = level[cnt - 1];
                    if (parent->left == nullptr) parent->left = next;
                    else parent->right = next;
                    cnt = 0;
                }
                i = j - 1;
            }
            else ++cnt;  
        }
        return level[0];
    }
};
