class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // iterative
        if (head == nullptr) return head;
        ListNode* next;
        ListNode* prev = nullptr;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;

        // Recursion (ListNode* prev = nullptr parameter)
        // if (!head) return prev;
        // ListNode* next = head->next;
        // head->next = prev;
        // return reverseList(next, head);

        // Recursion one-liner (two parameters)
        // return head ? reverseList(head->next, (head->next = prev, head)) : prev; 
    }
};
