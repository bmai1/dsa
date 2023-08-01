/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> ans;
    void tr(Node* root) {
        if (!root) return;
        for (auto child : root->children) tr(child); 
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        tr(root);
        return ans;
    }
};