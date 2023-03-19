class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) { return head; }
        if (left == right) { return head; }

        // locate start with dummy
        ListNode *dummy = new ListNode(0), *prev = dummy, *curr;
        dummy->next = head;
        for (int i = 0; i < left - 1; i++) {
           prev = prev->next;
        }
        curr = prev->next;

        // reverse
        for (int i = 0; i < right - left; i++) {
           ListNode* temp = prev->next;
           prev->next = curr->next;
           curr-> next = curr->next->next;
           prev->next->next = temp;
        }
        return dummy -> next;
    }
};
