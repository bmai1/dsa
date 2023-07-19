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
private:
    int md = 0;
    void tr(Node* root, int depth) {
        if (!root) return;
        md = max(md, depth);
        for (auto child : root->children) {
            tr(child, depth + 1);
        }
    }
public:
    int maxDepth(Node* root) {
        tr(root, 1);
        return md;
    }
};