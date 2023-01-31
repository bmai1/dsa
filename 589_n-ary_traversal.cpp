class Solution {
private:
    void preord(Node* root, vector<int>& ans) {
        if (root == nullptr) { return; }
        ans.push_back(root->val);
        // Node* 
        for (auto n : root->children) {
            preord(n, ans);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preord(root, ans);
        return ans; 
    }
};
