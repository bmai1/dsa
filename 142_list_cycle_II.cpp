class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) { return nullptr; }
        // Floyd's Cycle Detection Algorithm
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *ans = head;
        while (fast && fast->next) {
            // reached end
            fast = fast->next->next;
            slow = slow->next;
            // found cycle
            if (slow == fast) { 
                // get to cycle location
                while (slow != ans) {
                    slow = slow->next;
                    ans = ans->next;
                }
                return ans;
            }
        }
        return nullptr;
    }
};
