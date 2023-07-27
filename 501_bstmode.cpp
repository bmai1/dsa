class Solution {
private:
    int max_freq = 0;
    vector<int> vals;
    unordered_map<int, int> freq;
    void t(TreeNode* root) {
        if (!root) return;
        vals.push_back(root->val);
        freq[root->val]++;
        max_freq = max(max_freq, freq[root->val]);
        t(root->left);
        t(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        t(root);
        vector<int> ans;
        for (auto it : freq) { 
            if (it.second == max_freq) ans.push_back(it.first);
        }
        return ans;
    }
};