class Solution {

private:
    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        if (!l1) { return l2; }
        else if (!l2) { return l1; }
        if (l1->val <= l2->val) {
            l1->next = mergeTwo(l1->next, l2); 
            return l1;
        }
        else {
            l2->next = mergeTwo(l1, l2->next);
            return l2;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) { return {}; }
        if (lists.size() == 1) { return lists[0]; }
        while (lists.size() > 1) {  
            // check last merge
            if (lists.size() == 2) {
                return mergeTwo(lists[0], lists[1]);
            }  
            // merge first two lists
            lists[0] = mergeTwo(lists[0], lists[1]);
            // erase second list
            lists.erase(lists.begin() + 1);
        }
        return {};
    }
};
