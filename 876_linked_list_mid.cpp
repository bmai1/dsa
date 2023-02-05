
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return head;
        ListNode* temp = head;
        int n, length = 0;
        // find length of linked list
        while (temp) {
            length++;
            temp = temp->next;
        }
        // even length = second middle node
        if (length % 2 == 0) n = (length / 2) + 1;
        // odd length = middle node
        else n = (length + 1) / 2;
        // iterate to node
        for (int i = 1; i < n; ++i) {
            head = head->next;
        }
        return head;
    }
};
