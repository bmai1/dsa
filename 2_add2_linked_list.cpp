class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        // initializing linked list value using constructor() instead of Node ptr
        ListNode head(0);
        ListNode *n = &head;
        while (c|| l1 || l2) {
            // if l1, c += l1->val else c+= 0 
            c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            // c % 10 returns last digit of value for when it goes over a digit, since Node.val <= 9
            n->next = new ListNode(c % 10);
            n = n->next;
            c /= 10;
            // iterating through linked lists
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        // not a pointer, so dot notation
        return head.next;
    }
};
