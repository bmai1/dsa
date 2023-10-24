class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
  
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            int m = INT_MIN;
            for (int i = 0; i < n; ++i) {
                auto node = q.front(); q.pop();
                m = max(m, node->val);
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(m);
        }
        return ans;
    }
};