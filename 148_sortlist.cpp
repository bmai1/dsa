class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) { return head; }
        ListNode* tmp = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tmp->next = nullptr;
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(slow);
        return mergeTwoLists(list1, list2);
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // base cases with empty lists
        if (list1 == nullptr) { return list2; }
        else if (list2 == nullptr) { return list1; }
        // if list2->val greater/equal, it goes ahead
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
