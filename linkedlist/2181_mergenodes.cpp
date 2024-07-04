/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        int sum = 0;
        while (head) {
            if (head->val == 0) {
                curr->next = new ListNode(sum);
                curr = curr->next;
                sum = 0;
            }
            else sum += head->val;
            head = head->next;
        }
        return res->next;
    }
};