class Solution {
private:
    vector<int> ans;
    string path;
    void findPath(TreeNode* root, TreeNode* target, string p) {
        if (!root) return; 
        if (root == target) { path = p; return; }
        findPath(root->left, target, p + 'l');
        findPath(root->right, target, p + 'r');
    }
    void search(TreeNode* root, TreeNode* target, string p, int k) {
        if (!root) return;
        int d = path.size(); // init as distance from root to target node
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == path[i]) --d; // on path to target, so distance decreases
            else {
                d += p.size() - i; // path diverges, so add remaining nodes to distance
                break;
            }
        }
        if (d == k) ans.push_back(root->val); 
        search(root->left, target, p + 'l', k);
        search(root->right, target, p + 'r', k);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findPath(root, target, ""); // find target node and record path
        search(root, target, "", k); // search for nodes with distance k from target
        return ans;
    }
};
