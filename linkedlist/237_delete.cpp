class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;

        node->val = node->next->val;
        node->next = node->next->next;

        while (node->next) {
            node->val = node->next->val;
            if (!node->next->next) node->next = nullptr;
            else node = node->next;
        }
    }
};
