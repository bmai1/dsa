class Node {
public:
    unordered_map<char, Node*> children;
    bool end;
    Node () {
        end = false;
    }
};

class Trie {
private:
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */