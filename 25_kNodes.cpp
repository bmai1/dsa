class Solution {
private: 
    vector<ListNode*> nodes; 
    void reverseK(ListNode* head, int k) {
        if (!head) return;
        ListNode* next;
        ListNode* prev = nullptr;
        for (int i = 0; i < k; ++i) {
            next = head->next;
            head->next = prev; 
            prev = head;
            head = next;
        }
        // ListNode* t = prev;
        // while (t) {
        //     cout << t->val;
        //     t = t->next;
        // }
        // cout << endl;
        nodes.push_back(prev);
    }
    int reversals(ListNode* head, int k) {
        ListNode* tmp = head;
        int size = 0;
        while (tmp) {
            ++size;
            tmp = tmp->next;
        }
        return (size - (size % k)) / k; 
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) { return head; }
        int r = reversals(head, k);
        ListNode* n = nullptr; // placeholder for next location to reverse
        for (int i = 0; i < r; ++i) {
            n = head;
            for (int j = 0; j < k; ++j) { n = n->next; }
            reverseK(head, k);
            head = n;
        }

        ListNode* connector = nodes[0];
        for (int i = 0; i < nodes.size() - 1; ++i) {
            for (int j = 0; j < k - 1; ++j) {
                connector = connector->next;
            }
            connector->next = nodes[i + 1];
            connector = connector->next;
        }

        // connect leftover nodes
        if (n) {
            while (connector->next) { connector = connector->next; }
            connector->next = n;
        }
        return nodes[0];
    }
};
