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
    ListNode* partition(ListNode* head, int x) {
        ListNode* under = new ListNode();
        ListNode* over = new ListNode();
        ListNode* u = under;
        ListNode* o = over;
        ListNode* curr = head;
   
        while (curr) {

            // if (curr->val < x) {
            //     u->next = new ListNode(curr->val);
            //     u = u->next;
            // }
            // else {
            //     o->next = new ListNode(curr->val);
            //     o = o->next;
            // }

            ListNode* &tmp = curr->val < x ? u : o;
            tmp = tmp->next = new ListNode(curr->val);
            
            curr = curr->next;
        }
        u->next = over->next;
        return under->next;
    }
};